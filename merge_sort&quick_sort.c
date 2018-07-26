
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
	int *a, i, n, choice;
	
	a = (int *)malloc(sizeof(int) * 100);
	
	if(!a) {
		printf("malloc error");
		return -1;
	}
	
	printf("enter the no of elements to sort: ");
	scanf("%d",&n);
  	memset(a, 0, sizeof(int) * 100);
	printf("enter the elements one by one\n");
	for(i = 0; i < n; i++) {
		printf("enter the %d element:",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("1. Mergesort\n2. Quicksort\n");
	scanf("%d", &choice);
	
	switch(choice) {
	
		case 1:	mergesort(a, 0, n-1);
	
			printf("the sorted array after merge sort is:\n");
			for(i = 0; i < n; i++) {
				printf("%d\n",a[i]);
			}
			break;

		case 2:	quicksort(a, 0, n-1);
		
			printf("the sorted array after quick sort is:\n");
			for(i = 0; i < n; i++) {
				printf("%d\n",a[i]);
			}
			break;
		default: exit(0);
	}
	free(a);
	a = NULL;
}

void mergesort(int *a, int low, int high) {
	
	int mid;
	if(low < high) {
		mid = (high + low) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

void merge(int *a, int low, int mid, int high) {
	int i, j, k,*temp;
	
	temp = (int*)malloc(sizeof(int) * 1000);

	if(!temp) {
		printf("malloc error");
		exit(0);
	}
	
	memset(temp, 0, sizeof(int) * 1000);

	i = low;
	j = mid+1;
	k = low;
	
	while((i <= mid) && (j <= high)) {
		if(a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = a[i++];
	}
	while(j <= high) {
		temp[k++] = a[j++];
	}
	for(i = low; i <= high; i++)
	{
		a[i] = temp[i];
	}
	free(temp);
	temp = NULL;
}

void quicksort(int *a, int low, int high) {
	int pi;
	if(low < high) {
		pi = partition(a, low, high);
		quicksort(a, low, pi-1);
		quicksort(a, pi+1, high);
	}
}

int partition(int a[], int low, int high) {
	int i, p, pi, temp, temp1;
	p = a[high];
	pi = low;
	for (i = low; i < high; i++) {
		if(a[i] <=  p) {
			temp = a[i];
			a[i] = a[pi];
			a[pi] = temp;
			pi++;
		}
	}
	temp1 = a[high];
	a[high] = a[pi];
	a[pi] = temp1;
	return pi;
}
