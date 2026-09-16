#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Brute Force Search (Linear Search)
// Checks every element one by one from left to right.
int bruteForceSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// 2. Divide and Conquer Search (Binary Search)
// Works on a sorted array by repeatedly dividing the search space in half.
int divideAndConquerSearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If element is at the middle
        if (arr[mid] == target)
            return mid;

        // If element is smaller than mid, search the left half
        if (arr[mid] > target)
            return divideAndConquerSearch(arr, low, mid - 1, target);

        // Otherwise, search the right half
        return divideAndConquerSearch(arr, mid + 1, high, target);
    }
    return -1; // Element not present
}

int main() {
    // A simple, sorted array of numbers
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = 10;          // Total number of elements
    int target = 14;     // The number we want to find

    printf("Searching for %d in the array...\n\n", target);

    // --- 1. Test Brute Force ---
    clock_t start_bf = clock();
    int result_bf = bruteForceSearch(arr, n, target);
    clock_t end_bf = clock();
    double time_bf = (double)(end_bf - start_bf) / CLOCKS_PER_SEC;

    printf("Brute Force:\n");
    printf("- Result: Found at index %d\n", result_bf);
    printf("- Time taken: %f seconds\n\n", time_bf);

    // --- 2. Test Divide and Conquer ---
    clock_t start_dc = clock();
    int result_dc = divideAndConquerSearch(arr, 0, n - 1, target);
    clock_t end_dc = clock();
    double time_dc = (double)(end_dc - start_dc) / CLOCKS_PER_SEC;

    printf("Divide & Conquer:\n");
    printf("- Result: Found at index %d\n", result_dc);
    printf("- Time taken: %f seconds\n", time_dc);

    return 0;
}