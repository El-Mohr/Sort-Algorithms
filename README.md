# Sort-Algorithms
A collection of different sort algorithms implemented in C

## Implemented algorithms:

- Bubble sort ( and Optimized Buuble sort)
- Insertion Sort
- Selection Sort
- Merge Sort
- Heap Sort (Recursive and iterative)
- Quick Sort

All functions return void and takes an array of int as well as the array size.

## Performance analysis of the implemented functions:

- selection_sort:		Worst case O(n^2)		  Average case O(n^2)		  Best case O(n^2)		  Space: O(1)					      Stable
- insertion_sort: 	Worst case O(n^2)		  Average case O(n^2)		  Best case O(n)			  Space: O(1)					      Stable
- bubble_sort: 		  Worst case O(n^2)		  Average case O(n^2)		  Best case O(n^2)		  Space: O(1)					      Stable
- bubble_sort_opt: 	Worst case O(n^2)		  Average case O(n^2)		  Best case O(n)			  Space: O(1)					      Stable
- merge_sort:			  Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(n)					      Stable
- heap_sort_rec:	  Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(log(n))			    Unstable
- heap_sort_it:	    Worst case O(nlog(n))	Average case O(nlog(n))	Best case O(nlog(n))	Space: O(1)					      Unstable
- quick_sort:			  Worst case O(n^2)		  Average case O(nlog(n))	Best case O(nlog(n))	Space: O(log(n)) to O(n)	Unstable

