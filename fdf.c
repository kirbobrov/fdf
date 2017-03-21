/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:08:47 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/23 17:53:53 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_destroy(t_fdf *s)
{
	mlx_clear_window(s->mlx, s->win);
	ft_image(s);
}

int		my_key(int	keycode, t_fdf *s)
{
	(keycode == 53) ? exit (53) : 0;
	if (keycode == 126)
	{
		s->dy -= 100;
		mlx_destroy(s);
	}
	if(keycode == 125)
	{
		s->dy += 100;
		mlx_destroy(s);
	}
	if (keycode == 123)
	{
		s->dx -= 100;
		mlx_destroy(s);
	}
	if (keycode == 124)
	{
		s->dx += 100;
		mlx_destroy(s);
	}
	if (keycode == 78 || keycode == 27)
	{
		 s->mult -= 100;
		mlx_destroy(s);
	}
	if (keycode == 69 || keycode == 24)
	{
		s->mult += 100;
		mlx_destroy(s);
	}
	if(keycode == 0)
	{
		s->za0 += 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 6)
	{
		s->za0 -= 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 1)
	{
		s->xa0 += 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 7)
	{
		s->xa0 -= 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 2)
	{
		s->ya0 += 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 8)
	{
		s->ya0 -= 10;
		ft_isometric(s);
		mlx_destroy(s);
	}
	if(keycode == 45)
	{
		s->mult = 700;
		mlx_destroy(s);
	}
	printf ("my keycode %d\n", keycode);
	return (0);
}

int		ft_mouse_hook(void *win, int x, int y, t_fdf *s)
{
	exit (77);  /// дописать исполнение события когда нажимается крестик
}

int 	ft_xmax(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	t_fdf	s;
	int 	fd;
	char 	*buf;
	size_t 	op;

	s.mlx = mlx_init ();
	s.win = mlx_new_window (s.mlx, WEIGHT, HEIGHT, "fdf");
	fd = open(av[1], O_RDONLY);
	s.ymax = 0;
	while (get_next_line(fd, &buf))
		s.ymax++;
	s.xmax = ft_xmax(ft_strsplit(buf, ' '));
	////printf("s.ymax == %d  s.xmax == %d\n", s.ymax, s.xmax);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		av[1] && ac == 2 ? write(1, "No file ", 8) : 0;
		av[1] && ac == 2 ? write(1, &(*av[1]), 1) : 0;
		if (av[1] && ac == 2)
			while (*av[1]++)
				write(1, &(*av[1]), 1);
		av[1] && ac == 2 ? write(1, "\n", 1) : 0;
		!av[1] || ac > 2 ? write(1, "Usage : ./fdf <filename>\n", 25) : 0;
	}
	(ac == 2 && fd >= 3) ? ft_readmap(fd, &s) : 0;

	close(fd);

	//mlx_mouse_hook(s.win, ft_mouse_hook, &s);
	mlx_hook(s.win, 17, 0L, ft_mouse_hook, &s);
	mlx_loop (s.mlx);
}