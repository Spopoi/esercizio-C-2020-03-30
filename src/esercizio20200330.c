#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long fibonacci(unsigned long n){
	if(n==0) return 0;
	if(n==1) return 1;
	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

unsigned long * fibonacci_array(unsigned int n){
	unsigned long* result = calloc(1,sizeof(unsigned long));
	for(int i = 0 ; i < n+1 ; i++){
		result = realloc( result , (i+1) * sizeof(unsigned long));
		result[i] = fibonacci(i);
	}
	return result;
}

void swap(unsigned long * array ,int i, int j){
	unsigned long buffer= array[i];
	array[i]=array[j];
	array[j]= buffer;
}

void bubble_sort(unsigned long * array, int array_dimension) {

	int n = array_dimension;
	int newn;
	while(n>0){
		newn=0;
		for(int i = 1 ; i < n ; i++){
			if(array[i-1]>array[i]){
				swap(array, i-1,i);
				newn=i;
			}
		}
		n=newn;
	}
}

short sameValueArray(unsigned long* firstArray, unsigned long* secondArray){
	for(int i = 0 ; i < 40 ; i++){
		if(firstArray[i]!= secondArray[i]) return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {

	unsigned long * fibonacci_result = fibonacci_array(39);
	printf("serie di fibonacci fino a 39:\n");
	for(int i = 0 ; i < 40 ; i++){
				printf("fibonacci_array[%d] = %lu \n", i, fibonacci_result[i]);
	}

	unsigned long * fibonacci_result_copy = calloc(40,sizeof(unsigned long));
	memcpy(fibonacci_result_copy, fibonacci_result, 40 * sizeof(long));
	printf("\n\ncopia della serie:\n");
	for(int j = 0 ; j < 40 ; j++){
				printf("fibonacci_array_copy[%d] = %lu \n", j, fibonacci_result_copy[j]);
		}

	for(int k = 0 ; k < 40 ; k++){ //inversion of fibonacci_array_copy
		fibonacci_result_copy[k]=fibonacci_result[39-k];
	}
	printf("\n\ninversione del contenuto dell'array copia:\n");
	for(int l = 0 ; l < 40 ; l++){
				printf("fibonacci_array_copy[%d] = %lu \n", l, fibonacci_result_copy[l]);
		}

	bubble_sort(fibonacci_result_copy , 40);
	printf("\n\ncontenuto dopo bubble sort applicato alla copia dell'array\n");
	for(int y = 0 ; y < 40 ; y++){
				printf("fibonacci_array_copy[%d] = %lu \n", y, fibonacci_result_copy[y]);
	}

	if ((sameValueArray(fibonacci_result, fibonacci_result_copy))!= 0 ) printf("Bubble sort ha fallito, gli array sono diversi\n");
	else printf("I due array sono uguali\n");

	free(fibonacci_result);
	free(fibonacci_result_copy);

}
