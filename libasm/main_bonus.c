/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:39:33 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/03/05 17:09:21 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define ATOIBASE(x, y, z)			printf("'%s', '%s' = %d, exp %d %s\n", x, y, ft_atoi_base(x, y), z, (ft_atoi_base(x, y) == z ? "✔" : "✘"));

int		ft_atoi_base(char *str, char *base);

int main()
{
	printf("\033[0;97m"); printf("\n---atoi_base---\n"); printf("\033[0m");
	ATOIBASE("10", "01", 2);

}	
