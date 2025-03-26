#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct tree {
	struct tree* Right;
	struct tree* Left;
};

void free_tree(struct tree* Current)
{
	if (Current->Right) free_tree(Current->Right);
	if (Current->Left) free_tree(Current->Right);
	free(Current);
	return;
}

int make_tree(struct tree* First)
{
	struct tree* Current;
	int info, count;
	char dot;

	Current = NULL;
	while (scanf("%d", &info))
	{
		if (info != 1)
		{
			free_tree(First);
			return 1;
		}
		//first el
		if (!First)
		{
			First = malloc(sizeof(struct tree));
			if (!First) return 0;
			Current = First;
			First->Right = NULL;
			First->Left = NULL;
			continue;
		}

		//el
		Current->next = malloc(sizeof(struct List));
		if (!(Current->next))
		{
			Current->next = First;
			free_list(First);
			return 0;
		}
		Current = Current->next;
		Current->info = info;
	}

	//empty list
	if (!First)
	{
		printf("the list is empty");
		return 0;
	}

	Current->next = First;
	scanf("%c", &dot);
	//no end el
	if (dot != '.')
	{
		free_list(First);
		return 0;
	}

	//no stop el
	if (!scanf("%d", &info))
	{
		free_list(First);
		return 0;
	}

	//no count
	if (!scanf("%d", &count))
	{
		free_list(First);
		return 0;
	}
}