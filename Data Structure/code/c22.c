/* How Long Does It Take */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define INF 10000

typedef struct QNode *PtrToQNode;
struct QNode{
    int Data[MAXN];
    int Front;
    int Rear;
};
typedef PtrToQNode Queue;

typedef struct GNode *PtrToGNode;
struct GNode{
    int G[MAXN][MAXN];
    int Nv;
    int Ne;
};
typedef PtrToGNode Graph;

void enqueue(int v, Queue q);
int dequeue(Queue q);
int maxl(int N, int list[]);

int main(){
    int N, M, i, j, v;
    int start, end, time;
    int indegree[MAXN] = {0};
    int totaltime[MAXN] = {0};
    int cnt = 0;
    scanf("%d %d", &N, &M);

    Graph g = (Graph)malloc(sizeof(struct GNode));
    g->Nv = N;
    g->Ne = M;

    for (i = 0; i < g->Nv; i++){
        for (j = 0; j < g->Nv; j++){
            g->G[i][j] = INF;
        }
    }

    for (i = 0; i < g->Ne; i++){
        scanf("%d %d %d", &start, &end, &time);
        g->G[start][end] = time;
        indegree[end]++;
    }

    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->Front = 0;
    q->Rear = 0;

    for (i = 0; i < g->Nv; i++){
        if (indegree[i] == 0){
            enqueue(i, q);
        }
    }

    while (q->Front != q->Rear){
        v = dequeue(q);
        cnt++;
        for (i = 0; i < g->Nv; i++){
            if (g->G[v][i] != INF) {
                if (totaltime[v] + g->G[v][i] > totaltime[i]){
                    totaltime[i] = totaltime[v] + g->G[v][i];
                }
                if (--indegree[i] == 0) {
                    enqueue(i, q);
                }
            }
        }
    }

    if (cnt != g->Nv){
        printf("Impossible");
    } else {
        printf("%d", maxl(g->Nv, totaltime));
    }

    free(g);
    free(q);

    return 0;
}

void enqueue(int v, Queue q){
    q->Data[q->Rear] = v;
    q->Rear++;
}

int dequeue(Queue q){
    int v = q->Data[q->Front];
    q->Front++;
    return v;
}

int maxl(int N, int list[]){
    int i;
    int m = 0;
    for (i = 0; i < N; i++){
        if (list[i] > m){
            m = list[i];
        }
    }
    return m;
}
