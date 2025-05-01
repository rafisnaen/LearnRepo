#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	
	int j;
	for(j = low; j < high; j++){ 
		if(arr[j] < pivot){
			i++;
			swap(&arr[j], &arr[i]);
		}
	} 
	
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

int quicksort(int arr[], int low, int high){
	
	if(low < high){
		int pivotindex = partition(arr,low,high);
		
		quicksort(arr, low, pivotindex - 1);
		quicksort(arr, pivotindex+1, high);
	}
}

int main(){
	
	int a;
	int i;
	scanf("%d", &a);
	
	int arr[a];
	for(i = 0; i < a; i++){
		scanf("%d", &arr[i]);
	}
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	quicksort(arr, 0, size - 1);
	
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
