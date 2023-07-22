#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void insort(int arr[],int n)
{
   int i,k,j;
   for(i=1;i<n;i++)
     {
	k=arr[i];
	j=i-1;

	while(j>=0 && arr[j]>k)
	  {
	     arr[j+1] = arr[j];
	     j=j-1;
	  }
	arr[j+1]=k;
     }
}

void parr(int arr[],int n)
{
   int i;
   for(i=0;i<n;i++)
     printf("%d ",arr[i]);
       printf("\n");
}

void mheap(int arr[],int n,int i)
{
   int largest = i;
   while(1)
     {
	if(i*2+1<n && arr[i*2+1]>arr[largest]) largest = 2*i+1;

	if(2*i+2<n && arr[2*i+2]>arr[largest]) largest = 2*i+2;

	if(largest != i)
	  {
	     int t = arr[largest];
	     arr[largest] = arr[i];
	     arr[i] = t;
	     i=largest;
	  }
	else break;
     }
}

void bheap(int arr[],int n)
{
   for(int i=(n-2)/2;i>=0;i--)
     {
	mheap(arr,n,i);
     }
}

void hsort(int arr[],int n)
{
   bheap(arr,n);
   for(int i=n-1;i>=0;i--)
     {
	int t=arr[0];
	arr[0]=arr[i];
	arr[i]=t;
	mheap(arr,i,0);
     }
}


int main()
{
  /* int n,min,max,randnum;
   scanf("%d %d %d",&min,&max,&n);
   srand(time(0));
   for(int i=0;i<n;i++)
     {
	randnum = rand() % (max - min + 1) + min;
	printf("%d\n",randnum);
     }*/

   int n=1000000;
   int arr[n]; // = {-1,-14,0,2,4,12,36,25,3,27};
   double time_spent = 0.0;
   clock_t begin = clock();
   for(int i=0;i<n;i++)
     {
	arr[i] = rand();
     }
   insort(arr,n);
   parr(arr,n);
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   printf("The elapsed time is %f seconds", time_spent);

  /* int n = 10;
   int arr[] = {-14,-1,0,2,3,4,6,7,15,25} ;
   for(int i=0;i<n;i++)
     {
	arr[i] = rand();
     }

   double time_spent = 0.0;
   clock_t begin = clock();

   hsort(arr,n);
   parr(arr,n);

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds", time_spent);*/
   return 0;
}