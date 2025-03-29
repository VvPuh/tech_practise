#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct tree {
	int info;
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

int fill_tree(struct tree* Current)
{
	int info = 0;

	if (!(scanf("%d", &info))) return 1;
	Current->info = info;
	if (Current->Left) if (fill_tree(Current->Left)) return 1;
	if (Current->Right) if (fill_tree(Current->Right)) return 1;

	return 0;
}

int count_tops(struct tree* Current, int info)
{
	int sum = 0;
	if (Current->info == info) sum = 1;
	if (Current->Left) sum += count_tops(Current->Left, info);
	if (Current->Right) sum += count_tops(Current->Right, info);
	return sum;
}

int count_tops_on_level(struct tree* Current,int info, int level)
{
	int sum = 0;
	if (level == info) return 1;
	if (level > info) return 0;
	if (Current->Left) sum += count_tops_on_level(Current->Left, info, level+1);
	if (Current->Right) sum += count_tops_on_level(Current->Right, info, level + 1);
	return sum;
}

struct tree* find_max(struct tree* Current, int level)
{
	struct tree* Right, * Left,* Return;
	Return = Right = Left = NULL;
	if (Current->Left) Left = find_max(Current->Left, 1);
	if (Current->Right) Right = find_max(Current->Right, 1);
	//
	if ((!(Current->Left) && !(Current->Right))) return NULL;
	if (level) Return = Current;
	if (Left)
	{
		if (Return)
		{
			if (Return->info < Left->info) Return = Left;
		}
		else Return = Left;
	}
	if (Right)
	{
		if (Return)
		{
			if (Return->info < Right->info) Return = Right;
		}
		else Return = Right;
	}
	
	return Return;
}

void print_tree(struct tree* Current)
{
	printf("%d", Current->info);
	if (Current->Left)
	{
		printf("(");
		print_tree(Current->Left);
		if (Current->Right)
		{
			printf(",");
			print_tree(Current->Right);
		}
		printf(")");
	}
	else if (Current->Right)
	{
		printf("(");
		print_tree(Current->Right);
		printf(")");
	}
	return;
}

int main()
{
	struct tree* First = NULL, *Max;
	int info = 0, height;

	scanf("%d", &info);
	if (info == 0)
	{
		printf("0\n0\nnot found\n");
		return 0;
	}
	else if (info != 1) return 0;

	First = malloc(sizeof(struct tree));
	if (!First) return 0;
	if (make_tree(First))
	{
		free_tree(First);
		return 0;
	}

	if (fill_tree(First))
	{
		free_tree(First);
		return 0;
	}

	if (!(scanf("%d", &info)))
	{
		free_tree(First);
		return 0;
	}

	printf("%d\n", count_tops(First, info));
	printf("%d\n", count_tops_on_level(First, info, 0));
	Max = find_max(First, 0);
	if (Max) printf("%d\n", Max->info);
	else printf("not found\n");
	print_tree(First);

	free_tree(First);
	return 0;
}