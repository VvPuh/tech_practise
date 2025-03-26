#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List {
	char info;
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
	for (;First;First = First->next) printf("%c", First->info);
	return;
}

struct List* del_not_lat(struct List* First, struct List* Last)
{
	struct List* Current_last = Last, * Del = NULL;
	for (; First != Last;)
	{
		if (Del)
		{
			free(Del);
			Del = NULL;
		}
		if (('z' >= First->info && First->info >= 'a') || ('Z' >= First->info && First->info >= 'A'))
		{
			Current_last->next = First;
			First = First->next;
			Current_last = Current_last->next;
			Current_last->next = NULL;
			continue;
		}
		Del = First;
		First = First->next;
	}
	if(Del) free(Del);
	if (('z' >= First->info && First->info >= 'a') || ('Z' >= First->info && First->info >= 'A'))
	{
		Current_last->next = First;
		First = First->next;
		Current_last = Current_last->next;
		Current_last->next = NULL;
	}
	else
	{
		Del = First;
		First = First->next;
		free(Del);
	}
	
	
	return First;
}

int main()
{
	struct List* First, * Current, * Last;
	char info;
	char dot;

	First = Current = Last = NULL;
	while (scanf("%c", &info))
	{
		if (info == '.') break;

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
			free_list(First);
			return 0;
		}
		Current = Current->next;
		Current->info = info;
	}

	//empty list
	if (!First)
	{
		printf("the queue is empty");
		return 0;
	}

	Last = Current;
	Current->next = NULL;
	print_list(First);
	printf("\n");

	First = del_not_lat(First, Last);
	if (!First)
	{
		printf("the queue is empty");
		return 0;
	}
	print_list(First);
	free_list(First);
	return 0;
}