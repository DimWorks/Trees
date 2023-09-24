#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trees.h"

#define RUS setlocale(LC_ALL, "RU");

node* ROOT = NULL;

node* search_the_node(node* tree, int key)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->key == key)
	{
		return tree;
	}
	else if(key < tree->key)
	{
		return search_the_node(tree->left, key);		
	}
	else
	{
		return search_the_node(tree->right, key);
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
			printf("Ќедостаточно пам€ти. Ќевозможно создать узел.\n");
		}
}

node* get_max(node* tree)
{
	RUS 

	if (tree == NULL)
	{
		printf("ƒерева не существует!\n");
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
		printf("ƒерева не существует!\n");
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

unsigned char level(node* tree)
{
	return tree ? tree->level : 0; //≈сли узел существует, возвр€щаем его уровень, иначе 0
}

int balance_faxtor(node* tree)
{
	return level(tree->right) - level(tree->left);
}

void fix_level(node* tree)
{
	unsigned char level_left = level(tree->left);
	unsigned char level_right = level(tree->right);
	tree->level = (level_left > level_right ? level_left : level_right) + 1;
}

node* rotate_to_right(node* tree)
{
	node* tmp = tree->left;
	tree->left = tmp->right;
	tmp->right = tree;
	fix_level(tree);
	fix_level(tmp);
	return tree;
}

node* rotate_to_left(node* tree)
{
	node* tmp = tree->right;
	tree->right = tmp->left;
	tmp->right = tree;
	fix_level(tmp);
	fix_level(tree);
	return tree;
}

node* balance(node* p) // балансировка узла p
{
	fix_level(p);
	if (balance_faxtor(p) == 2)
	{
		if (balance_faxtor(p->right) < 0)
			p->right = rotate_to_right(p->right);
		return rotate_to_left(p);
	}
	if (balance_faxtor(p) == -2)
	{
		if (balance_faxtor(p->left) > 0)
			p->left = rotate_to_left(p->left);
		return rotate_to_right(p);
	}
	return p; // балансировка не нужна
}

void delete_node(int key)
{
	node* root = ROOT;
	root = search_the_node(root, key);
	if (root == NULL)
	{
		return NULL;
	}	

	if (root->left == NULL || root->right == NULL)
	{
		if (root->left == NULL)
		{
			node* tmp = root->parent;
			if (key < tmp->key)
			{
				tmp->left = root->right;				
			}
			else
			{
				tmp->right = root->right;
			}
			tmp = root;
			root = root->right;
			if (tmp->right != NULL)
			{
				node* that_node = tmp->right;
				that_node->parent = tmp->parent;
			}
			if (tmp->left != NULL)
			{
				node* that_node = tmp->left;
				that_node->parent = tmp->parent;
			}
			free(tmp);
		}
		else
		{
			node* tmp = root->parent;
			if (key < tmp->key)
			{
				tmp->left = root->left;
			}
			else
			{
				tmp->right = root->left;
			}
			tmp = root;
			root = root->left;
			if (tmp->right != NULL)
			{
				node* that_node = tmp->right;
				that_node->parent = tmp->parent;
			}
			if (tmp->left != NULL)
			{
				node* that_node = tmp->left;
				that_node->parent = tmp->parent;
			}
			free(tmp);
		}
	}
	else if (root->left == NULL && root->right == NULL)
	{
		node* tmp = root->parent;
		if (key < tmp->key)
		{
			tmp->left = NULL;
			free(root);
		}
	}
	else
	{
		node* maxLeft = get_max(root->left);
		root->data = maxLeft->data;
		root->key = maxLeft->key;
		root->left = maxLeft->left;
		root->right = maxLeft->right;
		root->level = maxLeft->level;
		root->parent = maxLeft->parent;
	}
}