/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print2file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:46 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/05 12:15:31 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_test.h"

static int	print2file(char *s)
{
	int out = open("expect.log", O_RDWR|O_CREAT|O_TRUNC, 00644);
    if (-1 == out)
	{
		printf("opening expect.log\n");
		return (0);
	}

    int save_out = dup(fileno(stdout));
    if (-1 == dup2(out, fileno(stdout)))
	{
		printf("cannot redirect stdout\n");
		return (0);
	}

	printf(s);

	fflush(stdout);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	return (1);
}

static int	ft_print2file(char *s)
{
	int out = open("users.log", O_RDWR|O_CREAT|O_TRUNC, 00644);
    if (-1 == out)
	{
		printf("opening users.log\n");
		return (0);
	}

    int save_out = dup(fileno(stdout));
    if (-1 == dup2(out, fileno(stdout)))
	{
		printf("cannot redirect stdout\n");
		return (0);
	}

	ft_printf(s);
	printf("test diff");

	fflush(stdout);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	return (1);
}

int	test_stdout(char *s)
{
	char *users = "users.log";
	char *expect = "expect.log";
	char *diff = calloc(6 + strlen(users) + strlen(expect), sizeof(char));

	if (diff == NULL)
	{
		printf("cannot allocate memory\n");
		return 0;
	}
	strcat(diff, "diff ");
	strcat(diff, users);
	strcat(diff, " ");
	strcat(diff, expect);
	print2file(s);
	ft_print2file(s);
	return(system(diff));
}
