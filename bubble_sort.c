
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort_ascending(int a[], int n);
void sort_descending(int a[], int n);

int main() {

	int *a, n, i;
	
	printf("enter the total no. of elements to sort\n");
	scanf("%d",&n);
	
	a = (int *)malloc(sizeof(int) * 100);

	if(!a) {
		printf("malloc error\n");
		return -1;
	}
	memset(a, 0, sizeof(int) * 100);
	printf("enter the elements :\n");
	for(i = 0; i < n; i++) {
		printf("enter the %d element :", i+1);
		scanf("%d",&a[i]);
	}
	
	sort_ascending(a, n);

	printf("Sorted array in ascending order:\n");
	for(i = 0; i < n; i++) {
		printf("%d\n",a[i]);
	}
	
	sort_descending(a, n);
	
	printf("Sorted array in descending order:\n");
	for(i = 0; i < n; i++) {
		printf("%d\n",a[i]);
	}
}

void sort_ascending(int a[], int n) {

	int i, j, temp;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void sort_descending(int a[], int n) {
	
	int i, j, temp;
	for(i = 0;i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if(a[j] < a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}	
