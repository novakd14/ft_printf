/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cases_fnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:43:06 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/05 12:04:29 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_test.h"

static void	char_test_cases(void)
{
	printf("\033[34mPrint char %%c = 'A': \033[0m");
	printf("%c\n", 'A');
	printf("\033[34mPrint char %%c = '\\0': \033[0m");
	printf("%c\n", '\0');
	printf("\033[34mPrint char %%c = 0: \033[0m");
	printf("%c\n", 0);
	printf("\033[34mPrint char %%c = NULL: \033[0m");
	printf("%c\n", NULL);
}

static void	str_test_cases(void)
{
	printf("\033[34mPrint str %%s = \"Make 42Prague great!\": \033[0m");
	printf("%s\n", "Make 42Prague great!");
	printf("\033[34mPrint str %%s = '\\0': \033[0m");
	printf("%s\n", '\0');
	printf("\033[34mPrint str %%s = 0: \033[0m");
	printf("%s\n", 0);
	printf("\033[34mPrint str %%s = NULL: \033[0m");
	printf("Segmentation fault\n");
}

static void	ptr_test_cases(void)
{
	void *ptr = 0x56070f902008;

	printf("\033[34mPrint ptr %%p = NULL: \033[0m");
	printf("%p\n", NULL);
	printf("\033[34mPrint ptr %%p = 0x56070f902008: \033[0m");
	printf("%p\n", 0x56070f902008);
	printf("\033[34mPrint ptr %%p = 0x001: \033[0m");
	printf("%p\n", 0x001);
	printf("\033[34mPrint ptr %%p = 0xfedcba987654321: \033[0m");
	printf("%p\n", 0xfedcba987654321);
	printf("\033[34mPrint ptr %%p = 0x987654321fedcba987654321: \033[0m");
	printf("%p\n", 0x987654321fedcba987654321);
	printf("--> sizeof(ptr) = 8 ==> 16 hexadecimal places\n");
}

static void	digit_test_cases(void)
{
	printf("\033[34mPrint digit %%d = 0x1A (hexadec): \033[0m");
	printf("%d\n", 0x1A);
	printf("\033[34mPrint digit %%d = 0x1a (hexadec): \033[0m");
	printf("%d\n", 0x1a);
	printf("\033[34mPrint digit %%d = 0xAa (hexadec): \033[0m");
	printf("%d\n", 0xAa);
	printf("\033[34mPrint digit %%d = 010 (octa): \033[0m");
	printf("%d\n", 010);
	printf("\033[34mPrint digit %%d = 10 (dec): \033[0m");
	printf("%d\n", 10);
	printf("\033[34mPrint digit %%d = -0x10 (dec): \033[0m");
	printf("%d\n", -0x10);
	printf("\033[34mPrint digit %%d = -010 (dec): \033[0m");
	printf("%d\n", -010);
	printf("\033[34mPrint digit %%d = -10 (dec): \033[0m");
	printf("%d\n", -10);
}

static void	int_test_cases(void)
{
	printf("\033[34mPrint int %%i = 0x10 (hexadec): \033[0m");
	printf("%i\n", 0x10);
	printf("\033[34mPrint int %%i = 010 (octa): \033[0m");
	printf("%i\n", 010);
	printf("\033[34mPrint int %%i = 10 (dec): \033[0m");
	printf("%i\n", 10);
	printf("\033[34mPrint int %%i = -10 (dec): \033[0m");
	printf("%i\n", -10);
}

static void	unsign_test_cases(void)
{
	printf("\033[34mPrint unsigned %%u = 0x10 (hexadec): \033[0m");
	printf("%u\n", 0x10);
	printf("\033[34mPrint unsigned %%u = 010 (octa): \033[0m");
	printf("%u\n", 010);
	printf("\033[34mPrint unsigned %%u = 10 (dec): \033[0m");
	printf("%u\n", 10);
	printf("\033[34mPrint unsigned %%u = -10 (dec): \033[0m");
	printf("%u\n", -10);
}

static void	hexdeclow_test_cases(void)
{
	printf("\033[34mPrint hexadec low %%x = 0x1aA (hexadec): \033[0m");
	printf("%x\n", 0x1aA);
	printf("\033[34mPrint hexadec low %%x = 013 (octa): \033[0m");
	printf("%x\n", 013);
	printf("\033[34mPrint hexadec low %%x = 10 (dec): \033[0m");
	printf("%x\n", 10);
	printf("\033[34mPrint hexadec low %%x = -10 (dec): \033[0m");
	printf("%x\n", -10);
}

static void	hexdecup_test_cases(void)
{
	printf("\033[34mPrint hexadec up %%X = 0x1aA (hexadec): \033[0m");
	printf("%X\n", 0x1aA);
	printf("\033[34mPrint hexadec up %%X = 013 (octa): \033[0m");
	printf("%X\n", 013);
	printf("\033[34mPrint hexadec up %%X = 10 (dec): \033[0m");
	printf("%X\n", 10);
	printf("\033[34mPrint hexadec up %%X = -10 (dec): \033[0m");
	printf("%X\n", -10);
}

void	print_test_cases(void)
{
	printf("\033[1mShow test cases:\033[0m\n");
	printf("\033[34mPrint basic input: \033[0m");
	printf("Some basic input here!\n");
	printf("\033[34mPrint %%%%: \033[0m");
	printf("%%\n");
	printf("\n");
	char_test_cases();
	printf("\n");
	str_test_cases();
	printf("\n");
	ptr_test_cases();
	printf("\n");
	digit_test_cases();
	printf("\n");
	int_test_cases();
	printf("\n");
	unsign_test_cases();
	printf("\n");
	hexdeclow_test_cases();
	printf("\n");
	hexdecup_test_cases();
	printf("\n");
}
