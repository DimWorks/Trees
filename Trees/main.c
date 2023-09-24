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

	/*for (int i = 0; i < 10; i++)
	{
		create_node((i % 2) == 0 ? i : i * (-1), i);
		printf("%d   %d    done\n", (i%2) == 0 ? i : i * (-1), i);

	}*/

	create_node(3, 3);
	create_node(15, 15);
	create_node(2, 2);
	create_node(1, 1);
	create_node(11, 11);
	create_node(7, 7);
	create_node(5, 5);
	//create_node(6, 6);
	create_node(10, 10);
	create_node(14, 14);
	create_node(13, 13);
	create_node(4, 4);


	/*for (int i = 0; i < 10; i++)
	{
		create_node(i, i);
		printf("%d   %d    done\n", i, i);

	}	*/

	if (search_the_node(ROOT, 5) == NULL)
	{
		printf("\nЭлемент не найден!\n");
	}
	else
	{
		printf("\nНашёл!\n");
	}

	showTree(ROOT, 0, 0);

	balance(ROOT);

	delete_node(5);
	delete_node(9);

	showTree(ROOT, 0, 0);
}