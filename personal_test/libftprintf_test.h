/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_test.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/07 15:39:38 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_TEST_H
#define LIBFTPRINTF_TEST_H
#include "../libftprintf.h"
#include <stdio.h>	// printf, sprintf, I/O streams, fileno, fflush
#include <unistd.h> // close, open, dup
#include <fcntl.h>	// flags for open
#include <stdlib.h> // system

void print_test_cases(void);
int test_stdout(char *s);

#endif // LIBFTPRINTF_TEST_H
