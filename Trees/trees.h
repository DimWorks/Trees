#pragma once

typedef struct trees
{
	int key;
	int data;
	struct node* right;
	struct node* left;
	struct node* parent;
} node;

node* search_the_node(node* tree, int key);
void add_the_node(node* tree, int key, int data);
void create_node(int key, int data);