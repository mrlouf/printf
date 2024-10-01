/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:57:51 by nponchon          #+#    #+#             */
/*   Updated: 2024/10/01 17:08:20 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	size_t		count;

	va_start(args)
	i = 0;
	while (i < ft_strlen(format))
	{
		if ()
		{
			
		}
		write(1, format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
