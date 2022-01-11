#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int value;
	struct List *next;
	struct List *previous;
}List;


void	ft_display_li(List *list)
{
	List *buff;
	buff = malloc(sizeof(*buff));
	buff = list;
	int i;
	i = 1;
	while( list->next != buff)
        {
		printf("Data : %i\n", list->value);
                list = list->next;
		i++;
        }
	printf("Data : %i\n", list->value);
	return;
}

void	ft_insert_at_end(int to_insert, List *list)
{
	List *new_node;
	new_node = malloc(sizeof(*new_node));
	new_node->value = to_insert;
	new_node->next = list;
	while( list->next != new_node->next)
	{
		list = list->next;
	}
	list->next = new_node;
	return;
}

int	main (int argc, char *argv[])
{
	List *li;
	li = malloc(sizeof(*li));
	li->next = li;
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
	return 1;
}

