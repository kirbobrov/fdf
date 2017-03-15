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

void 	ft_readpoint(t_fdf *s)
{
	int 	i;
	//int		j;
	int 	l;

	//char 	*buf;
	l = 0;
	i = 0;
	while (s->str[i++])
		s->str[i] == '\n' ? l++ : 0;
	//j = 0;
	s->ymax = l;
	printf("y max == %d\n", s->ymax);
}

void	ft_read(const int fd, char *src, t_fdf *s)
{
	int		i;
	size_t		re;
	char	*buf;
	char	*str;

	i = 0;
	buf = (char *)malloc(10000001);
	re = read(fd, buf, 10000000);
	str = (char *)malloc(re + 1);
	while (i <= re)
	{
		str[i] = buf[i];
		i++;
 	}
	str[i] = '\0';
	s->str = str;
	free (buf);
	//return (str);
}

int 	ft_lenline(char **str)
{
	int i;
	int	j;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			n++;
		}
		i++;
	}
	return (n);
}

char 	*ft_color(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i]) {
			if (str[i] == 'x' || str[i] == 'X')
				return (str + i + 1);
			i++;
		}
	printf("i = %d\n", i);
	return (NULL);
}

int		ft_readmap(const int fd, char *src, t_fdf *s)
{
	int		x;
	int		y;
	char 	**buf;
	char 	**line;
	char 	**col;
	t_point **po;

	y = 0;
	//buf = ft_strnew(0);
	//buf = ft_strjoin(buf, (ft_read(fd, src))); /// read all map join src to buf
	ft_read(fd, src, s);
	ft_readpoint(s);
	//ft_valid(s);
	po = (t_point**)malloc(sizeof(t_point*) * s->ymax);
	buf = ft_strsplit(s->str, '\n');
	while (buf[y])
	{
	//	printf("ft_readmap buf[y] = %s\n", buf[y]);
		x = 0;
		line = ft_strsplit(buf[y], ' ');
		//printf("ft_readmap line[x]  ==== %s\n", line[x]);
		po[y] = (t_point*)malloc(sizeof(t_point) * (s->xmax = ft_lenline(line)));
		//printf("s->xmax = %d\n", s->xmax); //// нужно дописать остановился на том что необходимо порезать стринг по сьтрокам и запихнуть в массив структур
		while(line[x])
		{
			col = ft_strsplit(line[x], ',');
			po[y][x].x = x;
			po[y][x].y = y;
			printf("col == %s   %s\n", col[0], col[1]);
			col[0] ? (po[y][x].z = ft_atoi(col[0])) : 0;
			col[1] ? (po[y][x].color = ft_atoi_base(ft_color(col[1]), 16)) : (po[y][x].color = 0xFFFFFF);
			//printf("ft_readmap po[%d][%d].x = %d po[%d][%d].y = %d\n", y, x, po[y][x].x, y, x, po[y][x].y);
			//printf("ft_readmap po[%d][%d].y read point === %d\n", y, x, po[y][x].y);
			//printf("ft_readmap line[%d] read point === %d\n", x, po[y][x].z);
			printf("color %d\n", po[y][x].color);
			x++;
		}
		y++;
	}
	//ft_isometric(s, po);
	ft_bits(s, po);
	//ft_image(s, po);
	//printf("ft_readmymap\n%s\n", s->str);

	//printf("main 3\n");
	return 0;
}