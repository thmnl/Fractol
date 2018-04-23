/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:10:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/23 20:37:45 by tmanuel          ###   ########.fr       */
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
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		zoom;
	int		imax;
	float	cr;
	float	ci;
	float	zr;
	float	zi;
	int		i;
}				t_libx;

int				ft_mouse_hook(int key, int x, int y, void *f);
void			ft_exit(char *s);
int				ft_key_hook(int key, void *f);
void			ft_putpixel(t_libx *env, int x, int y, int color);
void			ft_print(t_libx *f);

#endif
