# Chapter 1
## 1.1
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
test.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
test.c: In function ‘main’:
test.c:6:12: warning: unknown escape sequence: '\c'
     printf("hello world\c");
            ^
hello world
hello worldc
```