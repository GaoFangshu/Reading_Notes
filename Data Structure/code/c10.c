/* Root of AVL Tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *PtrToNode;
typedef PtrToNode Tree;
struct AVLNode {
    int Data;
    Tree Left;
    Tree Right;
    int Height;
};

Tree insert(int d, Tree t);
int getheight(Tree t);
int getmax(int a, int b);
Tree rotateL(Tree t);
Tree rotateR(Tree t);
Tree rotateLR(Tree t);
Tree rotateRL(Tree t);

int main(){
    int N, i, d;
    Tree t = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &d);
        t = insert(d, t);
    }

    printf("%d", t->Data);

    return 0;
}

Tree insert(int d, Tree t){
    if (t == NULL){
        Tree node = (Tree)malloc(sizeof(struct AVLNode));
        node->Height = 1;
        node->Data = d;
        node->Left = NULL;
        node->Right = NULL;
        return node;
    } else {
        if (d < t->Data){ /* insert to left subtree of t */
            t->Left = insert(d, t->Left);
            if (getheight(t->Left) - getheight(t->Right) == 2){
                if (d < t->Left->Data){ /* LL */
                    t = rotateL(t);
                } else if (d > t->Left->Data){ /* LR */
                    t = rotateLR(t);
                }
            }
        } else if (d > t->Data){ /* insert to right subtree of t */
            t->Right = insert(d, t->Right);
            if (getheight(t->Right) - getheight(t->Left) == 2){
                if (d > t->Right->Data){ /* RR */
                    t = rotateR(t);
                } else if (d < t->Right->Data){ /* RL */
                    t = rotateRL(t);
                }
            }
        }
    }

    t->Height = getheight(t);

    return t;
}

int getheight(Tree t){
    if (t == NULL){
        return 0;
    } else if (t->Left == NULL && t->Right==NULL){
        return 1;
    } else {
        return getmax(getheight(t->Left), getheight(t->Right)) + 1;
    }
}

int getmax(int a, int b){
    return a >= b ? a : b;
}

Tree rotateL(Tree t){
    /*  t
       /
      A    =>  A
     /        / \
    B        B   t   */

    Tree A = t->Left;
    t->Left = A->Right;
    A->Right = t;

    t->Height = getheight(t);
    A->Height = getheight(A);
    return A;
}

Tree rotateR(Tree t){
    /*  t
         \
          A  =>  A
           \    / \
            B  t   B */
    Tree A = t->Right;
    t->Right = A->Left;
    A->Left = t;

    t->Height = getheight(t);
    A->Height = getheight(A);
    return A;
}

Tree rotateLR(Tree t){
    /*  t       t
       /       /
      A   =>  B  =>  B
       \     /      / \
        B   A      A   t */
    t->Left = rotateR(t->Left);
    return rotateL(t);
}

Tree rotateRL(Tree t){
    /* t    t
        \    \
         A => B  =>  B
        /      \    / \
       B        A  t   A */
    t->Right = rotateL(t->Right);
    return rotateR(t);
}
