#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "str_reverter.h"

void	test_step(char *in, char *out)
{
	char	*out_real;
	int		status;

	status = Write(in);
	printf("status: %d\n", status);
	out_real = Read();
	printf("in: 		%s\n", in);
	printf("out_real: 	%s\n", out_real);
	if (!in && !out) {
		assert(out == out_real);
	}
	else {
		assert(!strcmp(out, out_real));
	}
}

void	fill_str_and_reverse(char *str, char *reverse, int len)
{
	for (int i = 0; i < len; ++i)
	{
		str[i] = 32 + rand() % (127 - 32 + 1);
		reverse[len - 1 - i] = str[i];
	}
	str[len] = '\0';
	reverse[len] = '\0';
}

#define NTESTS 50

int main() {
	char	*in;
	char	*out;
	int		len;

	in = NULL;
	out = NULL;
	test_step(in, out);

	in = "123456789";
	out = "987654321";
	test_step(in, out);

	in = "12345678912345qwert";
	out = "trewq54321987654321";
	test_step(in, out);

	srand(time(NULL));
	for (int i = 0; i < NTESTS; ++i)
	{
		len = rand() % 50;
		printf("Test number: %d\n", i);
		in = malloc(sizeof(char) * (len + 1));
		out = malloc(sizeof(char) * (len + 1));
		fill_str_and_reverse(in, out, len);
		test_step(in, out);
		free(in);
		free(out);
	}
    return (0);
}