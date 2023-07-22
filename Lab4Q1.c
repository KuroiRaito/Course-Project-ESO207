#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<math.h>

int min(int a,int b){
if (a<b) return a;
else return b;
}

void merge(int arr[], int left,int mid, int right)
{
    // int mid = (left+right)/2;
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

void mergesort(int arr[], int n){

for (int len=1;len<n ; len*=2)
{
	for (int left=0; left<n-1; left+= 2*len)
	{
		int mid = min(left+len-1, n-1);
		int right = min(left+ 2*len-1,n-1);
		merge(arr,left,mid, right);
	}
}
}


struct QNode {
    int key;
    struct QNode* next;
};
 
struct Queue {
    struct QNode *front, *rear;
};
 
struct QNode* newNode(int k)
{
    struct QNode* temp
        = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
struct Queue* createQueue()
{
    struct Queue* q
        = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
void enQueue(struct Queue* q, int k)
{
    struct QNode* temp = newNode(k);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    q->rear->next = temp;
    q->rear = temp;
}
 
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
 
    struct QNode* temp = q->front;
 
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

void sortque(struct Queue* q, int size){
    
    int brr[size];
    int len = size;
    
    for(int i=0; i<len; i++) {
        brr[i] = q->front->key;
        deQueue(q);
    }
    
    mergesort(brr, size);
    
    for(int i=0; i<size; i++) enQueue(q,brr[i]);
    
}


int main()
{
    {
    int n,min, max, randomNum;
    scanf("%d %d %d", &min,&max,&n);
    int arr[n];
    srand(time(0));
    arr[0] = rand() % (max - min + 1) + min;
    for(int i=1;i<n;i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
        if (arr[i-1]==arr[i]) arr[i] ++;
    }
    
    int maxval=arr[0];
    
    for(int i=1; i<n; i++) if (maxval<arr[i]) maxval = arr[i];
    maxval++;
    
    double time_spent = 0.0;
    clock_t begin = clock();

    int k =20;
    struct Queue* q[k];
    int size[k];
    for(int i=0; i<k; i++) size[i]=0;
    
    for(int i=0; i<k; i++) q[i] = createQueue();
    
    for(int i=0;i<n;i++)
    {
        int index=k*arr[i]/maxval;
        enQueue(q[index],arr[i]);
        size[index]++;
    }
    
    for(int i=0; i<k; i++){
        sortque(q[i],size[i]);
    } 
int index=0;
    for(int i=0; i<k; i++){
        while(size[i]--){
            arr[index] = q[i]->front->key;
            deQueue(q[i]);
            index++;
        }
    }
   for(int i=0; i<n; i++) printf("%d ",arr[i]); 

    clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

}
   
   {
    int n,min, max, randomNum;
    scanf("%d %d %d", &min,&max,&n);
    int arr[n];
    srand(time(0));
    arr[0] = rand() % (max - min + 1) + min;
    for(int i=1;i<n;i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
        if (arr[i-1]==arr[i]) arr[i] ++;
    }

double time_spent = 0.0;
clock_t begin = clock();
mergesort(arr,n);

for(int i=0; i<n; i++) printf("%d ",arr[i]); 

clock_t end= clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
  }

}