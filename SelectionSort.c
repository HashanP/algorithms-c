#include <stdio.h>
#include <math.h>

void print(int arr[], size_t len);
int* selectionSort(int arr[], size_t len);

int main() {
	int arr[] = {3, -42, -12, 314234, 3232, 24333, 22, 3, 54};
	size_t len = sizeof(arr)/sizeof(int);
	print(selectionSort(arr, len), len);
}

void print(int arr[], size_t len) {
	for(int i = 0; i < len; i++) {
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int* selectionSort(int arr[], size_t len) {
	for(int i = 0; i < len; i++) {
		int min = i;
		for(int j = i + 1; j < len; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	return arr;
}
