/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:48:13 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/27 12:39:11 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <unistd.h>

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		count += ft_print_str("(null)");
	else
	{
		while (*str)
			count += write(1, str++, 1);
	}
	return (count);
}
