/*
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
	if (Current->Left) free_tree(Current->Left);
	free(Current);
	return;
}

int make_tree(struct tree* Current)
{
	int info;
	char dot;

	Current->Left = Current->Right = NULL;
	if (scanf("%d", &info))
	{
		if (info == 1)
		{
			Current->Left = malloc(sizeof(struct tree));
			if (!(Current->Left)) return 1;
			if (make_tree(Current->Left)) return 1;
		}
		else if (info == 0);
		else return 1;
	}
	else return 1;
	if (scanf("%d", &info))
	{
		if (info == 1)
		{
			Current->Right = malloc(sizeof(struct tree));
			if (!(Current->Right)) return 1;
			if (make_tree(Current->Right)) return 1;
		}
		else if (info == 0);
		else return 1;
	}
	else return 1;

	return 0;
}

int count_tops(struct tree* Current)
{
	int sum = 1;
	if (Current->Left) sum += count_tops(Current->Left);
	if (Current->Right) sum += count_tops(Current->Right);
	return sum;
}

int count_leaves(struct tree* Current)
{
	int sum = 0;
	if (Current->Left) sum += count_leaves(Current->Left);
	else if (!(Current->Right)) return 1;
	if (Current->Right) sum += count_leaves(Current->Right);
	return sum;
}

int find_height(struct tree* Current)
{
	int height_left, height_right;
	height_left = height_right = 0;
	if (Current->Left) height_left = 1 + find_height(Current->Left);
	if (Current->Right) height_right = 1 + find_height(Current->Right);
	if (height_left > height_right) return height_left;
	else return height_right;
}

int left_daughters(struct tree* Current)
{
	int sum = 0;
	if (Current->Left) sum += 1 + left_daughters(Current->Left);
	if (Current->Right) sum += left_daughters(Current->Right);
	return sum;
}

int main()
{
	struct tree* First = NULL;
	int info = 0;

	scanf("%d", &info);
	if (info != 1) return 0;

	First = malloc(sizeof(struct tree));
	if (!First) return 0;
	if (make_tree(First))
	{
		free_tree(First);
		return 0;
	}

	printf("%d\n", count_tops(First));
	printf("%d\n", count_leaves(First));
	printf("%d\n", find_height(First));
	printf("%d", left_daughters(First));

	free_tree(First);
	return 0;
}
*/