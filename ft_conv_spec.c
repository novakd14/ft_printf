/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:09:46 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/04 22:52:12 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conv_spec_char(int c)
{
	write(1, &((unsigned char) c), 1);
	return (1);
}

int	ft_conv_spec_str(const char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
