#include <stdio.h>
#include <string.h>

struct mahasiswa{
	char name[100];
	int num;
};

void swap(struct mahasiswa *a, struct mahasiswa *b){
	struct mahasiswa temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct mahasiswa mhs[], int low, int high){
	struct mahasiswa pivot = mhs[high];
	
	int i = low - 1;
	int j;
	
	for(j = low; j < high; j++){
		if(mhs[j].num < pivot.num || (mhs[j].num == pivot.num && strcmp(mhs[j].name, pivot.name) < 0)){
			i++;
			swap(&mhs[j], &mhs[i]);
		}
	}
	
	swap(&mhs[i+1], &mhs[high]);
	return i+1;
}

void quicksort(struct mahasiswa mhs[], int low, int high){
	if(low < high){
		int indexpivot = partition(mhs, low, high);
		
		quicksort(mhs, low, indexpivot - 1);
		quicksort(mhs, indexpivot + 1, high);
	}
}

int main(){
	
	int testcase;
	scanf("%d", &testcase);
	getchar();
	
	int size = testcase;
	struct mahasiswa mhs[size];
	
	int i;
	for(i = 0; i < size; i++){
		scanf("%[^#]#%d", mhs[i].name, &mhs[i].num);
		 getchar();
	}
	printf("\n");
	quicksort(mhs, 0, size - 1);
	
	for(i = 0; i < size; i++){
		printf("%s-%d\n", mhs[i].name, mhs[i].num);
	}
	
	return 0;
}
