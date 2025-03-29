/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List {
	int info;
	struct List* past;
	struct List* next;
};

void free_list(struct List* First)
{
	struct List* Current, * Past;

	//singl el list
	if (First->next == First)
	{
		free(First);
		return;
	}

	//free all
	(First->past)->next = NULL;
	for (First = First->next;First->next; First = First->next) free(First->past);
	free(First);

	return;
}

void print_list(struct List* First)
{
	struct List* Current;
	for (Current = First;Current->next != First;Current = Current->next) printf("%d ", Current->info);
	printf("%d\n", Current->info);
	for (Current = First->past;Current != First;Current = Current->past) printf("%d ", Current->info);
	printf("%d\n", Current->info);
	return;
}

struct List* only_one(struct List* First, int k, int n)
{
	struct List* Current;
	int i;

	//find k el
	if (First->info != k)
	{
		for (Current = First->next; Current != First; Current = Current->next)
		{
			if (Current->info == k)
			{
				First = Current;
				break;
			}
		}
	}
	//no k el
	if (First->info != k)
	{
		printf("not found");
		free_list(First);
		return NULL;
	}

	if (n % 2)	First = First->past;
	else First = First->next;
	//del
	while (First != First->next)
	{
		if (n % 2)
		{
			for (i = 1; i < n; i++, First = First->past);
			(First->next)->past = First->past;
			(First->past)->next = First->next;
			Current = First;
			First = First->past;
			free(Current);
		}
		else
		{
			for (i = 1; i < n; i++, First = First->next);
			(First->next)->past = First->past;
			(First->past)->next = First->next;
			Current = First;
			First = First->next;
			free(Current);
		}
	}
	return First;
}

int main()
{
	struct List* First, * Current;
	int info, k, n;
	char dot;

	First = Current = NULL;
	while (scanf("%d", &info))
	{
		if (!First)
		{
			First = malloc(sizeof(struct List));
			if (!First) return 0;
			First->past = First->next = NULL;
			First->info = info;
			Current = First;
			continue;
		}
		Current->next = malloc(sizeof(struct List));
		if (!(Current->next))
		{
			Current->next = First;
			First->past = Current;
			free_list(First);
			return 0;
		}
		(Current->next)->past = Current;
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
	First->past = Current;
	scanf("%c", &dot);
	//no end el
	if (dot != '.')
	{
		free_list(First);
		return 0;
	}
	//no k
	if (!(scanf("%d", &k)))
	{
		free_list(First);
		return 0;
	}
	//no n
	if (!(scanf("%d", &n)))
	{
		free_list(First);
		return 0;
	}
	if(n<1)
	{
		free_list(First);
		return 0;
	}

	print_list(First);

	First = only_one(First, k, n);
	if (!First) return 0;
	printf("%d", First->info);
	free(First);
	return 0;
}
*/