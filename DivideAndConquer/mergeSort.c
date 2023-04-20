#include<stdio.h>
#include<stdlib.h>

void merge(int[], int[], int[], int, int);
void mergeSort(int[], int);

int main(){
	int numbers[20], n;
	printf("Size: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for(int i=0; i<n; i++)
        scanf("%d", &numbers[i]);

	mergeSort(numbers, n);
	for(int i=0; i<n; i++)
		printf("%d ", numbers[i]);
	printf("\n");
	getchar();
}

void merge(int A[], int L[], int R[], int nL, int nR){
	int i=0, j=0, k=0;
	while(i<nL && j<nR){
		if(L[i]<=R[j]){
			A[k] = L[i];
			i = i+1;
		}
		
		else{
			A[k] = R[j];
			j = j+1;
		}
		k = k+1;
	}
	while(i<nL){
		A[k] = L[i]; i = i+1;  k = k+1;
	}
	while(j<nR){
		A[k] = R[j]; j = j+1; k = k+1;
	}
}

void mergeSort(int A[], int n){
	if(n<2)
		return;
	int i, mid, *left, *right;
	mid = n/2;
	left = (int *) malloc(mid * sizeof(int));
	right = (int *) malloc((n-mid) * sizeof(int));
	for(i=0; i<mid; i++)
		left[i] = A[i];
	for(i=mid; i<n; i++)
		right[i-mid] = A[i];
	mergeSort(left, mid);
	mergeSort(right, n-mid);
	merge(A, left, right, mid, n-mid);
	free(left);
	free(right);

}
