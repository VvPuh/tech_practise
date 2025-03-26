/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List {
	int info;
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

struct List* changed_list(struct List* First, int info, int count)
{
	struct List* Current, * Start;
	int counter = 0;
	Current = Start = NULL;

	//single el list
	if (First->next == First)
	{
		if (First->info == info)
		{
			free(First);
			return NULL;
		}
		else return First;
	}
	
	//find Start
	if (First->info == info) Start = First;
	else
	{
		for (Current = First->next; Current != First; Current = Current->next)
		{
			if (Current->info == info)
			{
				Start = Current;
				break;
			}
		}
	}

	//no del el
	if (!Start) return First;

	for (Current = Start->next; counter < count && (Current != Start); counter++)
	{
		Start->next = Current->next;
		free(Current);
		if (Current == First) First = Start->next;
		Current = Start->next;
	}
	if (counter < count)
	{
		free(Current);
		return NULL;
	}

	return First;
}

int main()
{
	struct List* First, * Current;
	int info, count;
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

	//print original list
	for (Current = First; Current->next != First; Current = Current->next) printf("%d ", Current->info);
	printf("%d\n", Current->info);

	First = changed_list(First, info, count);
	//print changed list
	if (!First)
	{
		printf("the list is empty");
		return 0;
	}
	if (First->next == First) printf("%d", First->info);
	else
	{
		for (Current = First; Current->next != First; Current = Current->next) printf("%d ", Current->info);
		printf("%d", Current->info);
	}
	
	free_list(First);
	return 0;
}
*/