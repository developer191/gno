/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
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
 *	@(#)string.h	8.1 (Berkeley) 6/2/93
 */

#ifndef _STRING_H_
#define	_STRING_H_

#ifndef _MACHINE_ANSI_H_
#include <machine/ansi.h>
#endif

#if defined(_BSD_SIZE_T_) && !defined(__size_t__)
#define __size_t__ 1
typedef	_BSD_SIZE_T_	size_t;
#undef	_BSD_SIZE_T_
#endif

#ifndef	NULL
#define NULL  (void *) 0L
#endif

#ifndef _SYS_CDEFS_H_
#include <sys/cdefs.h>
#endif

__BEGIN_DECLS
void	*memchr __P((const void *, int, size_t));
int	 memcmp __P((const void *, const void *, size_t));
void	*memcpy __P((void *, const void *, size_t));
void	*memmove __P((void *, const void *, size_t));
void	*memset __P((void *, int, size_t));
char	*strcat __P((char *, const char *));
char	*strchr __P((const char *, int));
int	 strcmp __P((const char *, const char *));
int	 strcoll __P((const char *, const char *));
char	*strcpy __P((char *, const char *));
size_t	 strcspn __P((const char *, const char *));
char	*strerror __P((int));
size_t	 strlen __P((const char *));
char	*strncat __P((char *, const char *, size_t));
int	 strncmp __P((const char *, const char *, size_t));
char	*strncpy __P((char *, const char *, size_t));
char	*strpbrk __P((const char *, const char *));
char	*strrchr __P((const char *, int));
size_t	 strspn __P((const char *, const char *));
char	*strstr __P((const char *, const char *));
char	*strtok __P((char *, const char *));
size_t	 strxfrm __P((char *, const char *, size_t));

/* Nonstandard routines */
#ifndef _ANSI_SOURCE
int	 bcmp __P((const void *, const void *, size_t));
void	 bcopy __P((const void *, void *, size_t));
void	 bzero __P((void *, size_t));
int	 ffs __P((int));
char	*index __P((const char *, int));
void	*memccpy __P((void *, const void *, int, size_t));
char	*rindex __P((const char *, int));
int	 strcasecmp __P((const char *, const char *));
char	*strdup __P((const char *));
void	 strmode __P((int, char *));
int	 strncasecmp __P((const char *, const char *, size_t));
char	*strsep __P((char **, const char *));
void	 swab __P((const void *, void *, size_t));

/* These are specific to Orca and GNO.  Some should probably use "const" */
char 	*c2pstr __P((char *));
char	*p2cstr __P((char *));
int	 strpos __P((char *, char));
char	*strrpbrk __P((char *, char *));
int	 strrpos __P((char *, char));
char 	*strupr __P((char *str));
char	*strlwr __P((char *str));
char	*strset __P((char *str, char ch));
char	*strnset __P((char *str, char ch, unsigned count));
char	*strrev __P((char *str));
char	*strpblnks __P((char *str));
char	*strrpblnks __P((char *str));
char	*strpad __P((char *str, char ch, unsigned count));
char	*strrpad __P((char *str, char ch, unsigned count));
short	 stricmp __P((const char *s1, const char *s2));
short	 strincmp __P((const char *s1, const char *s2, unsigned n));

#endif
__END_DECLS

#endif /* _STRING_H_ */
