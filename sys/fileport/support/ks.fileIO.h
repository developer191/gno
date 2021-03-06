
/*
 * Copyright (c) Kopriha Software,  1990-1991
 *       All Rights Reserved
 *
 * ks.fileio.h
 *
 * Description: This include file contains all the generic file
 *              support macros from Kopriha Software.
 *
 *
 * Table of contents:
 *
 *   External Data Structures:
 *
 *  Notes:
 *
 *  History:Oct 13, 1990  Dave  Created this file for basic
 *                              I/O (read/write)
 *
 *          Feb 25, 1991  Dave  Added buffer enhancements/create.
 *
 *          Mar 5, 1991   Dave  Added directory, file, path and
 *                              volume calls
 *
 *          Mar 24, 1991  Dave  Added delete and change aux type
 *
 */

#ifndef _KS_FILEIO_H_
#define _KS_FILEIO_H_

#ifndef _KS_FILEIO_E_
#include "ks.fileio.e"
#endif

#ifndef __GSOS__
#include <gsos.h>
#endif

#ifndef __PRODOS__
#include <ProDOS.h>
#endif

#ifndef __MEMORY__
#include <memory.h>
#endif

#ifndef _KS_MEMORY_
#include "ks.memory.h"
#endif


/*
 * Define all the external data referenced in this module:
 *
 * Note: The routines in this module minimize stack space usage,
 *       which is why all the structures are external...
 */

/* ****************************************************************** *
 *  KSf_Pkts - This is a union of all the GS/OS packets that are      *
 *             used by this module.  Since multitasking isn't         *
 *             supported on a IIGS, we won't worry about needing      *
 *             seperate unions for each task (which is how we will    *
 *             solve this problem when multitasking does become       *
 *             available).                                            *
 *                                                                    *
 * Note: fileinfo is a ProDOS 16 structure - this is because GS/OS    *
 *       does not provide an easy method to determine the amount of   *
 *       space used on a volume.                                      *
 * ****************************************************************** */

#ifdef FILEIO_DATA
#ifdef EXTERNAL
#undef EXTERNAL
#define EXTERNAL
#endif
#endif

#ifndef EXTERNAL
#define EXTERNAL extern
#endif

EXTERNAL union
    {
    CreateRecGS      create;
    OpenRecGS        open;
    IORecGS          IO;
    RefNumRecGS      close;
    SetPositionRecGS position;
    PrefixRecGS      prefix;
    FileRec          fileinfo;
    FileInfoRecGS    delete;
    FileInfoRecGS    fileinfoGSOS;
    ChangePathRecGS  rename;
    } KSf_pkts;


/* ****************************************************************** *
 *  KSf_pkts2 - This is the second unionized set of GS/OS packets.    *
 *              The reason for these packets is that the first packets*
 *              sometimes have option fields that these packets must  *
 *              be used to fill in.                                   *
 *                                                                    *
 *    optionList - this is the File System Translator specific        *
 *                 area returned on the Open call.  We don't do       *
 *                 anything with this data.                           *
 *                                                                    *
 * ****************************************************************** */

EXTERNAL union
    {
    Word          optionList[20];
    } KSf_pkts2;


/* ****************************************************************** *
 *  KSf_FileBufferSize - the specified size of the file buffers       *
 * ****************************************************************** */

EXTERNAL Long    KSf_FileBufferSize;


#ifdef FILEIO_DATA
#undef EXTERNAL
#define EXTERNAL extern
#endif

#endif
