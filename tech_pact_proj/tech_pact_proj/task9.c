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
	for (;First;First = First->next) printf("%c", First->info);
	return;
}

struct List* make_stuples(struct List* First)
{
	struct List* New_el, * Last,* Current_First = First, * Current;
	for (Last = First;Last->next;Last = Last->next);
	for (;First != Last;)
	{
		if (('z'>= Last->info && Last->info >= 'a') || ('Z' >= Last->info && Last->info >= 'A'))
		{
			//)
			New_el = malloc(sizeof(struct List));
			if (!New_el)
			{
				free_list(Current_First);
				return NULL;
			}
			New_el->info = ')';
			New_el->next = Current_First;
			Current_First = New_el;
			//el
			New_el = malloc(sizeof(struct List));
			if (!New_el)
			{
				free_list(Current_First);
				return NULL;
			}
			New_el->info = Last->info;
			New_el->next = Current_First;
			Current_First = New_el;
			//(
			New_el = malloc(sizeof(struct List));
			if (!New_el)
			{
				free_list(Current_First);
				return NULL;
			}
			New_el->info = '(';
			New_el->next = Current_First;
			Current_First = New_el;
		}
		else
		{
			//el
			New_el = malloc(sizeof(struct List));
			if (!New_el)
			{
				free_list(Current_First);
				return NULL;
			}
			New_el->info = Last->info;
			New_el->next = Current_First;
			Current_First = New_el;
		}
		//new last
		for (Current = First;Current->next != Last; Current = Current->next);
		free(Last);
		Last = Current;
		Last->next = NULL;
	}

	//for first
	if (('z' >= Last->info && Last->info >= 'a') || ('Z' >= Last->info && Last->info >= 'A'))
	{
		//)
		New_el = malloc(sizeof(struct List));
		if (!New_el)
		{
			free_list(Current_First);
			return NULL;
		}
		New_el->info = ')';
		New_el->next = Current_First;
		Current_First = New_el;
		//el
		New_el = malloc(sizeof(struct List));
		if (!New_el)
		{
			free_list(Current_First);
			return NULL;
		}
		New_el->info = Last->info;
		New_el->next = Current_First;
		Current_First = New_el;
		//(
		New_el = malloc(sizeof(struct List));
		if (!New_el)
		{
			free_list(Current_First);
			return NULL;
		}
		New_el->info = '(';
		New_el->next = Current_First;
		Current_First = New_el;
	}
	else
	{
		//el
		New_el = malloc(sizeof(struct List));
		if (!New_el)
		{
			free_list(Current_First);
			return NULL;
		}
		New_el->info = Last->info;
		New_el->next = Current_First;
		Current_First = New_el;
	}
	//last
	free(Last);

	//First -> NULL
	for (Current = Current_First;Current->next != First; Current = Current->next);
	Current->next = NULL;
	
	return Current_First;
}

int main()
{
	struct List* First, *Current;
	char info;

	First = Current = NULL;
	while (scanf("%c", &info))
	{
		if (info == '.') break;

		if (!First)
		{
			First = malloc(sizeof(struct List));
			if (!First) return 0;
			First->next = NULL;
			First->info = info;
			continue;
		}

		//el
		Current = malloc(sizeof(struct List));
		if (!Current)
		{
			free_list(First);
			return 0;
		}
		Current->next = First;
		Current->info = info;
		First = Current;
	}

	//empty list
	if (!First)
	{
		printf("stack is empty");
		return 0;
	}

	print_list(First);
	printf("\n");
	
	First = make_stuples(First);
	if(!First) return 0;
	print_list(First);
	
	free_list(First);
	return 0;
}
*/