/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:22:12 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/27 12:27:08 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_print_str("-2147483648");
	else if (n < 0)
	{
		i += ft_print_char('-');
		i += ft_print_int(-n);
	}
	else if (n > 9)
	{
		i += ft_print_int(n / 10);
		i += ft_print_char(n % 10 + '0');
	}
	else
		i += ft_print_char(n + '0');
	return (i);
}
