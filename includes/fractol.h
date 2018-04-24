/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:10:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/24 15:36:50 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define INT_MAX 2147483647
# define SCY 1000
# define SCX 1300

typedef struct	s_libx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*image;
	char	*pix;
	int		bbp;
	int		s_l;
	int		endian;
	int		frct;
	double	zoom;
	double	ar1;
	double	ar2;
	double	rar1;
	double	rar2;
	int		im;
	double	x1;
	double	y1;
	double	zoomm;
	int		imax;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	int		i;
	int		djoo;
}				t_libx;

void			ft_julia(t_libx *f);
int				ft_hook(int x, int y, t_libx *f);
void			ft_mandel(t_libx *f);
int				ft_mouse_hook(int key, int x, int y, t_libx *f);
void			ft_exit(char *s);
int				ft_key_hook(int key, t_libx *f);
void			ft_putpixel(t_libx *env, int x, int y, int color);
void			ft_print(t_libx *f);

#endif
