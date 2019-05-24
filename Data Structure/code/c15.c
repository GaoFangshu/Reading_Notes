/* Get Connected Components */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    int G[MAXN][MAXN];
    int Visited[MAXN];
};
typedef PtrToGNode Graph;

typedef struct QNode *PtrToQNode;
struct QNode {
    int Data[MAXN];
    int Front, Rear;
};
typedef PtrToQNode Queue;

Graph readgraph(int N, int E);
void BFS(int id, Graph g);
void DFS(int id, Graph g);
int nextcomponent(Graph g);
int allvisited(Graph g);
void initvisit(Graph g);
int isedge(int v1, int v2, Graph g);

int main(){
    int N, E, v, i, j;
    scanf("%d %d", &N, &E);

    Graph g = readgraph(N, E);

    while (allvisited(g) == 0){
        v = nextcomponent(g);
        printf("{ ");
        DFS(v, g);
        printf("}\n");
    }

    initvisit(g);

    while (allvisited(g) == 0){
        v = nextcomponent(g);
        printf("{ ");
        BFS(v, g);
        printf("}\n");
    }

    free(g);

    return 0;
}

Graph readgraph(int N, int E){
    int i, j, v1, v2;
    Graph g = (Graph)malloc(sizeof(struct GNode));
    g->Nv = N;
    g->Ne = E;

    initvisit(g);
    for (i = 0; i < g->Ne; i++){
        scanf("%d %d", &v1, &v2);
        g->G[v1][v2] = 1;
        g->G[v2][v1] = 1;
    }
    return g;
}

void DFS(int v, Graph g){
    int i;
    g->Visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < g->Nv; i++){
        if (g->Visited[i] == 0 && isedge(v, i, g)){
            DFS(i, g);
        }
    }
}

void BFS(int v, Graph g){
    int cv, i;

    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->Front = q->Rear = 0;

    q->Data[0] = v;
    q->Rear += 1;
    g->Visited[v] = 1;

    while (q->Front < q->Rear){
        cv = q->Data[q->Front];

        printf("%d ", cv);
        q->Front += 1;

        for (i = 0; i < g->Nv; i++){
            if (g->Visited[i] == 0 && isedge(cv, i, g)){
                g->Visited[i] = 1;
                q->Data[q->Rear] = i;
                q->Rear += 1;
            }
        }
    }
    free(q);
}

int nextcomponent(Graph g){
    int i;
    for (i = 0; i < g->Nv; i++){
        if (g->Visited[i] == 0){
            return i;
        }
    }
}

int allvisited(Graph g){
    int i;
    for (i = 0; i < g->Nv; i++){
        if (g->Visited[i] == 0){
            return 0;
        }
    }
    return 1;
}

void initvisit(Graph g){
    int i;
    for (i = 0; i < g->Nv; i++){
        g->Visited[i] = 0;
    }
}

int isedge(int v1, int v2, Graph g){
    return g->G[v1][v2];
}
