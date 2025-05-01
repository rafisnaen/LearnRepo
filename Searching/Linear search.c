#include <stdio.h>
/* Linear search
Keuntungan : dapat mencari data pada sebuah grup data yang acak ( tidak berurut )
			 mudah dipahami
			 
Kekurangan : Memiliki time complexity yang sama
			 Best Case: O(1)
		   	 Average Case: O(n)
             Worst Case: O(n)
*/
int linearsearch(int num[], int size, int find){
	
	int i;
	for(i = 0; i < size; i++){
		if(find == num[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	
	int num[5] = { 2, 5, 8, 11, 14 };
	int find;
	
	scanf("%d", &find);
	int size = sizeof(num) / sizeof(num[0]);
	
	int index = linearsearch(num, size, find);
	printf("The number is number %d of group datas", index+1);
	
	return 0;
}
