#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size) {
	/*
    size_t i, j, k, mid;
    int *temp;

    if (size <= 1) {
        return;
    }

    mid = size / 2;

    temp = malloc(size * sizeof(int));

    for (i = 0; i < mid; i++) {
        temp[i] = array[i];
    }
    for (i = mid; i < size; i++) {
        temp[i] = array[i];
    }

    merge_sort(temp, mid);
    merge_sort(temp + mid, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < mid; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (i = mid; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    i = 0, j = mid, k = 0;
    while (i < mid && j < size) {
        if (temp[i] <= temp[j]) {
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }

    while (i < mid) {
        array[k++] = temp[i++];
    }
    while (j < size) {
        array[k++] = temp[j++];
    }

    printf("[Done]: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
	free (temp);
	*/
	array = array;
	size = size;
}
