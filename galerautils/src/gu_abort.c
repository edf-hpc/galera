// Copyright (C) 2011-2013 Codership Oy <info@codership.com>

/**
 * @file Clean abort function
 *
 * $Id: gu_abort.c 3515 2014-03-26 16:10:56Z yan $
 */


#include "gu_abort.h"

#include "gu_system.h"
#include "gu_log.h"
#include <sys/resource.h> /* for setrlimit() */
#include <signal.h>       /* for signal()    */
#include <stdlib.h>       /* for abort()     */

void
gu_abort (void)
{
    /* avoid coredump */
    struct rlimit core_limits = { 0, 0 };
    setrlimit (RLIMIT_CORE, &core_limits);

    /* restore default SIGABRT handler */
    signal (SIGABRT, SIG_DFL);

#if defined(GU_SYS_PROGRAM_NAME)
    gu_info ("%s: Terminated.", GU_SYS_PROGRAM_NAME);
#else
    gu_info ("Program terminated.");
#endif

    abort();
}

