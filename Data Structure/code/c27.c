#include <stdio.h>
#include <stdlib.h>

#define MIN 0
#define MAX 50

int main(){
    int N, i, input;
    int bucket[MAX - MIN + 1] = {0};
    scanf("%d", &N);

    for (i=0; i < N; i++){
        scanf("%d", &input);
        bucket[input - MIN]++;
    }

    for (i = MIN; i < MAX - MIN + 1; i++){
        if (bucket[i] != 0){
            printf("%d:%d\n", i, bucket[i]);
        }
    }

    return 0;
}
