#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "PrimeNumbers.h"
int main() {
    int n = 40000;
    long long int result1, result2;
    clock_t start, end;
    double cpu_time_used;

    // ----- Version naïve -----
    start = clock();
    result1 = PrimeNumbers_naive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Naive PrimeNumbers(%d) = %lld\n", n, result1);
    printf("Time taken (naive): %f seconds\n\n", cpu_time_used);

    // ----- Version dynamique (Crible) -----
    start = clock();
    result2 = PrimeNumbers_dynamic(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dynamic PrimeNumbers(%d) = %lld\n", n, result2);
    printf("Time taken (dynamic): %f seconds\n", cpu_time_used);

    return 0;
}




