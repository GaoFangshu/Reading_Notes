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
