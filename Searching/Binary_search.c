#include <stdio.h>

// Binary search 
// Mencari nilai tengah sebuah data
// Jika nilai yang dicari itu lebih rendah, maka high = mid - 1
// Jika nilai yang dicari itu lebih tinggi, maka low = mid + 1
// Syarat : nilai harus terurut
// Binary search bisa dapat memakai rekursif maupun iteratif
// Time complexity : Best Case: O(1)
// 					 Average Case: O(log n)
//					 Worst Case: O(log n)


// versi rekursif
//int binarysearch(int num[], int find, int low, int high){
//	int mid = ( high + low ) / 2;
//	
//	if(num[mid] == find){
//		return mid;
//	}
//	else if(num[mid] > find){
//		binarysearch(num, find, low, mid - 1);
//	}
//	else if(num[mid] < find){
//		binarysearch(num, find, mid + 1, high);
//	}
//	
//}
//
//int main(){
//	
//	int num[5] = { 2, 5, 8, 11, 14 };
//	int find;
//	
//	scanf("%d", &find);
//	int size = sizeof(num) / sizeof(num[0]);
//	
//	int index = binarysearch(num, find, 0, size);
//	printf("The number is number %d of group datas", index+1);
//	
//	return 0;
//}


// versi iteratif
int binarysearch(int num[], int find, int low, int high){
	
	while(high >= low){
		int mid = ( high + low ) / 2;
	
		if(num[mid] == find){
			return mid;
		}
		else if(num[mid] > find){
			high = mid - 1;
		}
		else if(num[mid] < find){
			low = mid + 1;
		}	
	}
	
	return -1;
}

int main(){
	
	int num[5] = { 2, 5, 8, 11, 14 };
	int find;
	
	scanf("%d", &find);
	int size = sizeof(num) / sizeof(num[0]);
	
	int index = binarysearch(num, find, 0, size);
	printf("The number is number %d of group datas", index+1);
	
	return 0;
}
