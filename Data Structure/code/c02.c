/* Maximum Subsequence Sum */

#include <stdio.h>

int main(){
    int N, i, v, max_sum, this_sum, first, max_first, max_last, have_first, list_first, list_last, all_negative;

    scanf("%d", &N);

    max_sum=this_sum=have_first=0;
    all_negative=1;
    for (i=0; i<N; i++){
        scanf("%d", &v);

        if (i==0) {
            list_first=v;
        }
        if (i==N-1){
            list_last=v;
        }

        if (v>=0) {
            all_negative=0;
        }

        if (have_first==0){
            first=v;
            have_first=1;
        }

        this_sum+=v;

        if (this_sum>max_sum){
            max_sum=this_sum;
            max_first=first;
            max_last=v;
        } else if (this_sum<0){
            this_sum=0;
            have_first=0;
        }
    }

    if (all_negative==0) {
        printf("%d %d %d", max_sum, max_first, max_last);
    } else {
        printf("%d %d %d", 0, list_first, list_last);
    }

    return 0;
}

