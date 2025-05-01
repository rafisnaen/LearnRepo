#include <stdio.h>


void swap(int *a, int*b){
  int temp = *a;
  *a = *b;
  *b = temp; 
}

void selectionsort(int arr[], int size){
  
  int i,j;
  
  for( i = 0; i < size - 1; i++ ){
    int min_idx = i;
    for( j = i+1; j < size; j++){
      if(arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
   swap(&arr[i], &arr[min_idx]); 
  }
  
}

int main(){
  int arr[] = { 5, 3, 4, 1, 2 };
  int size = sizeof(arr) / sizeof(arr[0]);
  
  selectionsort(arr, size);
  
  int i;
  for( i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  
    return 0;
}
