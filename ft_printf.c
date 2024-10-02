/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:57:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/02 19:52:01 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converter(const char *str, int i, va_list args)
{
	if (str[i + 1] == 'c')
		return (i += ft_putchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		return (i += ft_putstr(va_arg(args, char *)));
	if (str[i + 1] == 'p')
		return (ft_putptr(va_arg(args, unsigned int), 0));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (str[i + 1] == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), str[i + 1]));
	if (str[i + 1] == '%')
		return (ft_putchar(str[i]));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			count += ft_converter(string, i, args);
			i += 2;
		}
		ft_putchar(string[i++]);
		count++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	//char	c = 'c';
	char	*str = NULL;
	//int		i = 102489153;
	//unsigned int		u = 4294967295;
	//void	*ptr = (void *)malloc(sizeof(char) * 8);

	printf("%d\n\n", ft_printf("%s\n", str));
	printf("%d\n", printf("%s\n", str));
	//free(ptr);
	return (0);
}
