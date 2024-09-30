/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:29:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/27 12:36:21 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i] == '%')
		count += ft_print_char('%');
	else if (format[i] == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format[i] == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (format[i] == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format[i] == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format[i] == 'i' || format[i] == 'd')
		count += ft_print_int(va_arg(args, int));
	else if (format[i] == 'u')
		count += ft_print_uint(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		output_length;

	i = 0;
	output_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			output_length += ft_formatter(format, args, ++i);
		else
		{
			output_length += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (output_length);
}

// int	main(void)
// {
// 	int returnPrintf;
// 	int returnPrintf1;
// 	int nbr = 10;

// returnPrintf = ft_printf("Main string: %s", "string");

// Hexadecimal Test
// returnPrintf = ft_printf("255 in hexadecimal = %x\n", 255);
// returnPrintf = ft_printf("255 in hexadecimal = %X\n", 255);

// Pointer Test
// int *ptr;
// ptr = &nbr;
// returnPrintf = printf("Pointer Address: %p\n", (void *)ptr);
// returnPrintf1 = ft_printf("Pointer Address1: %p", (void *)ptr);
// printf("\nReturn value: %d\n", returnPrintf);
// printf("\nReturn value: %d\n", returnPrintf1);

// Integer Test
// returnPrintf = ft_printf("My number: %i\n", -10);
// printf("My number with built-in: %i\n", -1);

// Unsigned Integer Test
// 	returnPrintf = ft_printf("My number: %u\n", 0xFFFFFFFF);
// 	printf("My number with built-in: %u\n", 0xFFFFFFFF);
// }