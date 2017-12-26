// Hrishikesh Kulkarni  miniature interpreter

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"
#include "ast.h"

int main(int argc, char **argv)
{
	FILE *fp = assert_fopen (argv[1], "r");
	struct node *root;

	while ((root = getnode (fp)) != NULL)
	{
		char value[10];
		strcpy(value,eval(root));
		if (strcmp(value,"-1") != 0)
			printf ("%d\n", num(value));
	}

	fclose(fp);
	return 0;
}
