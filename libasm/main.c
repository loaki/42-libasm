/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:01:56 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/03/03 19:33:45 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define STRLEN(x)			printf("%s = %d, exp %d\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);

int main()
{
	printf("\n---TESTS---\n");
	STRLEN("salut");
}