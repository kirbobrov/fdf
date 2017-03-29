/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:54:55 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/24 17:54:58 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"

/*t_img ft_image(t_fdf *s)
{
//	t_img	*image;

/*	image = (t_img*)malloc(sizeof(t_img));
	int bpp;
	int ednl;
	int sizel;

	s->img = mlx_new_image(s->mlx, WEIGHT, HEIGHT);
	s->line = mlx_get_data_addr(s->img, &bpp, &sizel, &ednl);
	printf("bpp: %d\n", bpp);
	//return (image);
}*/


/*
typedef struct s_env
{
	void *mlx;
	void *win;
	void *img;
}               t_env;

///// все что ниже скинул Вадим. на основе этого написать свое
void put_pix_img(t_env *e, int x, int y, t_color *c)
{
	char *data;
	int bpp;
	int size_l;
	int endi;
	int x0;
	if (c == NULL)
		return ;
	data = mlx_get_data_addr(e->img, &bpp, &size_l, &endi);
	printf("bpp: %d\n", bpp);
	printf("s_l: %d\n", size_l);
	x0 = y * size_l + x * 4;
	data[x0] = 0xFF;//145;//c->b; //Blue
	data[x0 + 1] = 0xFF;//92;//c->g; // Green
	data[x0 + 2] = 0xFF;//31;//c->r; //Red
}
int main ()
{
	t_env e;
	t_color c;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 450, 450, "mlx 42");
	e.img = mlx_new_image(e.mlx, 450, 450);
	c.r = 0xFF; //red
	c.g = 0xFF; //green
	c.b = 0xFF; //blue
//  ft_put_line(&e, 70, 370, 30, 370, &c);
	//  put_pix_img(&e, 200, 200, &c);
	ft_draw_line(50, 100, 70, 300, &c, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, my_key_funct, &e);
	mlx_loop(e.mlx);
}
*/