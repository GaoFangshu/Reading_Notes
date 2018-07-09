# include <stdio.h>

# define N 5 /* a tab for every N columns */

void detab(int n);

main() {
    detab(N);
    return 0;
}

void detab(int n) {
    int c;
    int i; 
    int j;

    j = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            while (j<n) {
                ++j;
                putchar(' ');
            }
            j = 0;  /* clear */
        } else if (c == '\n') {
            j = 0;  /* clear */
        } else {
            ++j;
            putchar(c);
        } 
    }
}

