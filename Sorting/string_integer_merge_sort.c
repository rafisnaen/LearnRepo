#include <stdio.h>
#include <string.h>

struct structure{
	char name[100];
	int num;
};

void merge(struct structure person[], int i, int j, int k){
	int mergedsize = k - i + 1;
	struct structure tempstruct[mergedsize];
	int mergepos = 0;
	int leftpos = i;
	int rightpos = j+1;
	
	while(leftpos <= j && rightpos <= k){
		if(person[leftpos].num > person[rightpos].num || (person[leftpos].num == person[rightpos].num && strcmp(person[leftpos].name, person[rightpos].name) < 0)){
			tempstruct[mergepos] = person[leftpos];
			++leftpos;
			++mergepos;
		}else{
			tempstruct[mergepos] = person[rightpos];
			++rightpos;
			++mergepos;
		}
	}
	
	while(leftpos <= j){
		tempstruct[mergepos] = person[leftpos];
		++leftpos;
		++mergepos;
	}
	
	while(rightpos <= k){
		tempstruct[mergepos] = person[rightpos];
		++rightpos;
		++mergepos;
	}
	
	int a;
	for(a = 0; a < mergedsize; a++){
		person[i + a] = tempstruct[a];
	}
	
}

void mergesort(struct structure person[], int i, int k){
	int j;
	
	if(i < k){
		j = (k + i) / 2;
		
		mergesort(person, i, j);
		mergesort(person, j+1, k);
		
		merge(person, i, j, k);
	}
}

int main(){

	printf("Please input testcase: ");
	int size;
	scanf("%d", &size);
	getchar();
	
	printf("Please input with format: name#num\n");
	struct structure person[size];
	int i;
	for(i = 0; i < size; i++){
		scanf("%[^#]#%d", person[i].name, &person[i].num); getchar();
	}
	printf("\n");
	
	printf("Before sort:\n");
	for(i = 0; i < size; i++){
		printf("%s#%d\n", person[i].name, person[i].num);
	}
	printf("\n");
	
	mergesort(person, 0, size - 1);
	
	printf("Merged sort:\n");
	for(i = 0; i < size; i++){
		printf("%s#%d\n", person[i].name, person[i].num);
	}
	
	return 0;
}
