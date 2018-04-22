/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:10:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/22 19:16:18 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define INT_MAX 2147483647
# define SCY 1080
# define SCX 1920

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
}				t_libx;

#endif
