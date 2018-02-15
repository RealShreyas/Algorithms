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
#define size 10

int length;

int largest(int a[]);
void radix_sort(int a[]);

int main(int argc, char const *argv[]){
	int arr[] = {5,7,98,45,12,34,56,78,10,81,19,33,57,94}, i;
	length = sizeof(arr) / sizeof(arr[0]);
	printf("The Original Array is :\n");

	for(i = 0; i < length; i++)
		printf("%d\t",arr[i]);

	printf("\n");
	radix_sort(arr);
	printf("The Sorted Array is :\n");

	for(i = 0; i < length; i++)
		printf("%d\t", arr[i]);

	return 0;
}

int largest(int a[]) {
	int large = a[0], i;
	for (i = 1; i < length; ++i) {
		if(a[i] > large) large = a[i];
	}
	return large;
}

void radix_sort(int a[]){
	int bucket[size][size], bucket_count[size];
	int i, j, k, remainder, NOP = 0, divisor = 1, pass, large;

	large = largest(a);

	while (large > 0) {
		large /= size;
		NOP++;
	} 

	for (pass = 0; pass < NOP; pass++) {
		for (i = 0; i < size; i++) bucket_count[i] = 0;

		for (i = 0; i < length; i++) {
			remainder = (a[i] / divisor) % size;
			bucket[remainder][bucket_count[remainder]] = a[i];
			bucket_count[remainder] += 1;
		}

		i = 0;

		for (j = 0; j < size; j++) {
			for (k = 0; k < bucket_count[j]; k++) {
				a[i] = bucket[j][k];
				i++;
			}
		}

		divisor *= size;
	}
}
