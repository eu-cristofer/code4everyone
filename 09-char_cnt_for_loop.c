
/*
	Sally Coder Jan 18, 2018
	modified to demonstrate for loop
    page 165 ABC4
*/

#include <stdio.h>

int main(void)
{
	int blanks = 0, digits = 0, letters = 0, others = 0, total_chars = 0;
	int c;		// use for int value of character
	for(;(c = getchar()) != EOF; total_chars++);
	{
		if (c == ' ')
			++blanks;
		else if ( c >= '0' && c <= '9')
			++digits;
		else if ( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			++letters;
		else
			++others;
	};
	printf(" blanks = %d, digits = %d , letters = %d, total chars = %d",
			 blanks, digits, letters, total_chars);
	printf(" others = %d\n\n", others);
	return 0;
};
