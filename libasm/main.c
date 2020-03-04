/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:15:50 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/03/04 17:06:14 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define STRLEN(x)			printf("'%s' = %d, exp %d %s\n", x, ft_strlen(x), (int)strlen(x), (ft_strlen(x) == (int)strlen(x) ? "✔" : "✘"));

# define STRCPY(x, y)			printf("'%s'= %s, exp %s %s\n", x, ft_strcpy(x, y), strcpy(x, y), (strcmp(ft_strcpy(x, y), strcpy(x, y)) == 0 ? "✔" : "✘"));

# define STRCMP(x, y)			printf("'%s', '%s'= %d, exp %d %s\n", x, y, ft_strcmp(x, y), strcmp(x, y), (ft_strcmp(x, y) == strcmp(x, y) ? "✔" : "✘"));

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);

int main()
{
	char str[100];

	printf("\033[0;97m"); printf("\n---strlen---\n"); printf("\033[0m"); 
	STRLEN("yo");
	STRLEN("");
	printf("\033[0;97m"); printf("\n---strcpy---\n"); printf("\033[0m"); 
	STRCPY(str, "yo");
	STRCPY(str, "");
	printf("\033[0;97m"); printf("\n---strcmp---\n"); printf("\033[0m"); 
	STRCMP("yo", "yo");
	STRCMP("yo", "y");
	STRCMP("", "yo");
	STRCMP("yo", "");
	STRCMP("", "");
}
