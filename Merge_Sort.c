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

void merge(int arr[], int beg, int mid, int end);
void merge_sort(int arr[], int beg, int end);

int main(int argc, char const *argv[]){
	int arr[] = {5,7,98,45,12,34,56,78,10,81,19,33,57,94}, i;
	size = sizeof(arr) / sizeof(arr[0]);
	printf("The Original Array is :\n");

	for(i = 0; i < size; i++)
		printf("%d\t",arr[i]);

	printf("\n");
	merge_sort(arr, 0, size - 1);
	printf("The Sorted Array is :\n");

	for(i = 0; i < size; i++)
		printf("%d\t", arr[i]);

	return 0;
}

void merge(int arr[], int beg, int mid , int end){
	int i, j , temp[size], index, k;
	i = beg, j = mid + 1, index = beg;

	while((i <= mid) && (j <= end)){
		if(arr[i] < arr[j]){
			temp[index]= arr[i];
			i++;
			index++;
		}
		else{
			temp[index]= arr[j];
			j++;
			index++;
		}
	}

	if(i > mid){
		while(j <= end){
			temp[index] = arr[j];
			j++;
			index++;
		}
	}
	else{
		while(i <= mid){
			temp[index]= arr[i];
			i++;
			index++;
		}
	}

	for(k = beg; k < index; k++){
		arr[k]= temp[k];
	}

}

void merge_sort(int arr[], int beg, int end){
	int mid;
	if(beg < end){
		mid= (beg + end) / 2;
		merge_sort(arr, beg , mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, beg, mid, end);
	}
}