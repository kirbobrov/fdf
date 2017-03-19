/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:00:46 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/12 14:00:48 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrx(t_fdf *s, t_point *pt)
{
	double y;
	double z;
	double a;

	y = pt->y;
	z = pt->z;
	a = s->xa;

	RAD(a);
	//pt.x = (x * 1);
	pt->y = ((y * cos(a)) + (z * (-sin(a))));
	pt->z = ((y * sin(a)) + (z * cos(a)));
}

void	ft_matry(t_fdf *s, t_point *pt)
{
	double x;
	double z;
	double a;

	x = pt->x;
	z = pt->z;
	a = s->ya;

	RAD(a);
	pt->x = ((x * cos(a)) + (z * sin(a)));
	//pt.y = ((y * cos(a)) + (z * (-sin(a))));
	pt->z = ((x * (-sin(a))) + (z * cos(a)));
}

void	ft_matrz(t_fdf *s, t_point *pt)
{
	double x;
	double y;
	double a;

	a = s->za;
	s->mult = 700;
	x = pt->x;
	y = pt->y;
	pt->x0 = pt->x;
	pt->y0 = pt->y;
	pt->z0 = pt->z;

	RAD(a);
	pt->x = ((x * cos(a)) + (y * (-sin(a))));
	pt->y = ((x * sin(a)) + (y * (cos(a))));
	//pt.z = ((x * (-sin(a))) + (z * cos(a)));
}

void	ft_isometric(t_fdf *s, t_point **pt)
{
	int x;
	int y;
	//double xa;
	//double ya;
	//double za;

	//printf("conner in isometric== %f  conner 0  in isometric== %f \n", s->xa, s->xa0);
	y = 0;
	while (y < s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			ft_matrz(s, &pt[y][x]);
			ft_matrx(s, &pt[y][x]);
			ft_matry(s, &pt[y][x]);
			x++;
			//printf("x0 = %.f!\tx = %.f!\ty0 = %.f!\ty = %.f!\tz0 = %.f!\tz = %.f!\t\n", pt[y][x].x0, pt[y][x].x, pt[y][x].y0, pt[y][x].y, pt[y][x].z0, pt[y][x].z);
		}
		y++;
	}
}