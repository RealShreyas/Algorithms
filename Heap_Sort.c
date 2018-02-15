//*   Created By : Shreyas More
// *  Hackerrank : RealShreyas
// *  CodeChef : frenzied_p_98
// *  Hackerearth : shrmore
// *------------------------------------
// *  OS : Windows 10
// *  Language : C
// *  Editor : Sublime Text 3
// *  C compiler : GNU GCC

#include <stdio.h>
#define MAX 10 

void Restore_Heap_Up (int *heap, int index);
void Restore_Heap_Down (int *heap, int index, int n);

int main(){
    int heap[MAX], i, j, n, temp;
    printf("\nEnter The Number Of Elements : ");
    scanf("%d", &n);
    printf("\nEnter The Elements : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
        Restore_Heap_Up(heap, i);
    }
    
    j = n;
    
    for(i = 1; i <= j; i++) {
        temp = heap[1];
        heap[1] = heap[n];
        heap[n] = temp;
        n -= 1;
        Restore_Heap_Down(heap, 1, n);
    }

    n = j;

    printf("\nThe Sorted Elements are : ");

    for (i = 1; i <= n; i++) {
        printf("%4d", heap[i]);
    }
    return 0;
}

void Restore_Heap_Up (int *heap, int index) {
    int val = heap[index];
    
    while ( (index > 1) && (heap[index / 2] < val)) {
        heap[index] = heap[index / 2];
        index /= 2;
    }

    heap[index] = val;
}

void Restore_Heap_Down(int *heap, int index, int n) {
    int val = heap[index], j;
    j = index * 2;

    while (j <= n) {
        if ( (j < n) && (heap[j] < heap[j + 1]) ) j++;
        if ( heap[j] < heap[j / 2] ) break;
        heap[j / 2] = heap[j];
        j *= 2; 
    }

    heap[j / 2] = val;
}