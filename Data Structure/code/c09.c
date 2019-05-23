/* Same BST */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrToTreeNode;
struct TreeNode {
    int Data;
    PtrToTreeNode Left;
    PtrToTreeNode Right;
};
typedef PtrToTreeNode Tree;

Tree insert(int d, Tree t);
int issame(Tree t1, Tree t2);

int main(){
    int N, L, n, l, d;
    Tree t0, t1;
    int ctn = 1;

    scanf("%d %d", &N, &L);
    while (ctn){
        t0 = NULL;
        for (n = 0; n < N; n++){
            scanf("%d", &d);
            t0 = insert(d, t0);
        }
        for (l = 0; l < L; l++){
            t1 = NULL;
            for (n = 0; n < N; n++){
                scanf("%d", &d);
                t1 = insert(d, t1);
            }
            if (issame(t0, t1) == 1){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        scanf("%d", &N);
        if (N){
            scanf("%d", &L);
        } else {
            ctn=0;
        }
    }

    return 0;
}

Tree insert(int d, Tree t){
    if (t == NULL){
        Tree node = (Tree)malloc(sizeof(struct TreeNode));
        node->Data = d;
        node->Left = NULL;
        node->Right = NULL;
        return node;
    } else {
        if (d < t->Data){
            t->Left = insert(d, t->Left);
        } else if (d > t->Data){
            t->Right = insert(d, t->Right);
        }
    }
}

int issame(Tree t1, Tree t2){
    if (t1 == NULL && t2 == NULL){
        return 1;
    }
    if (t1 == NULL && t2 != NULL){
        return 0;
    }
    if (t1 != NULL && t2 == NULL){
        return 0;
    }
    if (t1->Data != t2->Data){
        return 0;
    }
    if (t1->Left == NULL && t2->Left == NULL){
        return issame(t1->Right, t2->Right);
    } else if (t1->Left != NULL && t2->Left != NULL && t1->Left->Data == t2->Left->Data){
        return (issame(t1->Left, t2->Left) && issame(t1->Right, t2->Right));
    } else {
        return 0;
    }
}
