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
		printf("\nЭлемент не найден!\n");
	}
	else
	{
		printf("\nНашёл!");
	}

	for (int i = 0; i < 10; i++)
	{
		create_node((i % 2) == 0 ? i : i * (-1), i);
		printf("-----------------------------------\n");
		printf("%d   %d    done\n", (i%2) == 0 ? i : i * (-1), i);
		printf("-----------------------------------\n");
		showTree(ROOT, 0, 0);
	}

	create_node(6, 6);
	create_node(15, 15);
	create_node(-6, 6);



	

	if (search_the_node(ROOT, 8) == NULL)
	{
		printf("\nЭлемент не найден!\n");
	}
	else
	{
		printf("\nНашёл!\n");
	}

	showTree(ROOT, 0, 0);

}