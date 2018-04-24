/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:14:10 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/24 13:32:16 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_exit(char *s)
{
	ft_printf("%s\n", s);
	exit(-1);
}

int			ft_check_fct(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		i++;
	}
	if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "m"))
		return (1);
	if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "j"))
		return (2);
	if (!ft_strcmp(s, "autre") || !ft_strcmp(s, "a"))
		return (3);
	return (0);
}

int			main(int ac, char **av)
{
	t_libx	*ptr;

	if (ac != 2)
		return (ft_printf("Usage: ./fractol [fract]\n"));
	if (!(ptr = (t_libx*)malloc(sizeof(t_libx))))
		ft_exit("Malloc error");
	ft_bzero(ptr, sizeof(t_libx));
	ptr->frct = ft_check_fct(av[1]);
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, SCX, SCY, "Fractol");
	mlx_key_hook(ptr->win_ptr, ft_key_hook, (t_libx*)ptr);
	mlx_mouse_hook(ptr->win_ptr, ft_mouse_hook, (t_libx*)ptr);
	ft_print(ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
