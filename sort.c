/*
 * sort.c
 * Author: Mahmoud Elmohr
 *
 */


#include "sort.h"
#include <stdbool.h>



/*
 * Swap function used by sorting algorithms
*/
void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b= temp;
}



/*
 * Bubble Sort:
 * compare each two adjacent elements and swap if left is > right,
 * by the end of the iteration you will have the max to the right,
 * and go again
 * Worst case O(n^2)		Average case O(n^2)		Best case O(n^2)		Space: O(1)					Stable
*/
void bubble_sort(int arr[], int arr_size){
	for (int i=0; i<arr_size-1; i++)
		for (int j=0; j<arr_size-1-i; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}




/*
 * Bubble Sort Optimized:
 * Uses a flag that is set if a swap happens in an iteration
 * If in an iteration no swap happens it means the array is sorted so no need to continue
 * Worst case O(n^2)		Average case O(n^2)		Best case O(n)		Space: O(1)					Stable
*/
void bubble_sort_opt(int arr[], int arr_size){
	for (int i=0; i<arr_size-1; i++){
		bool swapped=0;
		for (int j=0; j<arr_size-1-i; j++){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
		}
		if(swapped==0){
			break;
		}
	}
}



/*
 * Insertion Sort
 * For each element compare it to each element to its left and swap if it's less than the left one,
 * continue until it's greater,
 * and go again
 * Worst case O(n^2)		Average case O(n^2)		Best case O(n)			Space: O(1)					Stable
*/
void insertion_sort(int arr[], int arr_size){
	for (int i=1; i<arr_size; i++){
		int j=i;
		while(j>0 && (arr[j]<arr[j-1])){
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}



/*
 * Selection Sort
 * Set first element as minimum and traverse the list to find a minimum and swap
 * and go again
 * Worst case O(n^2)		Average case O(n^2)		Best case O(n^2)		Space: O(1)					Stable
*/
void selection_sort(int arr[], int arr_size){
	for (int i=0; i<arr_size-1; i++){
		int i_min = i;
		for(int j=i+1; j<arr_size; j++)
			if (arr[j] < arr[i_min])
				i_min = j;
		swap(&arr[i], &arr[i_min]);
	}
}



/*
 * Merge function used by merge_sort algorithm
*/
void merge(int arr[], int first, int middle, int last){
	int arr_new[last-first+1];	//creates a new array with a size containing the 2 split arrays
	int i=first;				//iterator for the first split array
	int j= middle+1;			//iterator for the second split array
	int k=0;					//iterator for the newly created array

	//While at least one split array is not fully traversed
	while(i<=middle && j<=last){
		//Check if element in order in first array is less than the element in order in the second array
		if(arr[i]<=arr[j]){		// <= to make it stable sorting (Keeps order if the two elements are equal)
			arr_new[k]=arr[i];
			i++;
		} else {
			arr_new[k]=arr[j];
			j++;
		}
		k++;
	}

	//if the second array is fully traversed then no need to compare
	while(i<=middle){
		arr_new[k]=arr[i];
		i++;
		k++;
	}

	//if the first array is fully traversed then no need to compare
	while(j<=last){
		arr_new[k]=arr[j];
		j++;
		k++;
	}

	//copy the new united array into the original array in the same positions
	for(k=0; k<=(last-first); k++){
		arr[first+k]=arr_new[k];
	}


}



/*
 * Merge Sort Auxiliary (The Actual function)
 * Split the array into two and recursively call merge_sort on the split arrays
 * Splitting will end when the split array contains only 1 element
 * Merge function would merge each 2 split arrays into a bigger sorted one
 * Merging continues until reaching original array size
*/
void merge_sort_aux(int arr[], int first, int last){
	if(last>first){
		int middle=first + (last-first)/2;
		merge_sort_aux(arr, first, middle);
		merge_sort_aux(arr, middle+1, last);
		merge(arr, first, middle, last);
	}

}



/*
 * Merge Sort
 * Just an interface to the actual function
 * To keep the interface the same as other sorting functions
 * Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(n)					Stable
*/
void merge_sort(int arr[], int arr_size){
	merge_sort_aux(arr, 0, arr_size-1);
}







/*
 * Heapify Recursive
 * Used by Heap sort algorithm to construct a heap tree
*/
void heapify_rec(int arr[], int heap_size, int node){
	// left child and right child indices
	int left = 2*node +1;
	int right = 2*node +2;
	int max = node;				//assigns current node as max at the beginning

	// if the left child's value is larger than the node's value, assign it as max
	if(left < heap_size && arr[left]>arr[max]){
		max = left;
	}

	// if the right child's value is larger than the node's value, assign it as max
	if(right < heap_size && arr[right]>arr[max]){
		max = right;
	}

	//if the node is not the max, swap it with the max and heapify from the swapped position node
	if(max!=node){
		swap(&arr[node], &arr[max]);
		heapify_rec(arr,heap_size,max);
	}
}



/*
 * Heap Sort Recursive
 * Builds a heap tree first
 * Then extracts the max element from the heap and put it at the end
 * And heapifies again
 * Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(log(n))			Unstable
*/
void heap_sort_rec(int arr[], int arr_size){
	//Build a max heap
	for(int i=(arr_size/2)-1; i>=0; i--){
		heapify_rec(arr,arr_size,i);
	}

	//Extract Max and heapify again
	for(int heap_size=arr_size-1; heap_size>0; heap_size--){
		swap(&arr[0], &arr[heap_size]);
		heapify_rec(arr, heap_size, 0);
	}
}



/*
 * Heapify Iterative
 * Used by Heap sort algorithm to construct a heap
 * Uses a while loop instead of recursive call
*/
void heapify_it(int arr[], int heap_size, int node){
	//heap_size/2 is used as leafs need not to be heapified
	while(node<heap_size/2){
		// left child and right child indices
		int left = 2*node +1;
		int right = 2*node +2;
		int max = node;

		// if the left child's value is larger than the node's value, assign it as max
		if(left < heap_size && arr[left]>arr[max]){
			max = left;
		}

		// if the right child's value is larger than the node's value, assign it as max
		if(right < heap_size && arr[right]>arr[max]){
			max = right;
		}

		//if the node is not the max, swap it with the max and continue heapifing from the swapped node's position
		//if not then heaoifying complete and break the loop
		if(max!=node){
			swap(&arr[node], &arr[max]);
			node = max;
		} else{
			break;
		}
	}
}



/*
 * Heap Sort Iterative
 * Builds a heap tree first
 * Then extracts the max element from the heap and put it at the end
 * And heapifies again
 * Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(1)					Unstable
*/
void heap_sort_it(int arr[], int arr_size){
	//Build a max heap
	for(int i=(arr_size/2)-1; i>=0; i--){
		heapify_it(arr,arr_size,i);
	}

	//Extract Max and heapify again
	for(int heap_size=arr_size-1; heap_size>0; heap_size--){
		swap(&arr[0], &arr[heap_size]);
		heapify_it(arr, heap_size, 0);
	}
}






/*
 * Partition
 * Used by Quick Sort
*/
int partition(int arr[], int first, int last){
	int pivot = first + (last-first)/2;	//Set the pivot at the middle
	int pivot_value = arr[pivot];
	int i=first;
	int j=last;

	while(i<j){
		while(arr[i]<pivot_value){
			i++;		//increase the left pointer until finding an element larger or equal to the pivot
		}

		while(arr[j]>pivot_value){
			j--;		//decrease the right pointer until finding an element smaller or equal to the pivot
		}

		if(i<j){ //make sure the pointers didn't cross path yet
			swap(&arr[i],&arr[j]);
		}
	}
	return j;	//j is the new pivot position
}


/*
 * Quick Sort Auxiliary (The Actual function)
 * Partitions the array into two sorted arrays
 * Calls quick sort recursively to split again
 * Splitting will end when the split array contains only 1 element
*/
void quick_sort_aux(int arr[], int first, int last){
	int pivot;
	if(first<last){
		pivot = partition(arr,first, last);
		quick_sort_aux(arr,first, pivot-1);
		quick_sort_aux(arr,pivot+1, last);
	}

}



/*
 * Quick Sort
 * Just an interface to the actual function
 * To keep the interface the same as other sorting functions
 * Worst case O(n^2)		Average case O(nlog(n))	Best case O(nlog(n))	Space: O(log(n)) to O(n)	Unstable
*/
void quick_sort(int arr[], int arr_size){
	quick_sort_aux(arr, 0, arr_size-1);
}

