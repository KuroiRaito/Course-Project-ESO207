#include <stdio.h>
#include <stdlib.h>

#define r 3     // define r-way heap
#define MAX 5000

int heap[MAX];
int size = 0;

int getParent(int index) {
    return (index - 1) / r;
}

int getKthChild(int index, int k) {
    return r * index + k;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int data) {
    if (size >= MAX) {
        printf("Heap is full\n");
        return;
    }
    heap[size] = data;
    int current = size;
    while (heap[current] < heap[getParent(current)]) {
        swap(&heap[current], &heap[getParent(current)]);
        current = getParent(current);
    }
    size++;
}

void reduceKey(int index, int newValue) {
    heap[index] = newValue;
    while (index != 0 && heap[index] < heap[getParent(index)]) {
        swap(&heap[index], &heap[getParent(index)]);
        index = getParent(index);
    }
}

void heapify(int index) {
    int smallest = index;
    for (int i = 1; i <= r; i++) {
        int child = getKthChild(index, i);
        if (child < size && heap[child] < heap[smallest]) {
            smallest = child;
        }
    }
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify(smallest);
    }
}

int deleteMin() {
    if (size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return min;
}

int main() {
    int i;
    for(i=0; i<5000; i++){
        insert(rand()%10000);
    }
    for(i=0; i<1000; i++){
        printf("%d\n", deleteMin());
    }
    return 0;
}
