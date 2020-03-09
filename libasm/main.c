/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:15:50 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/03/09 15:35:57 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define STRLEN(x)			printf("'%s' = %lu, exp %lu %s\n", x, ft_strlen(x), strlen(x), (ft_strlen(x) == strlen(x) ? "✔" : "✘"));

# define STRCPY(x, y)			printf("'%s'= '%s', exp '%s' %s\n", x, ft_strcpy(x, y), strcpy(x, y), (strcmp(ft_strcpy(x, y), strcpy(x, y)) == 0 ? "✔" : "✘"));

# define STRCMP(x, y)			printf("'%s', '%s'= %d, exp %d %s\n", x, y, ft_strcmp(x, y), strcmp(x, y), (ft_strcmp(x, y) == strcmp(x, y) ? "✔" : "✘"));

# define WRITE(x, y, z)			printf("'%s' = %ld, exp %ld %s\n", y, ft_write(x, y, z), write(x, y, z), (ft_write(x, y, z) == write(x, y, z) ? "✔" : "✘"));

# define READ(x, y, z)			printf("'%s' = %ld, exp %ld %s\n", y, ft_read(x, y, z), read(x, y, z), (ft_read(x, y, z) == read(x, y, z) ? "✔" : "✘"));

# define STRDUP(x)			printf("'%s' = '%s', exp '%s' %s\n", x, ft_strdup(x), strdup(x), (strcmp(ft_strdup(x), strdup(x)) == 0 ? "✔" : "✘"));

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

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

	printf("\033[0;97m"); printf("\n---write---\n"); printf("\033[0m");
	WRITE(-1, "yo", 2);
	WRITE(-1, "", 0);
	WRITE(0, "yo", 2);
	WRITE(0, "", 0);
	WRITE(1, "yo", 2);
	WRITE(1, "", 0);

	printf("\033[0;97m"); printf("\n---read---\n"); printf("\033[0m");
	READ(-1, str, 0);
	READ(-1, str, 1);
	READ(1, str, 0);
	READ(5, str, 2);

	printf("\033[0;97m"); printf("\n---strdup---\n"); printf("\033[0m");
	STRDUP("yo");
	STRDUP("");
}
