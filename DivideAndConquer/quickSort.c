#include<stdio.h>
#include<stdlib.h>

int partition(int[], int, int);
void quickSort(int[], int, int);
void swap(int*, int*);

int main(){
	int numbers[20], n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for(i=0; i<n; i++)
        scanf("%d", &numbers[i]);

	quickSort(numbers, 0, n-1);
	for(int i=0; i<n; i++)
		printf("%d ", numbers[i]);
	printf("\n");

}
int partition(int A[], int start, int end){
	int pivot, pIndex, i;
	pivot = A[end];
	pIndex = start;
	for(i=start; i<end; i++){
		if(A[i] <= pivot){
			swap(&A[i], &A[pIndex]);
			pIndex = pIndex+1;
		}
	}
	swap(&A[pIndex], &A[end]);
	return pIndex;
}
void quickSort(int A[], int start, int end){
	int pIndex;
	if(start<end){
		pIndex = partition(A, start, end);
		quickSort(A, start, pIndex-1);
		quickSort(A, pIndex+1, end);
	}
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
