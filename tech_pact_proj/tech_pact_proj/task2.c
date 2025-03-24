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

	//free from first el to last el not included
	for (Past = Current = First; Current->next != First; Current = Current->next)
	{
		if (First == Current) continue;
		free(Past);
		Past = Current;
	}

	//free last el
	free(Current);

	return;
}

void re_print(struct List* First, int info)
{
	struct List* Current, * Stop = NULL;

	//single el list
	if (First->next == First)
	{
		printf("%d\n%d", First->info, First->info);
		return;
	}

	//list
	for (Current = First; Current->next != First; Current = Current->next)
	{
		if (Current->info == info)
		{
			Stop = Current;
			break;
		}
	}
	//list with last stop el
	if (Current->info == info) Stop = Current;

	//print list
	if (Stop)
	{
		for (Current = Stop; Current->next != Stop; Current = Current->next) printf("%d ", Current->info);
		printf("%d\n", Current->info);
		for (Current = Stop; Current->past != Stop; Current = Current->past) printf("%d ", Current->info);
		printf("%d", Current->info);
		return;
	}

	//list without stop el
	for (Current = First; Current->next != First; Current = Current->next) printf("%d ", Current->info);
	printf("%d\n", Current->info);
	for (Current = First->past; Current != First; Current = Current->past) printf("%d ", Current->info);
	printf("%d", Current->info);
	return;
}

int main()
{
	struct List* First, * Current;
	int info;
	char dot;

	First = Current = NULL;
	while (scanf("%d", &info))
	{
		//first el
		if (!First)
		{
			First = malloc(sizeof(struct List));
			if (!First) return 0;
			Current = First;
			First->info = info;
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
		(Current->next)->past = Current;
		Current = Current->next;
		Current->info = info;
	}

	//empty list
	if (!First)
	{
		printf("0");
		return 0;
	}

	First->past = Current;
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

	//print original list
	for (Current = First; Current->next != First; Current = Current->next) printf("%d ", Current->info);
	printf("%d\n", Current->info);

	//print reversed original list
	for (Current = First->past; Current != First; Current = Current->past) printf("%d ", Current->info);
	printf("%d\n\n", Current->info);

	//print list
	re_print(First, info);
	free_list(First);

	return 0;
}
*/