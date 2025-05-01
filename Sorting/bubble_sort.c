#include <stdio.h>
//bubblesort
//the simpliest sorting algorithm
//compare one elements with the elements after, then swap if intended
//do it until sorted through loop

void bubblesort(int arr[], int size){
	int i,j;
	
	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			
			if(arr[j] > arr[j+1]){
				
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
			}
		}
	}
}

int main(){
	
	int arr[] = { 5, 3, 4, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	bubblesort(arr, size);
	
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
}
