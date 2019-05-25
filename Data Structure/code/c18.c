#include <stdio.h>
#include <stdlib.h>

#define INF 10000
#define MAXN 100

typedef struct GNode *PtrToGNode;
struct GNode {
    int Data[MAXN+1][MAXN+1];
    int Nv;
    int Ne;
};
typedef PtrToGNode Graph;
typedef PtrToGNode DistGraph;

Graph read(int N, int M);
DistGraph Floyd(Graph g);
void take(DistGraph gd);
void printg(Graph g);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    Graph g = read(N, M);
    DistGraph gd = Floyd(g);
    take(gd);
    free(g);
    free(gd);
    return 0;
}

Graph read(int N, int M){
    int i, j, v1, v2, d;
    Graph g = (Graph)malloc(sizeof(struct GNode));
    g->Nv = N;
    g->Ne = M;
    for (i = 1; i < N + 1; i++){
        for (j = 1; j < N + 1; j++){
            if (i == j){
                g->Data[i][j] = 0;
            } else {
                g->Data[i][j] = INF;
            }
        }
    }

    for (i = 0; i < M; i++){
        scanf("%d %d %d", &v1, &v2, &d);
        g->Data[v1][v2] = d;
        g->Data[v2][v1] = d;
    }

    /* printg(g); */

    return g;
}

DistGraph Floyd(Graph g){
    int i, j, k;
    DistGraph gd = (DistGraph)malloc(sizeof(struct GNode));
    gd->Nv = g->Nv;
    gd->Ne = g->Ne;
    for (i = 1; i < g->Nv + 1; i++){
        for (j = 1; j <g->Nv + 1; j++){
            gd->Data[i][j] = g->Data[i][j];
        }
    }

    for (k = 1; k < g->Nv + 1; k++){
        for (i = 1; i < g->Nv + 1; i++){
            for (j = 1; j <g->Nv + 1; j++){
                if (gd->Data[i][k] + gd->Data[k][j] < gd->Data[i][j]){
                    gd->Data[i][j] = gd->Data[i][k] + gd->Data[k][j];
                }
            }
        }
    }

    /* printg(gd); */

    return gd;
}

void take(DistGraph gd){
    int i, j;
    int id, minmaxd, maxd;
    minmaxd = INF;
    for (i = 1; i < gd->Nv + 1; i++){
        maxd = -1;
        for (j = 1; j < gd->Nv + 1; j++){
            if (gd->Data[i][j] == INF){
                maxd = INF;
            } else if (gd->Data[i][j] > maxd && i != j){
                maxd = gd->Data[i][j];
            }
        }
        if (minmaxd > maxd){
            minmaxd = maxd;
            id = i;
        }
    }
    if (minmaxd == INF){
        printf("0");
    } else {
        printf("%d %d", id, minmaxd);
    }
}

void printg(Graph g){
    int i, j;
    for (i = 0; i < g->Nv + 1; i++){
        for (j = 0; j < g->Nv + 1; j++){
            printf("%d ", g->Data[i][j]);
        }
        printf("\n");
    }
}
