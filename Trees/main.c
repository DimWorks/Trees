#include <stdio.h>
#include <locale.h>
#include "trees.h"

#define RUS setlocale(LC_ALL, "RU");

node* ROOT;

int main()
{
	RUS
	if (search_the_node(ROOT, 5) == NULL)
	{
		printf("\n������� �� ������!\n");
	}
	else
	{
		printf("\n�����!");
	}

	for (int i = 0; i < 10; i++)
	{
		create_node(i*2, i+6);
	}
	

	if (search_the_node(ROOT, 2) == NULL)
	{
		printf("\n������� �� ������!\n");
	}
	else
	{
		printf("\n�����!");
	}
}