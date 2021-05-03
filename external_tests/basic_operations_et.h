#pragma once
#if !defined(_BASIC_OPERATIONS_ET)
#define _BASIC_OPERATIONS_ET

#include <sse_math_x64_lib.h>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

#include "macros/sse_macros.h"

using namespace sse_basics;

void testBasicInvSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 3.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = inv_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0f / x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed inv SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicInvSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = inv_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0 / x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed inv SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicNegSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = -3.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = neg_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -1.0f * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed neg SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicNegSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = neg_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -1.0 * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed neg SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastMulSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double y = 0.5;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.05;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast multiplication SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastMulSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float y = 0.5f;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.05f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast multiplication SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicMulSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *y = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.05;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10;

    y[0] = 0.05;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 2.0;
    x[16] = 10.3;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed multiplication SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicMulSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *y = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.05f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.0f;

    y[0] = 0.05f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 2.0f;
    y[16] = 10.3f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed multiplication SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastDivSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double y = 0.5;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.05;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastDivSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float y = 0.5;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.05f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSDivSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *y = sse_utility::aligned_alloc<double>(n, align);
    double x = 0.5;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    y[0] = 0.05;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 3.0;
    y[16] = 10;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_br_s_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast swapped division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSDivSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *y = sse_utility::aligned_alloc<float>(n, align);
    float x = 0.5;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    y[0] = 0.05f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 3.0f;
    y[16] = 10.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_br_s_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast swapped division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicDivSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *y = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.05;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10;

    y[0] = 0.05;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 2.0;
    y[16] = 10.3;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicDivSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *y = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.05f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.0f;

    y[0] = 0.05f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 2.0f;
    y[16] = 10.3f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed division SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastAddSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double y = 1.25;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.01;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast addition SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastAddSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float y = 1.25f;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 3.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast addition SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicAddSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *y = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.01;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    y[0] = 0.02;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 3.0;
    y[16] = 3.5;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed addition SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicAddSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *y = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 3.0f;

    y[0] = 0.0f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 3.0f;
    y[16] = 3.12f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed addition SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSubSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double y = 12.3;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSubSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float y = 2.365f;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 103.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_br_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSSubSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *y = sse_utility::aligned_alloc<double>(n, align);
    double x = 12.3;
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    y[0] = 0.0;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 3.0;
    y[16] = 3.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_br_s_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast swapped subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicBroadcastSSubSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *y = sse_utility::aligned_alloc<float>(n, align);
    float x = 2.365f;
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    y[0] = 0.0f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 3.0f;
    y[16] = 103.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_br_s_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed broadcast swapped subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicSubSSEDouble()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    double *x = sse_utility::aligned_alloc<double>(n, align);
    double *y = sse_utility::aligned_alloc<double>(n, align);
    double *res1 = sse_utility::aligned_alloc<double>(n, align);
    double *res2 = sse_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = sse_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 3.0;

    y[0] = 0.0;
    y[1] = pi / 2.0;
    y[2] = pi;
    y[3] = 3.0 * pi / 2.0;
    y[4] = 5.0 * pi / 4.0;
    y[5] = 2.0 * pi;
    y[6] = 4.0 * pi;
    y[7] = 3.0 * pi;
    y[8] = 6.0 * pi / 3.0;
    y[9] = -2.0 * pi;
    y[10] = -pi / 4.0;
    y[11] = 7.0 * pi / 4.0;
    y[12] = 0.5;
    y[13] = pi / 3.0;
    y[14] = 23.5;
    y[15] = 4.0 * pi / 3.0;
    y[16] = 103.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

void testBasicSubSSEFloat()
{
    int const n = 16 + 1;
    std::size_t const align = 16;

    float *x = sse_utility::aligned_alloc<float>(n, align);
    float *y = sse_utility::aligned_alloc<float>(n, align);
    float *res1 = sse_utility::aligned_alloc<float>(n, align);
    float *res2 = sse_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = sse_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 103.0f;

    y[0] = 0.0f;
    y[1] = pi / 2.0f;
    y[2] = pi;
    y[3] = 3.0f * pi / 2.0f;
    y[4] = 5.0f * pi / 4.0f;
    y[5] = 2.0f * pi;
    y[6] = 4.0f * pi;
    y[7] = 3.0f * pi;
    y[8] = 6.0f * pi / 3.0f;
    y[9] = -2.0f * pi;
    y[10] = -pi / 4.0f;
    y[11] = 7.0f * pi / 4.0f;
    y[12] = 0.5f;
    y[13] = pi / 3.0f;
    y[14] = 23.5f;
    y[15] = 4.0f * pi / 3.0f;
    y[16] = 3.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_sse(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed subtraction SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    sse_utility::aligned_free(x);
    sse_utility::aligned_free(y);
    sse_utility::aligned_free(res1);
    sse_utility::aligned_free(res2);
}

#endif ///_BASIC_OPERATIONS_ET
