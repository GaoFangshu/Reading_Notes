/* Reversing Linked List */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define DIM 2

typedef struct LNode *PtrToLNode;
struct LNode {
    int Start;
    int Data;
    int End;
    PtrToLNode Next;
};
typedef PtrToLNode List;

void printint(List L);
List reversek(List L, int n, int k);

int main(){
    int start_ad, n, k;
    int i, j;
    int start, end, d;
    int loc_start, loc_end;
    int data[MAXN][DIM] = {-1};
    scanf("%d %d %d", &start_ad, &n, &k);

    for (i = 0; i < n; i++){
        scanf("%d %d %d", &start, &d, &end);
        data[start][0] = d;
        data[start][1] = end;
    };

    List list0 = (List)malloc(sizeof(struct LNode));
    list0->End = start_ad;
    List list = list0;

    loc_start = start_ad;
    for (i = 0; i < n; i++){
        List list_new = (List)malloc(sizeof(struct LNode));
        loc_end = data[loc_start][1];
        list_new->Start = loc_start;
        list_new->Data = data[loc_start][0];
        list_new->End = loc_end;
        list_new->Next = NULL;
        list->Next = list_new;
        list = list->Next;
        loc_start = loc_end;
    };

    List result = reversek(list0, n, k);

    printint(result);

    return 0;
}


void printint(List L){
    List list = L->Next;
    while (list){
        if (list->End == -1){
            printf("%05d %d -1", list->Start, list->Data);
        } else {
            printf("%05d %d %05d", list->Start, list->Data, list->End);
        }
        list = list->Next;
        if (list){
            printf("\n");
        }
    }
}

List reversek(List L, int n, int k){
    int i, j;
    List list_new, temp, temp_end;
    List list_old = L;
    List list0 = (List)malloc(sizeof(struct LNode));
    List listk = list0;
    listk->Next = NULL;

    for (i = 0; i < n/k; i++){
        for (j = 0; j < k; j++){
            list_new = listk;
            temp = list_new->Next;
            list_new->Next = list_old->Next;
            list_new = list_new->Next;
            list_old->Next = list_new->Next;
            list_new->Next = temp;
            if (list_new->Next){
                list_new->End = temp->Start;
            } else {
                list_new->End = -1;
            }
            if (j == 0){
                temp_end = list_new;
            }
        }
        listk = temp_end;
    }
    if (temp){
        temp_end->End = list_old->Next->Start;
        temp_end->Next = list_old->Next;
    }

    return list0;
}
