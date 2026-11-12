#include <stdio.h>
#include <time.h>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

void printArray(int a[], int i, int n) {
    if (i == n) return;
    printf("%d ", a[i]);
    printArray(a, i + 1, n);
}

int recursiveMax(int a[], int n) {
    if (n == 1) return a[0];

    int maxRest = recursiveMax(a, n - 1);

    return (a[n - 1] > maxRest) ? a[n - 1] : maxRest;
}

int main() {
    int a[] = {5, 9, 1, 7, 3};
    int n = 5;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int fact_result = factorial(5);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Factorial(5) = %d\n", fact_result);
    printf("Time taken for Factorial: %f seconds\n", cpu_time_used);

    start = clock();
    int sum_result = sumDigits(1234);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sum of digits (1234) = %d\n", sum_result);
    printf("Time taken for sumDigits: %f seconds\n", cpu_time_used);

    start = clock();
    int count_result = countDigits(1234);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Count digits (1234) = %d\n", count_result);
    printf("Time taken for countDigits: %f seconds\n", cpu_time_used);

    printf("Array: ");
    start = clock();
    printArray(a, 0, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time taken for printArray: %f seconds\n", cpu_time_used);

    start = clock();
    int max_result = recursiveMax(a, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Max = %d\n", max_result);
    printf("Time taken for recursiveMax: %f seconds\n", cpu_time_used);

    return 0;
}