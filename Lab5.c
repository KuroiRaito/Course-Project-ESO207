#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int a,int b){
if (a<b) return a;
else return b;
}

void merge(int arr[], int left,int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int temp1[n1], temp2[n2];

	for (int i=0;i<n1;i++)  temp1[i] = arr[left + i];
	for (int i=0; i<n2; i++)  temp2[i] = arr[mid + 1+ i];

	int i=0, j=0, k=left;
	
	while (i<n1 && j<n2){
		if (temp1[i]<=temp2[j])  arr[k] = temp1[i++];
		else  arr[k] = temp2[j++];
		k++;
	}
	while (i<n1) arr[k++] = temp1[i++];
	while (j<n2) arr[k++] = temp2[j++];	
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{

{	
    int n,min, max, randomNum;
    scanf("%d %d %d", &min,&max,&n);
	int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
	double time_spent = 0.0;
	clock_t begin = clock();
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
	return 0;
	}

{	
    int n,min, max, randomNum;
    scanf("%d %d %d", &min,&max,&n);
	int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
	double time_spent = 0.0;
	clock_t begin = clock();
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array is \n");
    printArray(arr, n);
	clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    return 0;
	}

}

