# Chapter 1
## 1.1
### Exercise 1-2
``` C
#include <stdio.h>

main()
{
    printf("hello world\n");
    printf("hello world\c");
}
```
Ouput:
``` C
test.c: In function ‘main’:
test.c:6:12: warning: unknown escape sequence: '\c'
     printf("hello world\c");
            ^
hello world
hello worldc
```
## 1.2
int(16):-32768 ~ +32767

float(32):10^(-38) ~ 10^(+38)

When `int` divide `int`, **truncation** happens. Thus we delay the dividing operation.
``` C
celsius = 5 * (fahr-32) / 9
```
rather than
``` C
/* 5 / 9 = 0 */
celsius = 5 / 9 * (fahr-32)
/* float celsius, fahr; */
celsius = 5.0 / 9.0 * (fahr-32.0)
```

## 1.5
### Exercise 1-7
``` C
# include <stdio.h>

main()
{
    printf("%d\n", EOF);
}

/* Do not use `printf(EOF)` */
```
Output:
```
-1
```

`'\n'` is one character, and has type `int` (ASCII = 10). But `"\n"` is a string which contains one character.

### Exercise 1-10
``` C
# include <stdio.h>

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            putchar("\\t");
        else if (c == '\b')
            putchar("\\b");
        else if (c == '\')
            putchar("\\");
        else
            putchar(c);
    }
    return 0;
}
```

### Exercise 1-20 [[code]](./code/ex_01_10.c)
``` C
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
```

Input:
```
	1234	123	12	1	12345	1
```

Output:
```
     1234 123  12   1    123451
```

Note that when we input a line, actually we are always in the `while ((c = getchar()) != EOF) {}` loop. Thus, we should reset `j` to `0` in the while-loop rather than outside.
