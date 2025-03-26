/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct List {
	int info;
	struct List* next;
};

struct Deque {
	int info;
	struct Deque* past;
	struct Deque* next;
};

void free_list(struct List* First)
{
	struct List* Current, * Past;

	//singl el list
	if (!(First->next))
	{
		free(First);
		return;
	}

	//free from first el to last el not included
	for (Past = Current = First; Current->next; Current = Current->next)
	{
		if (First == Current) continue;
		free(Past);
		Past = Current;
	}

	//free last el
	free(Past);
	free(Current);

	return;
}

struct Deque* free_start_deque(struct Deque* First, int free_size)
{
	struct Deque* Current;
	int el_count;

	//empty deque
	if (!First) return NULL;

	//single el deque
	if (!(First->next))
	{
		free(First);
		return NULL;
	}

	//free all
	if (!free_size)
	{
		if (!(First->next))
		{
			free(First);
			return NULL;
		}
		for (Current = First->next; Current->next; Current = Current->next) free(Current->past);
		free(Current->past);
		free(Current);
		return NULL;
	}

	//free from first el to last el not included
	for (Current = First->next; free_size && (Current->next); Current = Current->next, free_size--) free(Current->past);
	if (free_size > 0)
	{
		free(Current->past);
		Current->past = NULL;
		if (free_size > 1)
		{
			free(Current);
			Current = NULL;
		}
	}
	else
	{
		Current = Current->past;
		Current->past = NULL;
	}

	return Current;
}

struct Deque* free_end_deque(struct Deque* Last, int free_size)
{
	struct Deque* Current;
	int el_count;

	//empty deque
	if (!Last) return NULL;

	//singl el list
	if (!(Last->past))
	{
		free(Last);
		return NULL;
	}

	//free from first el to last el not included
	for (Current = Last->past; free_size && (Current->past); Current = Current->past, free_size--) free(Current->next);
	if (free_size > 0)
	{
		free(Current->next);
		Current->next = NULL;
		if (free_size > 1)
		{
			free(Current);
			Current = NULL;
		}
	}
	else
	{
		Current = Current->next;
		Current->next = NULL;
	}

	return Current;
}

struct Deque* add_start_deque(struct Deque* First, int add_size)
{
	struct Deque* Current;
	int left_flag, el_info = 1;

	//empty deque
	if (!First)
	{
		Current = malloc(sizeof(struct Deque));
		if (!Current) return NULL;
		Current->info = el_info;
		el_info++;
		Current->past = Current->next = NULL;
		First = Current;
	}

	for (Current = First; el_info <= add_size; el_info++)
	{
		Current->past = malloc(sizeof(struct Deque));
		if (!(Current->past))
		{
			free_start_deque(Current, 0);
			return NULL;
		}
		(Current->past)->next = Current;
		Current = Current->past;
		Current->info = el_info;
		Current->past = NULL;
	}

	return Current;
}

struct Deque* add_end_deque(struct Deque* First, struct Deque* Last, int add_size)
{
	struct Deque* Current;
	int left_flag, el_info = 1;

	//empty deque
	if (!First)
	{
		Current = malloc(sizeof(struct Deque));
		if (!Current) return NULL;
		Current->info = el_info;
		el_info++;
		Current->past = Current->next = NULL;
		First = Last = Current;
	}

	for (Current = Last; el_info <= add_size; el_info++)
	{
		Current->next = malloc(sizeof(struct Deque));
		if (!(Current->next))
		{
			free_start_deque(First, 0);
			return NULL;
		}
		(Current->next)->past = Current;
		Current = Current->next;
		Current->info = el_info;
		Current->next = NULL;
	}

	return Current;
}

void do_actions(struct List* Action_list)
{
	struct Deque* First, *Last, *Current;
	struct List* Current_action;
	int print_flag = 0;

	First = Last = NULL;
	for (Current_action = Action_list; Current_action; Current_action = Current_action->next)
	{
		//0
		if (!(Current_action->info)) continue;
		//left/righ and delite/add
		//delite
		if ((Current_action->info) < 0)
		{
			if (Current_action->info % 2)
			{
				First = free_start_deque(First, (-1) * (Current_action->info));
				if (!First) Last = NULL;
			}
			else
			{
				Last = free_end_deque(Last, (-1) * (Current_action->info));
				if (!Last) First = NULL;
			}
		}
		//add
		else
		{
			if (Current_action->info % 2)
			{
				Last = add_end_deque(First, Last, Current_action->info);
				if (!Last) return;
				if (!First) for (Current = Last; Current; Current = Current->past) First = Current;
			}
			else
			{
				First = add_start_deque(First, Current_action->info);
				if (!First) return;
				if (!Last) for (Current = First; Current; Current = Current->next) Last = Current;
			}
		}

		//print deque
		if (!First) printf("0");
		for (Current = First; Current; Current = Current->next) printf("%d ", Current->info);
		printf("\n");
		print_flag = 1;
	}

	if (!print_flag) printf("0");
	else free_start_deque(First, 0);
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
			free_list(Action_list);
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
		free_list(Action_list);
		return 0;
	}

	do_actions(Action_list);
	free_list(Action_list);
	return 0;
}
*/