/*
 * Copyright (c) 2025 spekie
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <time.h>

#define ARRAY_MIN (1024)
#define ARRAY_MAX (4096*4096)
#define NUM_PRIMES (100000)

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

double get_seconds() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void benchmark_primes() {
    int primes_found = 0;
    int num = 2;
    double start_time = get_seconds();

    while (primes_found < NUM_PRIMES) {
        if (is_prime(num)) {
            primes_found++;
        }
        num++;
    }
    double end_time = get_seconds();
    double elapsed_time = end_time - start_time;
    printf("Time took to find %d numbers: %f seconds\n", NUM_PRIMES, elapsed_time);
    printf("Avg time per number: %f ms\n", (elapsed_time * 1000) / NUM_PRIMES);
}

int main() {
    printf("Calculating prime numbers...\n");
    benchmark_primes();
    return 0;
}
