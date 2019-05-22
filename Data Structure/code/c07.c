/* List Leaves */

#include <stdio.h>
#include <stdlib.h>

#define Null -1
#define MAXN 10
#define Tree int
#define Position int

struct TreeNode {
    int Data;
    int Left;
    int Right;
} T[MAXN];

typedef struct QNode *PtrToSNode;
struct QNode {
    struct TreeNode *Data;
    Position Front, Rear;
};
typedef PtrToSNode Queue;

Tree read(int N);
void getleaves(int N, Tree root);
void add(Queue q, struct TreeNode node);
struct TreeNode take(Queue q);

int main(){
    Tree root;
    int N;

    scanf("%d\n", &N);
    root = read(N);

    getleaves(N, root);

    return 0;
}

Tree read(int N){
    Tree root;
    int i;
    int haveparent[MAXN];
    char left, right;

    for (i=0; i<N; i++){
        haveparent[i] = 0;
    }

    if (N){
        for (i=0; i<N; i++){
            scanf("%c %c\n", &left, &right);
            T[i].Data = i;
            if (left != '-'){
                T[i].Left = left - '0';
                haveparent[T[i].Left] = 1;
            } else {
                T[i].Left = Null;
            }
            if (right != '-'){
                T[i].Right = right - '0';
                haveparent[T[i].Right] = 1;
            } else {
                T[i].Right = Null;
            }
        }

        for (i=0; i<N; i++){
            if (haveparent[i] == 0) {
                break;
            }
        }

        root = i;

        return root;
    } else {
        return Null;
    }
}

void getleaves(int N, Tree root){
    int i, first=1;
    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->Data = (struct TreeNode *)malloc(MAXN*sizeof(struct TreeNode));
    q->Front = q->Rear = 0;

    /*
    if (root == Null){
        return Null;
    }*/

    add(q, T[root]);
    while (q->Front < q->Rear){/* queue not empty */
        struct TreeNode node = take(q);
        if (node.Left != Null){
            add(q, T[node.Left]);
        }
        if (node.Right != Null){
            add(q, T[node.Right]);
        }
        if (node.Left == Null && node.Right == Null){
            if (first){
                printf("%d", node.Data);
                first = 0;
            } else {
                printf(" %d", node.Data);
            }
        }
    }
    free(q);
}

void add(Queue q, struct TreeNode node){
    q->Data[q->Rear] = node;
    q->Rear += 1;
}

struct TreeNode take(Queue q){
    q->Front += 1;
    return q->Data[q->Front - 1];
}
