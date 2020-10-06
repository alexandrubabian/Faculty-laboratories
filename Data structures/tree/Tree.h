#ifndef TREE_H_D
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Link
  {
    Item  elem;
    struct Link *l;
    struct Link *r;
  } TreeNode;



void Init(TreeNode **t, Item x)
{
	(*t)=(TreeNode *)malloc(sizeof(TreeNode));
	(*t)->elem=x;
	(*t)->l=NULL;
	(*t)->r=NULL;   
}

void Insert(TreeNode **t, Item x)
{
	if(*t==NULL){
		*t=malloc(sizeof(*t));
		(*t)->elem=x;
		(*t)->l=NULL;
		(*t)->r=NULL; 
	}
	if(x<(*t)->elem)			  
		Insert(&((*t)->l),x);
	else if(x>(*t)->elem)
		Insert(&((*t)->r),x);
}

void PrintPostorder(TreeNode *t)
{
	if(t){
		PrintPostorder(t->l);
		PrintPostorder(t->r);
		printf("%d ",t->elem);
	}
}

void PrintPreorder(TreeNode *t)
{
	if(t){
		printf("%d ",t->elem);
		PrintPreorder(t->l);
		PrintPreorder(t->r);
	}
}

void PrintInorder(TreeNode *t)
{
	if(t){
		PrintInorder(t->l);
		printf("%d ",t->elem);
		PrintInorder(t->r);
	}
}

void Free(TreeNode **t)
{
	if(*t){
		Free(&(*t)->l);
		Free(&(*t)->r);
		free(*t);
		}
} 

int Size(TreeNode* t)
{
	if(t==NULL)
		return 0;
	else return(Size(t->l)+1+Size(t->r));
}


int maxDepth(TreeNode *t)
{
	int stanga,dreapta;
	if(t==NULL)
		return 0;
	stanga=maxDepth(t->l);
	dreapta=maxDepth(t->r);
	if(stanga>dreapta)
		return 1+stanga;
	else return 1+dreapta;
}

#endif // LINKEDSTACK_H_INCLUDED
