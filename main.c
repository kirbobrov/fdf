/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:08:47 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/18 14:47:04 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "minilibx/mlx.h"

/*int		my_key(int	keycode, void *mlx, void *win)
{
	printf ("my keycode %d\n", keycode);
	mlx_pixel_put (mlx, win, 300, 200, 0xFF00FF);
	return (0);
}

int		main()
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;

	mlx = mlx_init ();
	win = mlx_new_window (mlx, 800, 600, "new window mlx");

	y = 100;
	while (y < 400)
	{
		x = 100;
		while (x < 600)
		{
			mlx_pixel_put (mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook (win, my_key, mlx);
	mlx_loop (mlx);
}*/

int ft_readmap(char *str)
{
	int 	i;
	int 	j;
	int 	n;
	char	*buf;
	char	*tmp;
	t_point	**pt;

	n = -1;
	pt = (t_point*)malloc(sizeof(t_point));
	pt = NULL;
	i = 0;
	while(str)
	{
		tmp = ft_strnew(ft_strlen(get_next_line(str, &tmp)));
		n++;
		buf = ft_strsplit(tmp, '\n');
		while (buf)
		{
			pt[n][i].x = i;
			pt[n][i].y = n;
			pt[n][i].z = ft_atoi(buf);
			buf++;
			i++;
		}
		ft_strdel(&buf);
		ft_strdel(&tmp);
	}
	return (0);
}

int fdf(int ac, char **av)
{
	int		i;
	//char	*tmp;
	char	*buf;

	i = 0;
	if (2 != ac)
		{
			write(1, "usage: .fdf/ source_file\n",24);
			return (1);
		}
	//if (!ac > 2)
	//	{
	//		write(1, "error\n", 6);
	//		return (1);
	//	}
	//if (ft_validmap(argv[1]) == 0)
	//	ft_error;
	buf = ft_strnew(ft_strlen(av[2]));
	buf = ft_strcpy(buf, av[2]);
	ft_readmap(buf);


	return 0;
}