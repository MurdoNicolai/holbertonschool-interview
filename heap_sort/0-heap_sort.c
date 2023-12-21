#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Heapify a subtree rooted at index 'root' in the array
 * @array: Array to be sorted
 * @size: Size of the array
 * @root: Index of the root of the subtree
 */
void heapify(int *array, size_t size, size_t root) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(&array[root], &array[largest]);
        printf("Swap: %d %d\n", array[root], array[largest]);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(&array[0], &array[i]);
        printf("Swap: %d %d\n", array[0], array[i]);
        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}
