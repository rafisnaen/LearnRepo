#include <stdio.h>
#include <string.h>

void swap(char a[100], char b[100]){
	char temp[100];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

int partition(char name[][100], int low, int high){
	char pivot[100];
	strcpy(pivot, name[high]);
	int i = low - 1;
	int j;
	for(j = low; j < high; j++){
		if(strcmp(name[j], pivot) < 0){
			i++;
			swap(name[j], name[i]);
		}
	}
	swap(name[i+1], name[high]);
	return i+1;
}

void quicksort(char name[][100], int low, int high){
	if(low < high){
		int indexpivot = partition(name, low, high);
		
		quicksort(name, low, indexpivot - 1);
		quicksort(name, indexpivot + 1, high);
	}
}

int main(){
	
	int testcase;
	scanf("%d", &testcase);
	getchar();
	
	int size = testcase;
	char name[testcase+1][100];
	
	int i;
	for(i = 0; i < size; i++){
		scanf("%[^\n]", name[i]);getchar();
	}
	printf("\n");
	
	quicksort(name, 0, size - 1);
	
	for(i = 0; i < size; i++){
		printf("%s\n", name[i]);
	}
	
	return 0;
}
