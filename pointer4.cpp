#include <stdio.h>
#include <math.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));  // same as arr[i]
    }
    printf("\n");
}

int* findMax(int *arr, int size) {
    int *max = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }
    return max;
}

int* findMin(int *arr, int size) {
    int *min = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) {
            min = arr + i;
        }
    }
    return min;
}

void doubleArr(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        *(arr+i)=pow(*(arr+i), 2);
    }
}

int main() {
    int nums[] = {3, 7, 1, 9, 4};
    int size = 5;

    printArray(nums, size);

    int *maxPtr = findMax(nums, size);
    int *minPtr = findMin(nums, size);
    printf("Max value: %d\n", *maxPtr);
    printf("Max is at index: %ld\n", maxPtr - nums);  // pointer subtraction
	printf("Min value: %d\n", *minPtr);
    printf("Min is at index: %ld\n", minPtr - nums); 
    
    doubleArr(nums, size);
    printf("Doubled array: \n");
    printArray(nums, size);
    return 0;
}
