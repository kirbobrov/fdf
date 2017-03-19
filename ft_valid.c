/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:58:47 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/02 18:58:50 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_skipcolor(t_fdf *s, int a)
{
	int i;

	i = 0;
	if (a)
		while ((s->str[i] >= 48 && s->str[i] <= 57) ||
			   (s->str[i] >= 65 && s->str[i] <= 70) ||
			   (s->str[i] >= 97 && s->str[i] <= 102) || s->str[i] == 120)
			i++;
	else
	if (!(s->str[i] >= 48 && s->str[i] <= 57) || (s->str[i] != 45 && s->str[i] && s->str[i] != 32))
	{
		write(1, "File invalid. Exiting.\n", 23);
		return (0);
	}
	return (i);  /// not valid function return not correct value
}

int ft_valid(t_fdf *s)
{
	int i;
	int	num;
//	int tab;
	int col;
	i = 0;
	num = 0;
	while (s->str[i++])
	{
		if((s->str[i] >= 48 && s->str[i] <= 57) || s->str[i] == 45)
			num++;
		if(s->str[i] == 44)
			col = ft_skipcolor(s, 1);
	}
	printf("color %d\n", col);
	return (0);
}