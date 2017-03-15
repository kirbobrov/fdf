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


/*
void	begin(int fd, char *z)
{
	t_v		v;

	v.a = 0;
	v.b = 0;
	v.c = 0;
	v.name = z;
	v.str = fd_to_str(fd);
	while (v.str[v.a])
	{
		((v.str[v.a] >= 48 && v.str[v.a] <= 57) || v.str[v.a] == 45) ?
		v.b++ : 0;
		v.str[v.a] == 45 ? v.a++ : 0;
		while (v.str[v.a] >= 48 && v.str[v.a] <= 57)
			v.a++;
		v.str[v.a] == 44 ? skip(&v, 1) : 0;
		while (v.str[v.a] == 32)
			v.a++;
		if (v.str[v.a] == 10)
			if (line_number(&v))
				break ;
		if (skip(&v, 0))
			break ;
	}
	v.c == 1 ? write(1, "File has only one number.\n", 26) : 0;
	v.a && v.c != 1 ? save_map(v) : 0;
}
 int		skip(t_v *v, int b)
{	if (b)
	{		v->a++;
		while ((v->str[v->a] >= 48 && v->str[v->a] <= 57) ||
			(v->str[v->a] >= 65 && v->str[v->a] <= 70) ||
			(v->str[v->a] >= 97 && v->str[v->a] <= 102) || v->str[v->a] == 120)
			v->a++;	}
	else
	{		if (!(v->str[v->a] >= 48 && v->str[v->a] <= 57) &&
			v->str[v->a] != 45 && v->str[v->a] && v->str[v->a] != 32)
		{
			write(1, "File invalid. Exiting.\n", 23);
			v->a = 0;
			return (1);
		}
	}
	return (0);
}

*/