/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:57:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/02 18:48:40 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_converter(const char *str, int i, va_list args)
{
	if (str[i + 1] == 'c')
		return (i += ft_putchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		return (i += ft_putstr(va_arg(args, char *)));
/*	if (str[i + 1] == 'p')
		ft_putptr(va_arg(args, void *));	*/
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr(va_arg(args, int));
	if (str[i + 1] == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
/*	if (str[i + 1] == 'x')
		ft_puthex_low();	// TODO
	if (str[i + 1] == 'X')
		ft_puthex_up();		// TODO		*/
	if (str[i + 1] == '%')
		ft_putchar(str[i]);
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	va_start(args, string);
	while (string[i] != '\0')	// iterate string and putchar normal chars until '%' sign
	{
		if (string[i] == '%')
		{
			count += ft_converter(string, i, args);
			i += 2;	// print conversion and increment count
		}
		ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	char	c = 'c';
	char	*str = "string";
	int		i = 13456;
	unsigned int		u = 4294967295;
	void	*ptr = (void *)malloc(sizeof(char) * 8);

//	ft_printf("Char = %c\nStr= %s\nInt = %u\n", c, str, i);
	printf("Char = %c\nStr= %s\nInt = %i\nUnsigned = %u\nPtr = %p\n", c, str, i, u, ptr);
	free(ptr);
	return (0);
}
