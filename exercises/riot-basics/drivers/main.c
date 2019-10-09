/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>
#include <string.h>

#include "xtimer.h"
#include "thread.h"

#include "board.h"

#include "hts221.h"
#include "hts221_params.h"

#include "lsm6dsl.h"
#include "lsm6dsl_params.h"

static char stack1[THREAD_STACKSIZE_MAIN];
static char stack2[THREAD_STACKSIZE_MAIN];

static void *thread1_handler(void *arg)
{
    (void) arg;

    return NULL;
}

static void *thread2_handler(void *arg)
{
    (void) arg;

    return NULL;
}


int main(void)
{
    puts("RIOT multi drivers application");

    thread_create(stack1, sizeof(stack1),
                  THREAD_PRIORITY_MAIN - 1,
                  0,
                  thread1_handler,
                  NULL, "thread1");
    
    thread_create(stack2, sizeof(stack2),
                  THREAD_PRIORITY_MAIN - 1,
                  0,
                  thread2_handler,
                  NULL, "thread2");

    return 0;
}
