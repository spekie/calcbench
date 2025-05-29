/*
 * Copyright (C) 2025 spekie
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
