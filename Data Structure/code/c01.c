/* Maximum Subsequence Sum */

#include <stdio.h>

int main(){
    int N, i, v, max_sum, this_sum;

    scanf("%d", &N);

    max_sum=this_sum=0;
    for (i=0; i<N; i++){
        scanf("%d", &v);
        this_sum+=v;
        if (this_sum<0){
            this_sum=0;
        }
        else if (this_sum>max_sum){
            max_sum=this_sum;
        }
    }

    printf("%d", max_sum);

    return 0;
}
