# include <stdio.h>

# define MAXLINE 10 /* max colunm for each line */
# define MAXTEXT 500 /* max colunm for each input */

int textstart = 0;
char line[MAXLINE];
char text[MAXTEXT];

void getlines(void);
void divideline(void);

main() {
    getlines();
    return 0;
}

/* read characters until the `line` is full */
void getlines(void) {
    extern int textstart;
    extern char line[];
    extern char text[];
    int at = 0;
    int c, i, j;

    while ((c = getchar()) != EOF && c != '\n' && at <= MAXTEXT) {
        text[at] = c;
        ++at;
    }

    for (i = 0; i < MAXLINE; ++i) {
        line[i] = text[i];
    }

    while (line[0] != '\0') {
        divideline();
        for (i = textstart; i < textstart + MAXLINE; ++i) {
            line[i - textstart] = text[i];
        }
    }
}

/* divide line */
void divideline(void) {
    extern char line[];
    extern int textstart;
    int i = MAXLINE-1;
    int go = 1;
    int end = MAXLINE-1;
    int j, k;

    while (go && i >= 0) {
        if (line[i] == '\t' || line[i] == ' ') {
            line[i] = '\n';
            go = 0;
            end = i;
        } else {
            --i;
        }
    }

    for (j = 0; j <= end; ++j) {
        putchar(line[j]);
        ++textstart;
    }

    for (j = 0; j < MAXLINE; ++j) {
        line[j] = '\0';
    }
}
