/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:50 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/05 11:57:52 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while(*(format + i))
		if(*(format + i) == '%')
		{
			i++;
			write(1, (format + i++), 1);
			len++;
		}
		else
		{
			write(1, (format + i++), 1);
			len++;
		}
	return (len);
}
