#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtab.h"

static int symtab['z' - 'a' + 1];

char l[10][10], r[10][10];
static int i=0;  

void store(char var[], char value[])
{
	//symtab[var - 'a'] = value;	
	strcpy(l[i],var);
	strcpy(r[i],value);
	i++; 
}
int flag = 0;

char* getval(char var[])
{
	// int val = symtab[var - 'a'];
	// if (val == -1)
	// {
	// 	fprintf (stderr, "Unknown variable %c\n", var);
	// 	exit (EXIT_FAILURE);
	// }
	flag = 0;
	for (int j = 0; j < i; ++j)
	{
		if (strcmp(var, l[j])==0)
		{
			flag = 1;
			return r[i];	
		}
	}
	if (flag == 0)
	{
		fprintf (stderr, "Unknown variable %s\n", var);
	 	exit (EXIT_FAILURE);
	}
	return NULL;
}

