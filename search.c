#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// i) Brute Force Search (Linear Search)
int bruteForceSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// ii) Divide and Conquer Search (Binary Search - requires sorted array)
int divideAndConquerSearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return divideAndConquerSearch(arr, low, mid - 1, target);
    } else {
        return divideAndConquerSearch(arr, mid + 1, high, target);
    }
}

int main() {
    int n_values[] = {1000, 5000, 10000, 50000, 100000, 500000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    int target = -1; // Worst-case: element not present or at the end

    printf("n\t\tBrute Force Time (s)\tDivide & Conquer Time (s)\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        
        // Populate array with sorted elements
        for (int j = 0; j < n; j++) {
            arr[j] = j;
        }

        // Measure Brute Force Time
        clock_t start_bf = clock();
        bruteForceSearch(arr, n, target);
        clock_t end_bf = clock();
        double time_bf = (double)(end_bf - start_bf) / CLOCKS_PER_SEC;

        // Measure Divide and Conquer Time
        clock_t start_dc = clock();
        divideAndConquerSearch(arr, 0, n - 1, target);
        clock_t end_dc = clock();
        double time_dc = (double)(end_dc - start_dc) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\t\t%f\n", n, time_bf, time_dc);

        free(arr);
    }

    return 0;
}