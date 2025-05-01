#include <stdio.h>
//  merge sort


void merge(int num[], int low, int mid, int high){
	
	//create temporary array to sort the num

	int mergesize = high - low + 1; 	//declare merge array size;
	int mergearr[mergesize];			//declare the temparr for sorted num
	int rightpos = mid + 1;						// declare right position
	int leftpos = low;						// declare left position
	int mergepos = 0;						// declare merge position
	
	//loop 
	//compare until left / right is empty
	while(leftpos <= mid && rightpos <= high){
		//compare left side with right side
		if(num[leftpos] <= num[rightpos]){
			mergearr[mergepos] = num[leftpos];
			++leftpos;
			++mergepos;
		}
		else{
			mergearr[mergepos] = num[rightpos];
			++rightpos;
			++mergepos;
		}
	}
	
	//loop for left side empty condition
	while(leftpos <= mid){
    	mergearr[mergepos] = num[leftpos];
    	++leftpos;
    	++mergepos;
	}
	
	
	//loop for right side empty condition
	while(rightpos <= high){
		mergearr[mergepos] = num[rightpos];
		++rightpos;
		++mergepos;
	}
	
	//copy sorted temparr merge to initial array
	int i;
	for(i = 0; i < mergesize; i++){
		num[low+i] = mergearr[i];
	}
	
}


void mergeSort(int num[], int low, int high){
	//declare midpoint
	int mid;
	
	if(low < high){
		// midpoint
		mid = (high + low) / 2;
		
		//recursively divide the array into two
		//left part
		mergeSort(num, low, mid);
		//right part
		mergeSort(num, mid+1, high);
		
		//merge the sorted array
		merge(num, low, mid, high);		
	}
}

int main(){
	
	int N;
	int i;
	scanf("%d", &N);
	
	int size = 3*N;
	int num[size];
	for(i = 0; i < size; i++){
		scanf("%d", &num[i]);
	}
	
	mergeSort(num, 0, size - 1);
	
	int median = num[N];
	for(i = N + 1; i < 2 * N; i++){
		if(num[i] < median){
			median = num[i];
		}
	}
	
	printf("%d\n", median);
	
   return 0;
}
