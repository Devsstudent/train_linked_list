#include <stdio.h>
#include <stdlib.h>

struct List {
	int value;
	struct List *next;
	struct List *previous;
};


void	ft_display_li(struct List *list)
{
	int i;
	i = 1;
	while( list->next != NULL)
        {
		printf("node %i : %i\n", i, list->value);
                list = list->next;
		i++;
        }
	printf("node %i : %i\n", i, list->value);
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
	new_node->previous = list;
	list->next = new_node;
	return;
}

int	main (int argc, char *argv[])
{
	struct List *li;
	li = malloc(sizeof(*li));
	li->next = NULL;
	li->previous = NULL;
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
	printf( "\n\nData entered in the list are : \n");
	ft_display_li(li);
	return 1;
}
