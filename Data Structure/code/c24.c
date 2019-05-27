/* Merge Sort Test */

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

void merge_sort(ElementType input[], int N);
void msort(ElementType input[], ElementType temp[], int left, int rightend);
void merge(ElementType input[], ElementType temp[], int left, int right, int rightend);

int main(){
    int N, i;
    scanf("%d", &N);
    ElementType input[N];

    for (i = 0; i < N; i++){
        scanf("%d", &input[i]);
    }

    merge_sort(input, N);

    return 0;
}

void merge_sort(ElementType input[], int N){
    int i;
    ElementType *tempPtr;
    tempPtr = (ElementType *)malloc(N * sizeof(ElementType));

    if (tempPtr != NULL) {
        msort(input, tempPtr, 0, N - 1);
        for (i = 0; i < N; i++){
            printf("%d", input[i]);
            if (i < N-1) {
                printf(" ");
            }
        }
        free(tempPtr);
    } else {
        printf("Not enough memory.");
    }
}

void msort(ElementType input[], ElementType temp[], int left, int rightend){
    int len, newleft;
    for (len = 1; len <= rightend - left + 1; len *= 2){
        for (newleft = left; newleft < rightend; newleft += 2 * len){
            if (newleft + len - 1 < rightend && newleft + len * 2 - 1 > rightend){
                merge(input, temp, newleft, newleft + len, rightend);
            } else if (newleft + len * 2 - 1 <= rightend){
                merge(input, temp, newleft, newleft + len, newleft + len * 2 - 1);
            }
        }
    }
}

void merge(ElementType input[], ElementType temp[], int left, int right, int rightend){
    int newleft, newright, i;
    newleft = left;
    newright = right;
    i = left;

    /* copy and merge*/
    while (newleft < right && newright <= rightend){
        if (input[newleft] <= input[newright]){
            temp[i++] = input[newleft++];
        } else {
            temp[i++] = input[newright++];
        }
    }

    while (newleft < right){
        temp[i++] = input[newleft++];
    }

    while (newright <= rightend){
        temp[i++] = input[newright++];
    }

    /* overwrite */
    for (i = left; i <= rightend; i++){
        input[i] = temp[i];
    }
}
