#ifndef AST_H_
#define AST_H_


struct node
{
	char data[10];
	struct node* left;
	struct node* right;
};

struct node *getnode(FILE *);
char* eval(struct node *);
int num(char []);
char* strr(int);

#endif
