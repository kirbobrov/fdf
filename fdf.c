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


int		my_key(int	keycode, t_fdf *s)
{
	if (keycode == 53)
		exit (53);
	printf ("my keycode %d\n", keycode);
	//mlx_pixel_put (mlx, win, 300, 200, 0xFF00FF);
	return (0);
}

int		ft_mouse_hook(void *win, int x, int y, t_fdf *s)
{
	exit (77);  // дописать исполнение события когда нажимается крестик
}

int		main(int ac, char **av)
{
	t_fdf	s;
	int 	fd;

	s.mlx = mlx_init ();
	s.win = mlx_new_window (s.mlx, 1600, 1200, "fdf");
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
	(ac = 2 && fd >= 3) ? ft_readmap(fd, av[1], &s) : 0;


	close(fd);
	mlx_key_hook (s.win, my_key, &s);
	//mlx_mouse_hook(s.win, ft_mouse_hook, &s);
	//ft_draw(900, 500, 357, 524, 0x00FFFFFF, &s); /// x0, y0, xn, yn, color, struct(win, mlx)
	mlx_hook(s.win, 17, 0L, ft_mouse_hook, &s);
	mlx_loop (s.mlx);
}