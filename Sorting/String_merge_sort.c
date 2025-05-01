#include <stdio.h>
#include <string.h>
// cara melakukan name merge sort
// 1. Pakai library string.h
// 2. Jika number itu langsung assign, maka string memakai string copy
// 3. Jika number itu langsung compare, maka string memakai string compare
// 4. Ganti semua deklarasi variabel num dengan deklarasi string 2 dimensi


void merge(char num[][100], int i, int j, int k){
	
	int mergesize = k - i + 1;
	char temparr[mergesize][100];
	int leftpos = i;
	int rightpos = j+1;
	int mergepos = 0;
	
	while(leftpos <= j && rightpos <= k){
		if(strcmp(num[leftpos], num[rightpos]) < 0){
			strcpy(temparr[mergepos], num[leftpos]);
			++leftpos;
			++mergepos;
		}else{
			strcpy(temparr[mergepos], num[rightpos]);
			++rightpos;
			++mergepos;
		}
	}
	
	while(leftpos <= j){
		strcpy(temparr[mergepos], num[leftpos]);
		++leftpos;
		++mergepos;
	}
	
	while(rightpos <= k){
		strcpy(temparr[mergepos], num[rightpos]);
		++rightpos;
		++mergepos;
	}
	
	int a;
	for(a = 0; a < mergesize; a++){
		strcpy(num[i + a], temparr[a]);
	}
}

void mergesort(char num[][100], int i, int k){
	int j;
	
	if(i < k){
		j = (k + i) / 2;
		
		mergesort(num, i, j);
		mergesort(num, j+1, k);
		
		merge(num, i, j, k);
	}	
}

int main(){
	
	int size;
	scanf("%d", &size);
	getchar();
	
	char num[size+1][100];
	
	int i;
	for(i = 0; i < size; i++){
		scanf("%[^\n]", num[i]);
		getchar();
	}
	
	printf("\nBefore sort:\n");
	for(i = 0; i < size; i++){
		printf("%s\n", num[i]);
	}
	printf("\n\n");
	
	mergesort(num, 0, size - 1);
	
	printf("Merged sort:\n");
	for(i = 0; i < size; i++){
		printf("%s\n", num[i]);
	}
	
	return 0;
}
