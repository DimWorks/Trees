#pragma once

typedef struct trees
{
	int key;
	int data;
	struct node* right;
	struct node* left;
	struct node* parent;
} node;

void create_node();