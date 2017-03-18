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

void	ft_swapcolor(char *str)
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

char 	*ft_color_substr(char *str)
{
	int 	i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == 'x' || str[i] == 'X')
				return (str + i + 1);
			else
				i++;
		}
	return ("FFFFFF");
}

int		ft_readmap(const int fd, t_fdf *s)
{
	int		x;
	int		y;
	char 	**buf;
	char 	*line;
	t_point **po;

	y = 0;
	//ft_read(fd, s);
	//ft_valid(s);
	po = (t_point**)malloc(sizeof(t_point*) * (s->ymax + 1));
	po[s->ymax] = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		printf("line[%d] == %s\n",y , line);
		x = 0;
		po[y] = (t_point*)malloc(sizeof(t_point) * (s->xmax));

		buf = ft_strsplit(line, ' ');
		while(buf[x])
		{
			po[y][x].x = x;
			po[y][x].y = y;
			po[y][x].z = (double)ft_atoi(buf[x]);
			//ft_swapcolor(buf[x]);
			po[y][x].color = ft_atoi_base(ft_color_substr(buf[x]), 16);
			printf("buf[x] = %s\t\t\t, x = %i\telem[%d][%d].z = %.1f\t\tcolor[%d]=%d\n", buf[x], x, y, x, po[y][x].z, x, po[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_isometric(s, po);
	//ft_bits(s, po);
	ft_image(s, po);

	//printf("main 3\n");
	return 0;
}