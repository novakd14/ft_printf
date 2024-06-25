/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_test.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/20 15:06:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_TEST_H
# define LIBFTPRINTF_TEST_H
# include "../ft_printf/libftprintf.h"
# include "unity.h"
# include <fcntl.h>  // flags for open
# include <stdio.h>  // printf, fflush
# include <unistd.h> // open, close, dup, dup2
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_UINT 4294967295
# define MIN_UINT 0

#endif // LIBFTPRINTF_TEST_H
