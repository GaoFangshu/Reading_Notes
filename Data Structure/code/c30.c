#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 11
#define MAXN 100000
#define HASHP 200003

typedef struct Node *PtrToNode;
struct Node {
    char Number[LENGTH];
    int Count;
    PtrToNode Next;
};
typedef PtrToNode Phone;

int same = 1;

void take(Phone hashtable[], Phone result);
void insert(Phone p, Phone start, Phone result);
int getlast(char number[]);
void takemax(Phone p, Phone result);

int main(){
    int N, i;

    Phone hashtable[HASHP];
    for (i = 0; i < HASHP; i++){
        hashtable[i] = (Phone)malloc(sizeof(struct Node));
    }

    Phone result = (Phone)malloc(sizeof(struct Node));
    for (i = 0; i < LENGTH; i++){
        result->Number[i] = '9';
    }

    result->Count = 0;

    scanf("%d\n", &N);

    for (i = 0; i < N; i++){
        take(hashtable, result);
        take(hashtable, result);
    }

    if (same > 1){
        printf("%s %d %d", result->Number, result->Count, same);
    } else {
        printf("%s %d", result->Number, result->Count);
    }

    free(result);

    return 0;
}

void take(Phone hashtable[], Phone result){
    int last;
    Phone p = (Phone)malloc(sizeof(struct Node));
    scanf("%s", &p->Number);
    p->Count = 1;
    last = getlast(p->Number);
    insert(p, hashtable[last % HASHP], result);
}

void insert(Phone p, Phone start, Phone result){
    if (strcmp(p->Number, start->Number) != 0){
        if (start->Next == NULL){
            start->Next = p;
            takemax(p, result);
        } else {
            insert(p, start->Next, result);
        }
    } else {
        start->Count++;
        takemax(start, result);
        free(p);
    }
}

int getlast(char number[]){
    int last = 0;
    last += atoi(&number[10]);
    last += atoi(&number[9]) * 10;
    last += atoi(&number[8]) * 100;
    last += atoi(&number[7]) * 1000;
    last += atoi(&number[6]) * 10000;
    return last;
}

void takemax(Phone p, Phone result){
    if (p->Count > result->Count){
        int i;
        for (i = 0; i < LENGTH; i++){
            result->Number[i] = p->Number[i];
        }
        result->Count = p->Count;
        same = 1;
    } else if (p->Count == result->Count){
        same++;
        if (strcmp(&p->Number, &result->Number) < 0) {
            int i;
            for (i = 0; i < LENGTH; i++){
                result->Number[i] = p->Number[i];
            }
            result->Count = p->Count;
        }
    }
}
