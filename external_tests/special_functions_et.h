#pragma once
#if !defined(_SPECIAL_FUNCTIONS_ET)
#define _SPECIAL_FUNCTIONS_ET

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sse_math_x64_lib.h>

#include "macros/sse_macros.h"

using namespace sse_specials;

void testErfSSEDouble()
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
    x[5] = 0.30;
    x[6] = 0.25;
    x[7] = 0.015;
    x[8] = 0.6;
    x[9] = 0.012;
    x[10] = pi / 4.0;
    x[11] = 0.56;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10.2;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erf_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erf(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed erf SSE occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
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

void testErfSSEFloat()
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
    x[5] = 0.30f;
    x[6] = 0.25f;
    x[7] = 0.015f;
    x[8] = 0.6f;
    x[9] = 0.012f;
    x[10] = pi / 4.0f;
    x[11] = 0.56f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 9.2f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erf_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erf(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed erf SSE occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
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

void testErfcSSEDouble()
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
    x[5] = 0.30;
    x[6] = 0.25;
    x[7] = 0.015;
    x[8] = 0.6;
    x[9] = 0.012;
    x[10] = pi / 4.0;
    x[11] = 0.56;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10.2;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erfc_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = erfc(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed erfc SSE occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
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

void testErfcSSEFloat()
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
    x[5] = 0.30f;
    x[6] = 0.25f;
    x[7] = 0.015f;
    x[8] = 0.6f;
    x[9] = 0.012f;
    x[10] = pi / 4.0f;
    x[11] = 0.56f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 9.1f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erfc_sse(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = erfc(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    SSE_ASSERT(rc1 == 1, "Failure in packed erfc SSE occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
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

#endif ///_SPECIAL_FUNCTIONS_ET
