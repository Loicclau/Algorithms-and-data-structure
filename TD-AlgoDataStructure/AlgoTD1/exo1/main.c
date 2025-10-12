#include <stdio.h>
#include <time.h>
#include "fibo.h"



int main() {
    int n = 42;
    clock_t start, end;
    double cpu_time_used;
    long long int result1;
    long long int result2;

    // // ----- Version naïve -----
    start = clock();
    result1 = fibonacci_naive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Naive Fibonacci(%d) = %lld\n", n, result1);
    printf("Time taken (naive): %f seconds\n\n", cpu_time_used);

    // ----- Version dynamique -----
    long long int DPFib[n + 1];
    for (int i = 0; i <= n; i++) {
        DPFib[i] = -1;
    }

    start = clock();
    result2 = fibonacci_dynamic(n, DPFib);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic Fibonacci(%d) = %lld\n", n, result2);
    printf("Time taken (dynamic): %f seconds\n", cpu_time_used);

    return 0;
}
