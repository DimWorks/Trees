#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trees.h"

#define RUS setlocale(LC_ALL, "RU");

node* ROOT = NULL;

node* search_the_node(node* tree, int key)
{
	if (tree == NULL) return NULL;
	if (tree->key == key)
	{
		return tree;
	}
	else
	{
		search_the_node(tree->left, key);
		search_the_node(tree->right, key);
	}
}

node* finde_parend(node* parent, int key)
{
	if (key < parent->key)
	{
		if (parent->left != NULL)
		{
			finde_parend(parent->left, key);
		}
		else
		{
			return parent;
		}
	}
	else
	{
		if (parent->right != NULL)
		{
			finde_parend(parent->right, key);
		}
		else
		{
			return parent;
		}
	}


	//if (parent->left != NULL)
	//{
	//	if (key < parent->key)
	//	{
	//		finde_parend(parent->left, key);
	//	}
	//	
	//}	
	//if (parent->right != NULL)
	//{
	//	if (key >= parent->key)
	//	{
	//		finde_parend(parent->right, key);
	//	}
	//	//finde_parend(parent->right, key);
	//}
	//else
	//{
	//	return parent;
	//}
}

void create_node(int key, int data)
{
	node* tree = NULL;
		if ((tree = (node*)malloc(sizeof(node))))
		{
			tree->data = data;
			tree->key = key;
			tree->left = tree->right = NULL;
			if (ROOT != NULL)
			{
				node* parent = finde_parend(ROOT, key);

				tree->parent = parent;

				if (key < parent->key)
				{
					parent->left = tree;
				}
				else
				{
					parent->right = tree;
				}
			}
			else
			{
				tree->left = tree->right = tree->parent = NULL;
				ROOT = tree;
			}
		}
		else
		{
			printf("Недостаточно памяти. Невозможно создать узел.\n");
		}
}

node* get_max(node* tree)
{
	RUS 

	if (tree == NULL)
	{
		printf("Дерева не существует!\n");
		return;
	}
	if (tree->right == NULL)
	{
		return tree;
	}
	return(get_max(tree->right));
}

node* get_min(node* tree)
{
	RUS

	if (tree == NULL)
	{
		printf("Дерева не существует!\n");
		return;
	}
	if (tree->left == NULL)
	{
		return tree;
	}
	return(get_max(tree->left));
}

void showLine(char* c, int p, int s) {
	int t = s; 
	for (int i = 0; i < p; i++) 
	{ 
		printf(t & 1 ? "|  " : "   "); 
		t /= 2; 
	} 
	printf(c);
}
void showTree(node* tree, int p, int s)
{
	if (tree == NULL)
	{
		return;
	}
		
	printf("%d", tree->data); 
	printf("\n");

	if (tree->left != NULL) {
		showLine("|\n", p, s); 
		showLine("L: ", p, s);
		showTree(tree->left, p + 1, s + ((tree->right == NULL ? 0 : 1) << p));
	}
	if (tree->right != NULL) {
		showLine("|\n", p, s); 
		showLine("R: ", p, s);
		showTree(tree->right, p + 1, s);
	}
}