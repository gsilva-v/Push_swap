/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_different.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:17:59 by matrodri          #+#    #+#             */
/*   Updated: 2021/11/03 12:53:30 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_different(int argc, char **argv)
{
	int	size;
	int	pos;

	size = argc - 1;
	pos = size - 1;
	while (size > 0)
	{
		while (pos > 0)
		{
			if (ft_atoi(argv[size]) == ft_atoi(argv[pos]))
				return (FALSE);
			pos--;
		}
		size--;
		pos = size - 1;
	}
	return (TRUE);
}
