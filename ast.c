#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"
#include "symtab.h"
#include "ast.h"

struct node *
getnode (FILE *fp)
{
	//printf("chalu\n");
	char c[10];
	struct node *root;
	int i=0;
	do
	{

		do
		{
			c[i] = getc (fp);
			if (c[i] == EOF)
				return NULL;
			if(c[i]==')')
				break;
		}while(c[i]=='(' || c[i]=='\n' );
		
	
	//c[i] = (isdigit (c[i])) ? c[i] - '0' : c[i];
	
	i++;
	}while(1);
	c[i]='\0';
	root = assert_malloc (sizeof (*root));

	strcpy((root->data), c);


	if (!is_oper (c[0]) && c[0] != '=')
		return root;

	//printf("startl %c \n", c);
	root->left = getnode (fp);
	//printf("endl\n");

	//printf("startr %c \n", c);
	root->right = getnode (fp);
	//printf("endr\n");
	return root;
}

static char* val(char op[], char l[], char r[])
{
	char c ='0';
	int i;
	switch(op[0])
	{
		case '+':
			return strr(num(l) + num(r));
		case '-':
			return strr(num(l) - num(r));
		case '*':
			return strr(num(l) * num(r));
		case '/':
			return strr(num(l) / num(r));
		default:
			assert (0);
	}
	//printf("err\n");
}

char*
eval(struct node* root)
{
	//printf("%c \n", root->data);
	char left_op[10], right_op[10];

	if (is_oper ((root->data)[0]))
	{
		strcpy(left_op,eval(root->left));
		strcpy(right_op,eval(root->right));
		return val(root->data, left_op, right_op);
	}

	else if ((root->data)[0] == '=')
	{
		char id[10];
		strcpy(id,root->left->data);
		strcpy(right_op,eval(root->right));
		store (id, right_op);
		return "-1";
	}

	else if (isalpha (root->data[0]))
		return getval(root->data);

	else
		return root->data;
}

int num(char a[])
{
	int i=0;
	int v=0;
	for (i = 0; a[i]!='\n'; ++i)
	{
		v = v + a[i]*(10*(strlen(a)-i-1));
	}
	return v;
}

char a[10];
char* strr(int n)
{
	int i=0;
	while(n!=0)
	{
		a[i] = n%10;
		n = n/10; 
		i++;
	}
	a[i]='\0';
	return a;
} 
