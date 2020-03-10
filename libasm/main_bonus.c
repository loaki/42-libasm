/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:39:33 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/03/10 17:13:39 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define ATOIBASE(x, y, z)			printf("'%s', '%s' = %d, exp %d %s\n", x, y, ft_atoi_base(x, y), z, (ft_atoi_base(x, y) == z ? "✔" : "✘"));

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void			print_list(t_list *list)
{
	while (list)
	{
		printf(" %s,", list->data);
		list = list->next;
	}
	printf("\n");
}

void			clear_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->data)
			free(list->data);
		free(list);
		list = tmp;
	}
}

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list,int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void*));

int main()
{
	printf("\033[0;97m"); printf("\n---atoi_base---\n"); printf("\033[0m");
	ATOIBASE("AB10", "0123456789ABCDEF", 43792);
	ATOIBASE("10", "01", 2);
	ATOIBASE("-10", "01", -2);
	ATOIBASE("  +-10", "01", -2);
	ATOIBASE(" --10", "01", 2);
	ATOIBASE(" --10 ", "01", 2);
	ATOIBASE("1", "001", 0);
	ATOIBASE(" -- 10", "01", 0);
	ATOIBASE(" --10", "0 1", 0);
	ATOIBASE(" --10", "0+1", 0);

	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("yo");
	list.next = &list_next;
	list_next.data = strdup("pouet");
	list_next.next = &list_last;
	list_last.data = strdup("truc");
	list_last.next = NULL;

	printf("\033[0;97m"); printf("\n---list_push_front---\n"); printf("\033[0m");
	t_list *list_push = &list;
	printf("list :"); print_list(list_push);
	ft_list_push_front(&list_push, "toto");
	printf("add 'toto' :"); print_list(list_push);
	ft_list_push_front(&list_push, "shrek");
	printf("add 'shrek' :"); print_list(list_push);

	printf("\033[0;97m"); printf("\n---list_size---\n"); printf("\033[0m");
	t_list *list_size = &list;
	printf("list :"); print_list(list_size);
	printf("nb elem : %d\n", ft_list_size(list_size));
	printf("list :"); print_list(list_push);
	printf("nb elem : %d\n", ft_list_size(list_push));

	printf("\033[0;97m"); printf("\n---list_sort---\n"); printf("\033[0m");
	t_list *list_sort = &list;
	printf("list :"); print_list(list_sort);
	ft_list_sort(&list_sort, &strcmp);
	printf("sorted :"); print_list(list_sort);
	printf("list :"); print_list(list_push);
	ft_list_sort(&list_push, &strcmp);
	printf("sorted :"); print_list(list_push);

	printf("\033[0;97m"); printf("\n---list_remove_if---\n"); printf("\033[0m");
	t_list *list_remove = &list;
	ft_list_push_front(&list_remove, strdup("salut"));
	ft_list_push_front(&list_remove, strdup("shrek"));
	printf("list :"); print_list(list_remove);
	ft_list_remove_if(&list_remove, "salut", &strcmp, &free);
	printf("remove 'salut' :"); print_list(list_remove);
	ft_list_remove_if(&list_sort, "shrek", &strcmp, &free);
	printf("remove 'shrek' :"); print_list(list_sort);
}	
