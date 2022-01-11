#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int value;
	struct List *next;
	struct List *previous;
}List;

void	ft_insert_at(struct List *li)
{
	int pos;
	int value;
	int i;
	struct List *new_node;
	struct List *buff;
	buff = li;
	new_node = malloc(sizeof(*new_node));
	printf("\nInput the position of the element you want to insert : ");
	scanf("%i", &pos);
	printf("\nInput the value you want to insert : ");
	scanf("%i", &value);
	new_node->value = value;	
	i = 1;
	if ( pos == 1)
	{
		new_node->value = li->value;
		new_node->next = li->next;
		new_node->previous = li;
		li->value = value;
		li->next = new_node;
		return;
	}
	while (li->next != buff)
	{
		if ( i + 1 == pos )
		{
			new_node->next = li->next;
			new_node->previous = li;
			li->next = new_node;
			return;
		}	
		li = li->next;
		i++;
	}
	if ( i + 1 == pos )
	{
		new_node->next = li->next;
		new_node->previous = li;
		li->next = new_node;
	}	
	return;
}

void	ft_display_li(List *list)
{
	List *buff;
	buff = malloc(sizeof(*buff));
	buff = list;
	int i;
	i = 1;
	while( list->next != buff)
        {
		printf("node %i : %i\n", i, list->value);
                list = list->next;
		i++;
        }
	printf("node %i : %i\n", i, list->value);
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
	new_node->previous = list;
	list->next = new_node;
	return;
}

int	main (int argc, char *argv[])
{
	List *li;
	li = malloc(sizeof(*li));
	li->next = li;
	li->previous = li;
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
	ft_insert_at(li);
	ft_display_li(li);
	return 1;
}


