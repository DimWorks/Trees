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
				node* parent = ROOT;

				while (parent->left != NULL || parent->right != NULL)
				{
					if (key < parent->key)
					{
						parent = parent->left;
					}
					else
					{
						parent = parent->right;
					}
				}

				tree->parent = parent;

				if (key < parent->key)
				{
					parent->left = tree;
				}
				else
				{
					parent->right = tree;
				}


				//while(tree != NULL) 
				//{
				//	if (key < tree->key)
				//	{
				//		if (tree->left == NULL)
				//		{
				//			tree->left = tmp;
				//			root->parent = tree;
				//		}
				//		/*else
				//		{
				//			tre = tre->left;
				//		}*/
				//	}
				//	else
				//	{
				//		if (tree->right == NULL)
				//		{
				//			tree->right = tmp;
				//			root->parent = tree;
				//			tree = tree->right;
				//			tree->right = NULL;
				//		}
				//		else
				//		{
				//			tree = tree->right;
				//			//exit(0);
				//		}
				//	}
				//}
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