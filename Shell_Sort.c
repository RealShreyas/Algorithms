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

void shell_sort(int arr[]);

int main(int argc, char const *argv[]) {
	int arr[] = {5,7,98,45,12,34,56,78,10,81,19,33,57,94}, i;
	size = sizeof(arr) / sizeof(arr[0]);
	printf("The Original Array is :\n");

	for(i = 0; i < size; i++) { printf("%d\t",arr[i]); }

	printf("\n");
                shell_sort(arr);
	printf("The Sorted Array is :\n");

	for(i = 0; i < size; i++) { printf("%d\t", arr[i]); }

	printf("\n");
	return 0;
}

void shell_sort(int arr[]){
	int gap_size, flag, i, temp;
	flag = 1;

	while(flag == 0 || gap_size > 1){
		gap_size = (gap_size + 1) / 2;

		for(i = 0; i < (size - gap_size); i++){
			if(arr[i] > arr[i + gap_size]){
				temp = arr[i + gap_size];
				arr[i + gap_size] = arr[i];
				arr[i] = temp;
				flag = 1;
			}
		}
	}
}