/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:21:21 by matrodri          #+#    #+#             */
/*   Updated: 2021/11/02 20:57:00 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_range(int argc, char **argv)
{
	int	size;

	size = argc - 1;
	while (size)
	{
		if (ft_atoi(argv[size]) < INT_MIN || ft_atoi(argv[size]) > INT_MAX)
			return (FALSE);
		size--;
	}
	return (TRUE);
}
