//*   Created By : Shreyas More
// *  Hackerrank : RealShreyas
// *  CodeChef : frenzied_p_98
// *  Hackerearth : shrmore
// *------------------------------------
// *  OS : Windows 10
// *  Language : C
// *  Editor : Sublime Text 3
// *  C compiler : GNU GCC

#include<stdio.h>

int size;

int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);

int main(int argc, char const *argv[]) {
	int arr[] = {5,7,98,45,12,34,56,78,10,81,19,33,57,94}, i;
	size = sizeof(arr) / sizeof(arr[0]);
	printf("The Original Array is :\n");

	for(i = 0; i < size; i++) { printf("%d\t",arr[i]); }

	printf("\n");
                quick_sort(arr, 0, size - 1);
	printf("The Sorted Array is :\n");

	for(i = 0; i < size; i++) { printf("%d\t", arr[i]); }

	printf("\n");
	return 0;
}
/**
 * This function takes the first element in the unsorted array initially and partitions the array 
 * into two halves with it beiing the middle element and subsequently both the halves are again
 * partitioned and sorted 
 * @param  a [The array which needs to be sorted]
 * @param  beg [pointer to the first element]
 * @param  end [pointer to the last element]
 * @return     [the middle element which taken as reference on both sides]
 */
int partition(int a[], int beg, int end) {
	int left, right, loc, temp, flag;
	left = loc = beg;
	right = end;
	flag = 0;
	while(flag != 1) {
		while( (a[loc] <= a[right]) && (loc != right)) { right-- ; }
		if(loc == right) { flag = 1; }
		else if(a[loc] > a[right]) {
			temp = a[loc];
			a[loc] = a[right];
			a[right] = temp;
			loc = right;
		}
		if(flag != 1) {
			while( (a[loc] >= a[left]) && (loc != left)) { left++; }
			if(loc == left) { flag = 1; }
			if(a[loc] < a[left]) {
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}
/**
 * This function handles the partitioning of the array and iterative implementation of recursively 
 * sorting the arrays after partioning them
 * @param  a [The array which needs to be sorted]
 * @param  beg [pointer to the first element]
 * @param  end [pointer to the last element]
 */
void quick_sort(int a[], int beg, int end) {
	int loc;
	if(beg < end) {
		loc = partition(a, beg, end);
		quick_sort(a, beg, loc - 1);
		quick_sort(a, loc + 1, end);
	}
}