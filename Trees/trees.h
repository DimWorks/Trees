#pragma once

typedef struct trees
{
	int key;
	struct tree *data;
	struct tree *right;
	struct tree *left;
} tree;

void create_node();