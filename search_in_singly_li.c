#include <stdio.h>
#include <stdlib.h>

struct List {
	int value;
	struct List *next;
};

void	ft_search_li(struct List *li)
{
	int to_search;
	int i;
	printf("\nInput the element to be searched : ");
	scanf("%i", &to_search);
	i = 1;
	while( li->next != NULL)
	{
		if ( li->value == to_search )
		{
			printf("Element found at node %i\n", i);
			return;
		}
		li = li->next;
		i++;
	}
	if ( li->value == to_search )
	{
		printf("Element found at node %i\n", i);
		return;
	}
	printf("\nElement not found\n");
	return;
}

void	ft_display_li(struct List *list)
{
	int i;
	i = 1;
	while( list->next != NULL)
        {
		printf("Data : %i\n", list->value);
                list = list->next;
		i++;
        }
	printf("Data : %i\n", list->value);
	return;
}

void	ft_insert_at_end(int to_insert, struct List *list)
{
	struct List *new_node;
	new_node = malloc(sizeof(*new_node));
	new_node->value = to_insert;
	new_node->next = NULL;
	while( list->next != NULL)
	{
		list = list->next;
	}
	list->next = new_node;
	return;
}

int	main (int argc, char *argv[])
{
	struct List *li;
	li = malloc(sizeof(*li));
	li->next = NULL;
	int i;
	int nb_node;
	int buff_value;
	printf("Input the number of nodes : ");
	scanf("%i", &nb_node);
	i = 1;
	while ( i <= nb_node )
	{
		printf("Input data for node %i : ", i);
		scanf("%i", &buff_value);
		if ( i == 1)
		{
			li->value = buff_value;
		}
		else
		{
			ft_insert_at_end(buff_value, li);
		}
		i++;
	}
	printf( "\n\nData entered in the list : \n");
	ft_display_li(li);
	ft_search_li(li);
	return 1;
}