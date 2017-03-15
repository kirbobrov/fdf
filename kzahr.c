

tatic t_pxl    *mkstruct(t_fdf **fdf, t_map **start)
{
	    t_pxl   *new;
		char    **array;
		int     i;
		double  hx;
		double  hy;

		i = 0;
		hx = (*fdf)->mapx / 2;
		hy = (*fdf)->mapy / 2;
		array = ft_strsplit((*start)->mapline, ' ');
		while (array[i])
			i++;
		if (i != (*fdf)->mapx)
			return (NULL);
		new = (t_pxl *)malloc(sizeof(t_pxl) *  ((*fdf)->mapx));
		i = -1;
		while (array[++i])
		{
			new[i].x = (i - hx);
			new[i].y = ((*start)->linenum - hy);
			new[i].z = ft_atoi(array[i]);
			new[i].color = makecolor(array[i], &new[i]);
		}
		delarray(array);
return (new);
}
