# include <stdio.h>
# include <ctype.h>
# define MAXLINE 32 

void atos(int s[]);

main() {
	while (1) {
		int c, i, dot, s[MAXLINE];
		i = 0;
		dot = 0;
		while ((c=getchar()) != EOF && c != '\n') {
			if (c == '.')
				dot = 1;
			s[i++] = c;
		}

		if (dot == 0) {
			s[i++] = '.';
		}
		while (i < MAXLINE) {
			s[i++] = '\0';
		}

		atos(s);
	}

	return 0;
}

void atos(int s[]) {
	int i, j, k, p, sign, move;
	for (i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? '-' : '\0';
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (j = i; s[j] != '.'; ++j)
		;
	for (k = i; s[k] - '0' == 0 || s[k] == '.'; ++k)
		;
	if (k > j) {
		move = j - k;
	} else {
		move = j - k - 1;
	}
	if (s[k] == '\0') {
		putchar('0');
	} else {
		putchar(sign);
		for (p = 0; k < MAXLINE; ++k, ++p) {
			if (p == 1) putchar('.');
			if isdigit(s[k]) putchar(s[k]);
		}
		putchar('e');
		printf("%i\n", move);
	}
}