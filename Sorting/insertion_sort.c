#include <stdio.h>
//insertionsort
//choose key (start from index 1)
//declare variable j (key index - 1)
//compare the elements through loop
//if the number before key is bigger than the key ( wants to do asc )
//set j+1 with arr[j]
//check the condition until it is false
//after while loop ended, then swap j+1 with key

void insertionsort(int arr[], int size){
	int i,j;
	
	for(i = 1; i <= size - 1; i++){
		int key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
	
}

int main(){
	
	int arr[] = { 5, 3, 4, 1, 2, 10, -1, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	insertionsort(arr,size);
	
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
