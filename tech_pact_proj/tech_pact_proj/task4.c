/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List {
	int info;
	struct List* next;
};

//same task3
struct List* free_els(struct List* First, int count)
{
	int i;
	struct List* Return,* Past;

	//empty list
	if (!First) return NULL;

	//one el list
	if (!(First->next))
	{
		free(First);
		return NULL;
	}

	Past = First;
	Return = First->next;

	//free all
	if (!count)
	{
		for (; !Return; Return = Return->next, Past = Past->next) free(Past);
		free(Past);
		return NULL;
	}

	//free n frist els
	for (i = count; i; i--, Return = Return->next)
	{
		free(Past);
		Past = Return;
		if (!Past) break;
	}
	Return = Past;
	return Return;
}


void do_actions(struct List* Action_list)
{
	struct List* Steck, * First, * Current_action, * Current;
	int c_a_count, print_flag = 0;

	Steck = First = NULL;
	for (Current_action = Action_list; Current_action; Current_action = Current_action->next)
	{
		c_a_count = Current_action->info;
		//0
		if (!c_a_count) continue;
		//delite
		if (c_a_count < 0) Steck = free_els(Steck, (-1) * c_a_count);
		//first el
		else if (!Steck)
		{
			Steck = malloc(sizeof(struct List));
			if (!Steck) return;
			Steck->info = 1;
			Steck->next = NULL;
			c_a_count--;
		}

		//enSteck
		for (; c_a_count > 0; c_a_count--)
		{
			First = malloc(sizeof(struct List));
			if (!First)
			{
				free_els(Steck, 0);
				return;
			}
			First->info = (Steck->info) + 1;
			First->next = Steck;
			Steck = First;
		}

		//print Steck
		if (!Steck) printf("0");
		for (Current = Steck; Current; Current = Current->next) printf("%d ", Current->info);
		printf("\n");
		print_flag = 1;
	}

	if (!print_flag) printf("0");

	free_els(Steck, 0);
	return;
}

//same task3
int main()
{
	struct List* Action_list, * Current_action;
	int action;
	char dot;

	Action_list = Current_action = NULL;
	while (scanf("%d", &action))
	{
		//action list el
		if (!Action_list)
		{
			Action_list = malloc(sizeof(struct List));
			if (!Action_list) return 0;
			Current_action = Action_list;
			Action_list->info = action;
			continue;
		}

		//el
		Current_action->next = malloc(sizeof(struct List));
		if (!(Current_action->next))
		{
			Current_action->next = NULL;
			free_els(Action_list, 0);
			return 0;
		}
		Current_action = Current_action->next;
		Current_action->info = action;
	}

	//empty action list
	if (!Action_list)
	{
		printf("0");
		return 0;
	}

	Current_action->next = NULL;
	scanf("%c", &dot);
	//no end el
	if (dot != '.')
	{
		free_els(Action_list, 0);
		return 0;
	}

	do_actions(Action_list);
	free_els(Action_list, 0);
	return 0;
}
*/