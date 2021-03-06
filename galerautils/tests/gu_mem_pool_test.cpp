// Copyright (C) 2013 Codership Oy <info@codership.com>

// $Id: gu_mem_pool_test.cpp 3397 2013-12-08 01:56:58Z alex $

#define TEST_SIZE 1024

#include "gu_mem_pool.hpp"

#include "gu_mem_pool_test.hpp"

START_TEST (unsafe)
{
    gu::MemPoolUnsafe mp(10, 1, "unsafe");

    void* const buf0(mp.acquire());
    fail_if(NULL == buf0);

    void* const buf1(mp.acquire());
    fail_if(NULL == buf1);
    fail_if(buf0 == buf1);

    mp.recycle(buf0);

    void* const buf2(mp.acquire());
    fail_if(NULL == buf2);
    fail_if(buf0 != buf2);

    log_info << mp;

    mp.recycle(buf1);
    mp.recycle(buf2);
}
END_TEST

START_TEST (safe)
{
    gu::MemPoolSafe mp(10, 1, "safe");

    void* const buf0(mp.acquire());
    fail_if(NULL == buf0);

    void* const buf1(mp.acquire());
    fail_if(NULL == buf1);
    fail_if(buf0 == buf1);

    mp.recycle(buf0);

    void* const buf2(mp.acquire());
    fail_if(NULL == buf2);
    fail_if(buf0 != buf2);

    log_info << mp;

    mp.recycle(buf1);
    mp.recycle(buf2);
}
END_TEST

Suite *gu_mem_pool_suite(void)
{
    Suite *s = suite_create("gu::MemPool");
    TCase *tc_mem = tcase_create("gu_mem_pool");

    suite_add_tcase (s, tc_mem);
    tcase_add_test(tc_mem, unsafe);
    tcase_add_test(tc_mem, safe);

    return s;
}

