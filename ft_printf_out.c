/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:32:37 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/02 18:41:37 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*		Collection of functions to write various variables from a single char
		to strings, decimals and the likes.									*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;

	count = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = ft_putstr("0x");
	
	return (count);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		count++;
	}
	if (nbr > 10)
		ft_putnbr(nbr / 10);
	count += ft_putchar("0123456789"[nbr % 10]);
	return (count);
}

int	ft_putunsigned(unsigned int nbr)
{
	int	i;
	
	if (nbr > 9)
		ft_putunsigned(nbr / 10);
	ft_putchar("0123456789"[nbr % 10]);
	return (i);
}
