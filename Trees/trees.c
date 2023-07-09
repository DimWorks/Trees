#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trees.h"

#define RUS setlocale(LC_ALL, "RU");

node* ROOT = NULL;

void add_the_node(node* tree, int key, int data)
{
	node* tmp = NULL;
	tmp->data = data;
	tmp->key = key;
	if (key < tree->key)
	{
		if (tree->left == NULL)
		{
			tree->left = tmp;
		}
		else
		{
			add_the_node(tree->left, key, data);
		}
	}
	else
	{
		if (tree->right == NULL)
		{
			tree->right = tmp;
		}
		else
		{
			add_the_node(tree->right, key, data);
		}
	}
}

void create_node(int key, int data)
{
	node* tmp = NULL;
		if ((tmp = (node*)malloc(sizeof(node))))
		{
			tmp->data = data;
			tmp->key = key;
			if (ROOT != NULL)
			{
				
			}
			else
			{
				tmp->left = tmp->right = tmp->parent = NULL;
				ROOT = tmp;
			}
		}
		else
		{
			printf("Недлстаточно памяти. Невозможно создать узел\n");
		}
}