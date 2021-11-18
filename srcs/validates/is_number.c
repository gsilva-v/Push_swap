/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:01:57 by matrodri          #+#    #+#             */
/*   Updated: 2021/11/02 20:15:38 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(int argc, char **argv)
{
	int	size;

	size = argc - 1;
	while (size > 0)
	{
		if (!ft_isdigit(*argv[size]))
			return (FALSE);
		size--;
	}
	return (TRUE);
}
