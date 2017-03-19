/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:27:20 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/25 17:27:34 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_swapcolor(char *str)
{
	int 	i;

	i = 0;
	while(str)
	{
		if (str[i] > 96 || str[i] < 103)
			str[i] -= 32;
		i++;
	}
} //////функция не дописана. нужно допиать что бы она свапала все в большой регистр
*/
char 	*ft_color_substr(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == 'x' || str[i] == 'X')
				return (str + i + 1);
			else
				i++;
		}
	///return ("00");
	return ("FFFFFF");
}

void	ft_con(t_fdf *s)
{
	s->xa0 = 48;
	s->ya0 = 0;
	s->za0 =  315;
	s->xa = s->xa0;
	s->ya = s->ya0;
	s->za = s->za0;
	s->dx = 1100;
	s->dy = 900;
}

int		ft_readmap(const int fd, t_fdf *s)
{
	int		x;
	int		y;
	char 	**buf;
	char 	*line;
	//t_point **po;

	y = 0;
	//ft_valid(s);
	s->pt = (t_point**)malloc(sizeof(t_point*) * (s->ymax + 1));
	s->pt[s->ymax] = NULL;
	//s->pt = po;
	while (get_next_line(fd, &line) > 0)
	{
		printf("line[%d] == %s\n",y , line);
		x = 0;
		s->pt[y] = (t_point*)malloc(sizeof(t_point) * (s->xmax));

		buf = ft_strsplit(line, ' ');
		while(buf[x])
		{
			s->pt[y][x].x = x - (s->xmax / 2);
			s->pt[y][x].y = y - (s->ymax / 2);
			s->pt[y][x].z =  ft_atoi(buf[x]);
			//ft_swapcolor(buf[x]);
			s->pt[y][x].color = ft_atoi_base(ft_color_substr(buf[x]), 16);
			printf("buf[x] = %s\t\t\t, x = %i\telem[%d][%d].z = %.1f\t\tcolor[%d]=%d\n", buf[x], x, y, x, s->pt[y][x].z, x, s->pt[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_con(s);
	//ft_bits(s, po);
	ft_image(s);/// убрал второй аргумент на точку
	mlx_key_hook (s->win, my_key, s);

	//printf("main 3\n");
	return 0;
}