/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:07:54 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/24 15:53:09 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_print(t_libx *f)
{
	f->image = mlx_new_image(f->mlx_ptr, SCX, SCY);
	f->pix = mlx_get_data_addr(f->image, &f->bbp, &f->s_l, &f->endian);
	if (f->frct == 1 || f->frct == 0)
		ft_mandel(f);
	if (f->frct == 2)
		ft_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image, 0, 0);
	mlx_destroy_image(f->mlx_ptr, f->image);
}
