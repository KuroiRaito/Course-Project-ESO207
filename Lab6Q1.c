#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

void insort(int arr[], int n)
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

int partition(int arr[], int l, int r, int k);

void sort(int arr[], int n){
     int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findMedian(int arr[], int n)
{
    sort(arr, n);
    
	if (n%2==1) return arr[n/2];
	if (n%2==0) return (arr[n/2 -1]+arr[n/2])/2;
}

int kthSmallest(int arr[], int l, int r, int k)
{
		int n = r-l+1; 
		int i, median[(n+4)/5]; 
		
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
			
		if (i*5 < n) 
		{
			median[i] = findMedian(arr+l+i*5, n%5);
			i++;
		}	


		int medOfMed = (i == 1)? median[i-1]:
								kthSmallest(median, 0, i-1, i/2);

		
		int pos = partition(arr, l, r, medOfMed);
	
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) 
			return kthSmallest(arr, l, pos-1, k);
		
		 return kthSmallest(arr, pos+1, r, k-pos+l-1);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int l, int r, int x)
{

	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);

	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

int main()
{
    int n,min, max, randomNum;
    scanf("%d %d %d", &min,&max,&n);
        int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }

    if (n%2==1) printf("%d ",kthSmallest(arr, 0, n-1, 1+n/2));
    else if (n%2==0) {
        int x1 = kthSmallest(arr, 0, n-1, 1+n/2);
        int x2 = kthSmallest(arr, 0, n-1, n/2);
        printf("%d ",(x1+x2)/2);
    }
    
    insort(arr,n);
    printf("\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}