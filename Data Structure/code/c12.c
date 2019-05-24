/* Path in Heap */

#include <stdio.h>
#include <stdlib.h>

#define MIN -10000

typedef struct HNode *Heap;
struct HNode {
    int *Data;
    int Size;
    int Capacity;
};
typedef Heap MinHeap;

MinHeap initheap(int N);
void insert(int d, MinHeap h);
void getpath(int id, MinHeap h);

int main(){
    int N, M, i, id;
    scanf("%d %d", &N, &M);

    MinHeap h = initheap(N);

    for (i = 0; i < M; i++){
        scanf("%d", &id);
        getpath(id, h);
    }

    return 0;
}

MinHeap initheap(int N){
    int i, d;
    MinHeap h = (MinHeap)malloc(sizeof(struct HNode));
    h->Data = (int *)malloc((N + 1) * sizeof(int));
    h->Size = 0;
    h->Capacity = N;
    h->Data[0] = MIN;

    for (i = 0; i < N; i++){
        scanf("%d", &d);
        insert(d, h);
    }

    return h;
}

void insert(int d, MinHeap h){
    int i;

    i = ++h->Size;

    for (; h->Data[i/2] > d; i = i/2){
        h->Data[i] = h->Data[i/2];
    }
    h->Data[i] = d;
}

void getpath(int id, MinHeap h){
    while (id > 0){
        printf("%d", h->Data[id]);
        id = id / 2;
        if (id>0){
            printf(" ");
        }
    }
    printf("\n");
}

