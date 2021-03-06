/*
 * Copyright (c) 1982, 1986, 1989, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)signal.h	8.2 (Berkeley) 1/21/94
 * $Id: signal.h,v 1.4 2012/08/26 02:54:59 gdr Exp $
 */

#ifndef	_SYS_SIGNAL_H_
#define	_SYS_SIGNAL_H_

#define NSIG	32		/* counting 0; could be 33 (mask is 1-32) */

#if !defined(_ANSI_SOURCE) && !defined(_MACHINE_SIGNAL_H_)
#include <machine/signal.h>	/* sigcontext; codes for SIGILL, SIGFPE */
#endif

#ifdef KERNEL
/*
 * The kernel doesn't currently use these macros, but if they ever get 
 * into the kernel sources, they'd really cause havoc; the numbers differ
 * between GNO and ORCA/C
 */
#undef SIGABRT
#undef SIGFPE
#undef SIGILL
#undef SIGINT
#undef SIGSEGV
#undef SIGTERM
#endif

#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught) */
#ifndef _POSIX_SOURCE
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#endif
#define	SIGABRT	6	/* abort() */
#ifndef _POSIX_SOURCE
#define	SIGIOT	SIGABRT	/* compatibility */
#define	SIGEMT	7	/* EMT instruction */
#endif
#define	SIGFPE	8	/* floating point exception */
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#ifndef _POSIX_SOURCE
#define	SIGBUS	10	/* bus error */
#endif
#define	SIGSEGV	11	/* segmentation violation */
#ifndef _POSIX_SOURCE
#define	SIGSYS	12	/* bad argument to system call */
#endif
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#define	SIGALRM	14	/* alarm clock */
#define	SIGTERM	15	/* software termination signal from kill */
#ifndef _POSIX_SOURCE
#define	SIGURG	16	/* urgent condition on IO channel */
#endif
#define	SIGSTOP	17	/* sendable stop signal not from tty */
#define	SIGTSTP	18	/* stop signal from tty */
#define	SIGCONT	19	/* continue a stopped process */
#define	SIGCHLD	20	/* to parent on child stop or exit */
#ifndef _POSIX_SOURCE
#define SIGCLD	SIGCHLD	/* System V name for SIGCHLD */
#endif
#define	SIGTTIN	21	/* to readers pgrp upon background tty read */
#define	SIGTTOU	22	/* like TTIN for output if (tp->t_local&LTOSTOP) */
#ifndef _POSIX_SOURCE
#define	SIGIO	23	/* input/output possible signal */
#define	SIGPOLL	SIGIO	/* System V name for SIGIO */
#define	SIGXCPU	24	/* exceeded CPU time limit */
#define	SIGXFSZ	25	/* exceeded file size limit */
#define	SIGVTALRM 26	/* virtual time alarm */
#define	SIGPROF	27	/* profiling time alarm */
#define SIGWINCH 28	/* window size changes */
#define SIGINFO	29	/* information request */
#endif
#define SIGUSR1 30	/* user defined signal 1 */
#define SIGUSR2 31	/* user defined signal 2 */

typedef void (*__SIG_FUNC__) __P((int, int));
#define SIG_DFL ((__SIG_FUNC__) (0))
#define SIG_IGN ((__SIG_FUNC__) (1))
#define SIG_ERR ((__SIG_FUNC__) (-1))

#ifndef _ANSI_SOURCE
typedef unsigned long sigset_t;		/* non-BSD type */

/*
 * Signal vector "template" used in sigaction call.
 */
struct	sigaction {
#ifdef __GNO__
	void	(*sa_handler)(int, void (*)(void));	/* signal handler */
#else
#error __GNO__ is not defined
	void	(*sa_handler)();	/* signal handler */
#endif
	sigset_t sa_mask;		/* signal mask to apply */
	int	sa_flags;		/* see signal options below */
};
#ifndef _POSIX_SOURCE
#define SA_ONSTACK	0x0001	/* take signal on signal stack */
#define SA_RESTART	0x0002	/* restart system on signal return */
#define	SA_DISABLE	0x0004	/* disable taking signals on alternate stack */
#ifdef COMPAT_SUNOS
#define	SA_USERTRAMP	0x0100	/* do not bounce off kernel's sigtramp */
#endif
#endif
#define SA_NOCLDSTOP	0x0008	/* do not generate SIGCHLD on child stop */

/*
 * Flags for sigprocmask:	(non-BSD:  off by one)
 */
#define	SIG_BLOCK	0	/* block specified signal set */
#define	SIG_UNBLOCK	1	/* unblock specified signal set */
#define	SIG_SETMASK	2	/* set specified signal set */

#ifndef _POSIX_SOURCE

#ifndef _SYS_CDEFS_H_
#include <sys/cdefs.h>
#endif

#if 1	/* GNO */
typedef	void (*sig_t) __P((int, int));	/* type of signal function */
#else	/* BSD */
typedef	void (*sig_t) __P((int));	/* type of signal function */
#endif

/*
 * Structure used in sigaltstack call.
 */
struct	sigaltstack {
	char	*ss_sp;			/* signal stack base */
	int	ss_size;		/* signal stack length */
	int	ss_flags;		/* SA_DISABLE and/or SA_ONSTACK */
};
#define	MINSIGSTKSZ	8192			/* minimum allowable stack */
#define	SIGSTKSZ	(MINSIGSTKSZ + 32768)	/* recommended stack size */

/*
 * 4.3 compatibility:
 * Signal vector "template" used in sigvec call.
 */
struct	sigvec {
#ifdef __GNO__
	sig_t	sv_handler;		/* signal handler */
#else
	void	(*sv_handler)();	/* signal handler */
#endif
	int	sv_mask;		/* signal mask to apply */
	int	sv_flags;		/* see signal options below */
};

#define SV_ONSTACK	SA_ONSTACK
#define SV_INTERRUPT	SA_RESTART	/* same bit, opposite sense */
#define sv_onstack sv_flags	/* isn't compatibility wonderful! */

/*
 * Structure used in sigstack call.
 */
struct	sigstack {
	char	*ss_sp;			/* signal stack pointer */
	int	ss_onstack;		/* current status */
};

/*
 * Macro for converting signal number to a mask suitable for
 * sigblock().
 */
#define sigmask(m)	(1 << ((unsigned long int)((m)-1)))

#define	BADSIG		SIG_ERR

#endif	/* !_POSIX_SOURCE */
#endif	/* !_ANSI_SOURCE */

/*
 * For historical reasons; programs expect signal's return value to be
 * defined by <sys/signal.h>.
 */
__BEGIN_DECLS

#ifndef _POSIX_SOURCE
sig_t	signal __P((int, sig_t));
#endif

/*
 * Old definitions:
 *	BSD:	void	(*signal __P((int, void (*) __P((int))))) __P((int));
 *	GNO:	void  *signal(int sig, void (*func)(int, int));
 */

__END_DECLS
#endif	/* !_SYS_SIGNAL_H_ */
