/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:29:31 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/25 13:58:32 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		ft_color1(t_libx *f)
{
	f->color[0] = 0xff3f3f;
	f->color[1] = 0xd83636;
	f->color[2] = 0xaa2a2a;
	f->color[3] = 0x841f1f;
	f->color[4] = 0x631515;
	f->colorb = 0;
}

void		ft_color(t_libx *f)
{
	int				fd;
	unsigned char	buf[3];

	if (!(fd = open("/dev/random", O_RDONLY)))
		exit(ft_printf("Failed open /dev/random\n"));
	read(fd, buf, 3);
	f->color[0] = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
	read(fd, buf, 3);
	f->color[1] = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
	read(fd, buf, 3);
	f->color[2] = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
	read(fd, buf, 3);
	f->color[3] = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
	read(fd, buf, 3);
	f->color[4] = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
	read(fd, buf, 3);
	f->colorb = creatergb(buf[0] % 255, buf[1] % 255, buf[2] % 255);
}
