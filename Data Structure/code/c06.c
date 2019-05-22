/* Isomorphic trees */

#include <stdio.h>

#define MAXN 10
#define Null -1
#define ElementType char
#define Tree int

struct TreeNode {
    ElementType Data;
    Tree Left;
    Tree Right;
} t1[MAXN], t2[MAXN];

Tree read(struct TreeNode t[]);
int isomorphic(Tree root1, Tree root2);

int main(){
    Tree root1, root2;
    root1 = read(t1);
    root2 = read(t2);

    if (isomorphic(root1, root2)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}

Tree read(struct TreeNode t[]){
    Tree root;
    int N, i;
    char left, right;
    int haveparent[MAXN];

    scanf("%d\n", &N);

    if (!N){
        return Null;
    }

    if (N){
        for (i = 0; i < N; i++){
            haveparent[i] = 0;
        }
        for (i = 0; i < N; i++){
            scanf("%c %c %c\n", &t[i].Data, &left, &right);
            if (left != '-'){
                t[i].Left = left - '0';
                haveparent[t[i].Left] = 1;
            } else {
                t[i].Left = Null;
            }
            if (right != '-'){
                t[i].Right = right - '0';
                haveparent[t[i].Right] = 1;
            } else {
                t[i].Right = Null;
            }
        }
    }
    for (i = 0; i < N; i++){
        if (haveparent[i] == 0){
            break;
        }
    }
    root = i;

    return root;
}

int isomorphic(Tree root1, Tree root2){
    if (root1 == Null && root2 == Null) {
        return 1;
    }
    if (root1 != Null && root2 == Null){
        return 0;
    }
    if (root1 == Null && root2 != Null){
        return 0;
    }
    if (t1[root1].Data != t2[root2].Data){
        return 0;
    }
    if (t1[root1].Left == Null && t2[root2].Left == Null){
        return (isomorphic(t1[root1].Right, t2[root2].Right));
    }
    if (t1[root1].Left != Null && t2[root2].Left != Null && t1[t1[root1].Left].Data == t2[t2[root2].Left].Data){
        return (isomorphic(t1[root1].Left, t2[root2].Left) && isomorphic(t1[root1].Right, t2[root2].Right));
    } else {
        return (isomorphic(t1[root1].Left, t2[root2].Right) && isomorphic(t1[root1].Right, t2[root2].Left));
    }
}
