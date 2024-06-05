/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print2file_1arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:46 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/05 20:17:24 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_test.h"

static int	print2file(char *file, char *s)
{
	int out = open(file, O_RDWR|O_CREAT|O_TRUNC, 00644);
    if (-1 == out)
		return (printf("ERR opening expect.log\n"), 0);

    int save_out = dup(fileno(stdout));
    if (-1 == dup2(out, fileno(stdout)))
		return (printf("ERR cannot redirect stdout\n"), 0);

	printf(s);

	fflush(stdout);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	return (1);
}

static int	ft_print2file(char *file, char *s)
{
	int out = open(file, O_RDWR|O_CREAT|O_TRUNC, 00644);
	if (-1 == out)
		return (printf("ERR opening users.log\n"), 0);
	int save_out = dup(fileno(stdout));
	if (-1 == dup2(out, fileno(stdout)))
		return (printf("ERR cannot redirect stdout\n"), 0);

	ft_printf(s);

	fflush(stdout);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	return (1);
}

static int	check_diff(char *file, char *diff)
{
	int out = open(file, O_RDWR|O_CREAT|O_TRUNC, 00644);
	if (-1 == out)
		return (printf("ERR opening users.log\n"), -1);
	int save_out = dup(fileno(stdout));
	if (-1 == dup2(out, fileno(stdout)))
		return (printf("ERR cannot redirect stdout\n"), -1);
	int check = system(diff);
	fflush(stdout);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	if (check == 0)
		return (printf("PASS\n"), 1);
	else
		return (printf("FAIL\n"), 0);

}

// RETURN VALUE:
//	-1	for error
//	0	for PASS
//	>0	for FAIL
int	test_stdout_1arg(char *s)
{
	char *u_file = "users.log";
	char *e_file = "expect.log";
	char *d_file = "diff.log";
	char *diff = calloc(6 + strlen(u_file) + strlen(e_file) + 1, sizeof(char));

	if (diff == NULL)
		return (printf("ERR cannot allocate memory\n"), -1);
	sprintf(diff, "diff %s %s", u_file, e_file);

	if (ft_print2file(u_file, s) == 0)
		return (free(diff), -1);
	if (print2file(e_file, s) == 0)
		return (free(diff), -1);
	int check = check_diff(d_file, diff);
	return (free(diff), check);
}
