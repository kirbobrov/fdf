/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:30:04 by kbobrov           #+#    #+#             */
/*   Updated: 2017/02/23 17:54:04 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# define RAD(a) (a = 0.01745329 * a)


typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	x0;
	double	y0;
	double 	z0;
	int		color;
}				t_point;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	//void			*img;
	t_point			**pt;
	//int				mapx;
	//int				mapy;
	int				turn[3];
	char 			*str;
	char 			**line;
	int				xmax;
	int				ymax;
	int 			dx;
	int 			dy;
	//double 			delimeter=700;
	double			mult;
	double			xa;
	double 			xa0;
	double 			ya;
	double 			ya0;
	double 			za;
	double 			za0;


//	double			mapz;
//	struct  s_fdf	*next;

}				t_fdf;

/*
typedef struct      s_fdf
{
	    void            *mlx;
		void            *win;
		void            *img;
		t_pxl           **ptr;
		int             mapx;
		int             mapy;
		int             turn[3];
		double          mult;
		double          multz;
		int             shift_x;
		int             shift_y;
}                   t_fdf;
*/

int		fdf(int ac, char **av);
int		ft_readmap(const int fd, t_fdf *s);
///int		ft_valid(t_fdf *s);
void	ft_image(t_fdf *s);
void	ft_isometric(t_fdf *s, t_point **pt);
///int 	ft_bits(t_fdf *s, t_point **pt);
int		my_key(int	keycode, t_fdf *s);
///void	mlx_destroy(t_fdf *s, t_point **pt);

#endif
