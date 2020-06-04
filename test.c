/*
 * test.c
 * Author: Mahmoud Elmohr
 *
 */

#include "sort.h"
#include <stdio.h>

//An auxiliary function to print out array elements
void print_array(int arr[], int arr_size){
	for (int i=0; i<arr_size; i++){
		printf("%i  ",arr[i]);
	}
	printf("\n");
}



int main(){

	int array[] = {3,7,5,9,2,4,6,0};
	//int array[] = {0,1,2,3,4,5,6,7};
	//int array[] = {7,6,5,4,3,2,1,0};


	int n = sizeof(array)/sizeof(array[0]);

	print_array(array, n);


	bubble_sort(array, n);
	//bubble_sort_opt(array, n);
	//insertion_sort(array, n);
	//selection_sort(array, n);
	//merge_sort(array, n);
	//heap_sort_rec(array, n);
	//heap_sort_it(array, n);
	//quick_sort(array, n);


	print_array(array, n);


	return 0;
}
