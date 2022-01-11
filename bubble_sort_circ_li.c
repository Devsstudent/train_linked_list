#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int value;
	struct List *next;
	struct List *previous;
}List;

int	ft_check(List *list)
{
	List *buff;
	buff = malloc(sizeof(*buff));
	buff = list;
	while( list->next != buff )
	{
		if(list->value > list->next->value)
		{
			return 0;	
		}
		list = list->next;
	}
	return 1;
}

void	ft_sort_li(List *list)
{
	List *buff;
	int i;
	buff = malloc(sizeof(*buff));
	buff = list;
	int buffer;
	while ( ft_check(list) != 1)
	{
		i = 0;
		while ( list->next != buff)
		{
			if ( list->value > list->next->value )
			{
				buffer = list->value;
				list->value = list->next->value;
				list->next->value = buffer;
				if ( i == 0)
				{
					buff = list;	
				}
			}
			list = list->next;
			i++;
		}
		list = buff;
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
	ft_sort_li(li);
	printf("After sort : \n");
	ft_display_li(li);
	return 1;
}



