#include <stdio.h>
// Belajar rekursif
// Buat faktorial !

//int fact(int n){
//	if(n == 1){
//		return 1;
//	}else{
//		return n * fact(n - 1); 
//	}
//	
//}
//
//int main(){
//	int a;
//	scanf("%d", &a);
//	
//	int res = fact(a);	
//	printf("Factorial result : %d", res);
//	
//	return 0;
//}

// Buat fibonacci

int fib(int n){
	if(n == 1){
		return 0;
	}
	else if(n == 2){
		return 1;
	}else{
		return fib(n - 2) + fib(n - 1);
	}
	
}


int main(){
	int a;
	scanf("%d", &a);
	
	int res = fib(a);	
	printf("Fibonacci result : %d", res);
	
	return 0;
}
