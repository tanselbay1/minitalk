/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:20:31 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/27 12:51:42 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <unistd.h>

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_print_hex((unsigned long long)ptr, 0);
	return (count);
}
