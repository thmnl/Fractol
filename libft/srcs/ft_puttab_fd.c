/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 07:33:49 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/21 07:35:10 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, int fd)
{
	int i;

	if (!tab || fd < 0 || fd > 1024)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_putendl_fd(tab[i], fd);
		i++;
	}
}
