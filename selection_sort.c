/*

Author: Alpigramming.

References: http://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
http://www.sorting-algorithms.com/selection-sort

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	//variables
	int i, j, array_size, aux, *a;
	time_t t, start, end;
	float ti;

	//set array_size
	printf("Introduce the size of the array: \n");
	scanf("%d",&array_size);
	
	//declare array
	int array[array_size];

	//seed rand() function
	srand((unsigned) time(&t));

	//ask for memory for the array
	a = malloc(array_size * sizeof(int));

	//create & print random array
	printf("Generated random array is: \n");
	for(i = 0 ; i < array_size ; i++) {
		a[i] = rand()%101;
		printf("%d\n", a[i]);
	}

	//take the time of insertion algorithm, start clock
	start = clock();

	//i, j for comparisons, aux for swapping, in increasing order
	for(i = 0; i < array_size; i++) {
		for(j = i+1; j < array_size; j++) {
			if(a[i] > a[j]) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}

	//stop clock
	end = clock();

	//difference between end & start 
	ti = ( end - start ) / CLOCKS_PER_SEC;

	//ordered array
	printf("Ordered array is: \n");
	for(i = 0; i < array_size; i++) {
		printf("%d\n", a[i]);
	}

	//time the algorithm took
	printf("Selection sort algorithm took: ");
	printf("%f", ti);
	printf(" seconds\n");
	
	//free the memory we asked for earlier
	free(a);

	return 0;
}
