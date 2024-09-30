/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:59:57 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/27 12:38:44 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_print_uint(n / 10);
		i += ft_print_char(n % 10 + '0');
	}
	else
		i += ft_print_char(n + '0');
	return (i);
}
