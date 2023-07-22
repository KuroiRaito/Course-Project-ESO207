#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void max_heapify(int arr[],int n,int i)
{
    int largest  = i;
    while(1)
    {
        if(i*2+1<n && arr[i*2+1]>arr[largest])
            largest=2*i+1;
        if(2*i+2<n && arr[2*i+2]>arr[largest])
            largest=2*i+2;
        if(largest!=i)
        {
            int t=arr[largest];
            arr[largest]=arr[i];
            arr[i]=t;
            i=largest;
        }
        else break;
    }
}

void build_heap(int arr[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        max_heapify(arr, n, i);
    }
}

void heapsort(int arr[],int n)
{
    build_heap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        max_heapify(arr,i,0);
    }
}

int main()
{

    // {int N,min, max, randomNum;
    // scanf("%d %d %d", &min,&max,&N);
    // srand(time(0));
    // for(int i=0;i<N;i++)
    // {
    // randomNum = rand() % (max - min + 1) + min;
    // printf("%d\n",randomNum);
    // }
    // }
    
    // {int n = 100;
	// int arr[n];
	// double time_spent = 0.0;
    // clock_t begin = clock();
	// for(int i=0;i<n;i++){
	// 	arr[i] = rand();
	// }
	// insertionSort(arr, n);
	// printArray(arr, n);
	// clock_t end= clock();
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	// printf("The elapsed time is %f seconds", time_spent);
    // }

    // {int n = 1000;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     arr[i] = rand();
    // }
    // double time_spent = 0.0;
    // clock_t begin = clock();
    // heapsort(arr,n);
    // for(int i=0;i<n;i++)
    //     printf("%d ",arr[i]);
    // clock_t end= clock();
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("The elapsed time is %f seconds", time_spent);
    // }

    return 0;
}