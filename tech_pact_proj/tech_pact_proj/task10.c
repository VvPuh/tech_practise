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
	struct List* Return, * Past;

	//empty list
	if (!First) return;

	//one el list
	if (!(First->next))
	{
		free(First);
		return;
	}

	Past = First;
	Return = First->next;

	for (; !Return; Return = Return->next, Past = Past->next) free(Past);
	free(Past);
	return;
}

void print_list(struct List* First)
{
	for (;First;First = First->next) printf("%d ", First->info);
	return;
}

struct List* sort_deque(struct List* First, struct List* Last)
{
	int min, new_min, count_min;
	struct List* New_First, * Current, * Current_Last;

	//min el(s)
	for (Current = First, count_min = 0, min = First->info;Current;Current=Current->next)
	{
		if (min == Current->info) count_min++;
		else if (Current->info < min)
		{
			min = Current->info;
			count_min = 1;
		}
	}
	New_First = malloc(sizeof(struct List));
	if (!New_First)
	{
		free_list(First);
		return NULL;
	}
	Current_Last = Last->next = New_First;
	Current_Last->info = min;
	count_min--;
	for (;count_min;count_min--)
	{
		Current_Last->next = malloc(sizeof(struct List));
		if (!(Current_Last->next))
		{
			free_list(First);
			return NULL;
		}
		Current_Last = Current_Last->next;
		Current_Last->info = min;
	}

	//other els
	while (1)
	{
		//find new_min>min
		for (Current = First, new_min = min;Current != Last->next;Current = Current->next)
		{
			if (Current->info > min)
			{
				new_min = Current->info;
				break;
			}
		}
		if (new_min == min)
		{
			Current_Last->next = NULL;
			Last->next = NULL;
			free_list(First);
			return New_First;
		}
		for (Current = First, count_min = 0;Current != Last->next;Current = Current->next)
		{
			if (new_min == Current->info) count_min++;
			else if (min < Current->info && Current->info < new_min)
			{
				new_min = Current->info;
				count_min = 1;
			}
		}
		//make el(s)
		for (;count_min;count_min--)
		{
			Current_Last->next = malloc(sizeof(struct List));
			if (!(Current_Last->next))
			{
				free_list(First);
				return NULL;
			}
			Current_Last = Current_Last->next;
			Current_Last->info = new_min;
		}
		min = new_min;
	}
}

int main()
{
	struct List* First, * Current, * Last;
	int info;
	char dot;

	First = Current = Last = NULL;
	while (scanf("%d", &info))
	{
		//action list el
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
			Current->next = NULL;
			free_list(First);
			return 0;
		}
		Current = Current->next;
		Current->info = info;
	}

	//empty list
	if (!First)
	{
		printf("dec is empty");
		return 0;
	}

	Last = Current;
	Current->next = NULL;
	scanf("%c", &dot);
	//no end el
	if (dot != '.')
	{
		free_list(First);
		return 0;
	}

	print_list(First);
	printf("\n");

	First = sort_deque(First, Last);
	if (!First) return 0;

	print_list(First);
	free_list(First);
	return 0;
}
*/