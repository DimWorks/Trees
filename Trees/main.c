#include <stdio.h>
#include <locale.h>
#include "trees.h"

#define RUS setlocale(LC_ALL, "RU");

int main()
{
	RUS
	if (search_the_node(NULL, 5) == NULL)
	{
		printf("\n������� �� ������!\n");
	}
	else
	{
		printf("\n�����!");
	}

	create_node(5, 67);

	if (search_the_node(NULL, 5) == NULL)
	{
		printf("\n������� �� ������!\n");
	}
	else
	{
		printf("\n�����!");
	}
}