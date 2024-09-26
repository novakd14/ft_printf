#include "libftprintf_test.h"

static char	*file = "buffer.log";
static int	out;
static int	save_out;
static char	buf[100];

static void	ft_setStart(int fd)
{
	lseek(fd, 0, SEEK_SET);
}

static void	ft_clearFile(char *file, int out)
{
	int	clear;

	clear = open(file, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (-1 == clear)
		TEST_IGNORE_MESSAGE("cannot open buffer file");
	close(clear);
	ft_setStart(out);
}

static void	ft_readBuffer(int out, char *buf)
{
	fflush(stdout);
	ft_setStart(out);
	read(out, buf, 100);
}

void	setUp(void)
{
	out = open(file, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (-1 == out)
		TEST_IGNORE_MESSAGE("cannot open buffer file");
	fflush(stdout);
	save_out = dup(fileno(stdout));
	if (-1 == dup2(out, fileno(stdout)))
	{
		close(out);
		TEST_IGNORE_MESSAGE("cannot redirect stdout");
	}
	ft_bzero(buf, 100);
}

void	tearDown(void)
{
	if (-1 == out || -1 == save_out)
		return ;
	ft_bzero(buf, 100);
	ft_readBuffer(out, buf);
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	printf("%s", buf);
}

void	test_printf_NULL(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = -1;
	given_len = printf(NULL);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_emptyString(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_basicInput(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "Hello world";
	expect_len = 11;
	given_len = printf("Hello world");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_char(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "A";
	expect_len = 1;
	given_len = printf("%c", 'A');
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_nonPrintChar(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 1;
	given_len = printf("%c", '\0');
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_nonAsciiChar(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "\xF9";
	expect_len = 1;
	given_len = printf("%c", 249);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0char(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = " ";
	expect_len = 3;
	given_len = printf(" %c ", 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_2char(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "Ab";
	expect_len = 2;
	given_len = printf("%c%c", 'A', 'b');
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_2charInStr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "Character: A, character: b";
	expect_len = 26;
	given_len = printf("Character: %c, character: %c", 'A', 'b');
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_str(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "42Prague";
	expect_len = 8;
	given_len = printf("%s", "42Prague");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_emptystr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("%s", "");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0str(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	char	*str;

	str = 0;
	expect = "(null)";
	expect_len = 6;
	given_len = printf("%s", str);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_NULLstr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	char	*str;

	str = NULL;
	expect = "(null)";
	expect_len = 6;
	given_len = printf("%s", str);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_paddNULLstr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	char	*str;

	str = NULL;
	expect = "    (null)";
	expect_len = 10;
	given_len = printf("%10s", str);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_smallPrecisionNULLstr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	char	*str;

	str = NULL;
	expect = "";
	expect_len = 0;
	given_len = printf("%.4s", str);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_bigPrecisionNULLstr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	char	*str;

	str = NULL;
	expect = "(null)";
	expect_len = 6;
	given_len = printf("%.10s", str);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_charstr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "/42Prague";
	expect_len = 9;
	given_len = printf("%c%s", '/', "42Prague");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_ptr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	void	*ptr;

	ptr = (void *)0x42f;
	expect = "0x42f";
	expect_len = 5;
	given_len = printf("%p", ptr);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_RNDptr(void)
{
	char	expect[18];
	int		expect_len;
	int		given_len;
	char	*ptr;

	ptr = "42Prague";
	ft_bzero(expect, 18);
	expect_len = sprintf(expect, "%p", ptr);
	given_len = printf("%p", ptr);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0ptr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	void	*ptr;

	ptr = 0;
	expect = "(nil)";
	expect_len = 5;
	given_len = printf("%p", ptr);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_NULLptr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	void	*ptr;

	ptr = 0;
	expect = "(nil)";
	expect_len = 5;
	given_len = printf("%p", ptr);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_paddNULLptr(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;
	void	*ptr;

	ptr = NULL;
	expect = "     (nil)";
	expect_len = 10;
	given_len = printf("%10p", ptr);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0Iint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%i", 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_maxIint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "2147483647";
	expect_len = 10;
	given_len = printf("%i", MAX_INT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_minIint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "-2147483648";
	expect_len = 11;
	given_len = printf("%i", (int)MIN_INT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0Dint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%d", 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_maxDint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "2147483647";
	expect_len = 10;
	given_len = printf("%d", MAX_INT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_minDint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "-2147483648";
	expect_len = 11;
	given_len = printf("%d", (int)MIN_INT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_sign0Dint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "+0";
	expect_len = 2;
	given_len = printf("%+d", 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_sign0precision0Dint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "+";
	expect_len = 1;
	given_len = printf("%+.d", 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_Uint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "1234";
	expect_len = 4;
	given_len = printf("%u", 1234);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_maxUint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "4294967295";
	expect_len = 10;
	given_len = printf("%u", (unsigned)MAX_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_minUint(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%u", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_hexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "9abcdef";
	expect_len = 7;
	given_len = printf("%x", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_maxHexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "ffffffff";
	expect_len = 8;
	given_len = printf("%x", (unsigned)MAX_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_minHexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%x", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterHexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0x9abcdef";
	expect_len = 9;
	given_len = printf("%#x", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alter0HexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%#x", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0precision0HexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("%.0x", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterPrecisionHexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0x0009abcdef";
	expect_len = 12;
	given_len = printf("%#.10x", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterPaddHexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0x09abcdef";
	expect_len = 10;
	given_len = printf("%#010x", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alter0Precision0HexadecS(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("%#.0x", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_hexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "9ABCDEF";
	expect_len = 7;
	given_len = printf("%X", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_maxHexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "FFFFFFFF";
	expect_len = 8;
	given_len = printf("%X", (unsigned)MAX_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_minHexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%X", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterHexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0X9ABCDEF";
	expect_len = 9;
	given_len = printf("%#X", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alter0HexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0";
	expect_len = 1;
	given_len = printf("%#X", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0precision0HexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("%.0X", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterPrecisionHexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0X0009ABCDEF";
	expect_len = 12;
	given_len = printf("%#.10X", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alterPaddHexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0X09ABCDEF";
	expect_len = 10;
	given_len = printf("%#010X", 0x9aBcDeF);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_alter0Precision0HexadecB(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "";
	expect_len = 0;
	given_len = printf("%#.0X", MIN_UINT);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_pct(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "%";
	expect_len = 1;
	given_len = printf("%%");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_0paddNegInt(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "-0042";
	expect_len = 5;
	given_len = printf("%05i", -42);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_paddNegInt(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "  -42";
	expect_len = 5;
	given_len = printf("%5i", -42);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_precisionAtoiValue(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "%.0-5i";
	expect_len = 6;
	given_len = printf("%.-5i", -42);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_precisionNegInt(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "-00042";
	expect_len = 6;
	given_len = printf("%.5i", -42);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_precisionHexadec(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "0002a";
	expect_len = 5;
	given_len = printf("%.5x", 42);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_paddPct(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "%";
	expect_len = 1;
	given_len = printf("%-50%");
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_rightPaddChar(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = "a    ";
	expect_len = 5;
	given_len = printf("%-5c", 'a');
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL(expect_len, given_len);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void	test_printf_output(void)
{
	char	*expect;
	int		expect_len;
	int		given_len;

	expect = " 1 0 ";
	expect_len = 7;
	given_len = printf(" %c %c %c ", '1', '0', 0);
	ft_readBuffer(out, buf);
	ft_clearFile(file, out);
	TEST_ASSERT_EQUAL_STRING(expect, buf);
	TEST_ASSERT_EQUAL(expect_len, given_len);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_printf_NULL);
	RUN_TEST(test_printf_emptyString);
	RUN_TEST(test_printf_basicInput);
	RUN_TEST(test_printf_char);
	RUN_TEST(test_printf_nonPrintChar);
	RUN_TEST(test_printf_nonAsciiChar);
	RUN_TEST(test_printf_0char);
	RUN_TEST(test_printf_2char);
	RUN_TEST(test_printf_2charInStr);
	RUN_TEST(test_printf_str);
	RUN_TEST(test_printf_emptystr);
	RUN_TEST(test_printf_0str);
	RUN_TEST(test_printf_NULLstr);
	RUN_TEST(test_printf_paddNULLstr);
	RUN_TEST(test_printf_smallPrecisionNULLstr);
	RUN_TEST(test_printf_bigPrecisionNULLstr);
	RUN_TEST(test_printf_charstr);
	RUN_TEST(test_printf_ptr);
	RUN_TEST(test_printf_RNDptr);
	RUN_TEST(test_printf_0ptr);
	RUN_TEST(test_printf_NULLptr);
	RUN_TEST(test_printf_paddNULLptr);
	RUN_TEST(test_printf_0Iint);
	RUN_TEST(test_printf_maxIint);
	RUN_TEST(test_printf_minIint);
	RUN_TEST(test_printf_0Dint);
	RUN_TEST(test_printf_maxDint);
	RUN_TEST(test_printf_minDint);
	RUN_TEST(test_printf_sign0Dint);
	RUN_TEST(test_printf_sign0precision0Dint);
	RUN_TEST(test_printf_Uint);
	RUN_TEST(test_printf_maxUint);
	RUN_TEST(test_printf_minUint);
	RUN_TEST(test_printf_hexadecS);
	RUN_TEST(test_printf_maxHexadecS);
	RUN_TEST(test_printf_minHexadecS);
	RUN_TEST(test_printf_alterHexadecS);
	RUN_TEST(test_printf_alter0HexadecS);
	RUN_TEST(test_printf_0precision0HexadecS);
	RUN_TEST(test_printf_alterPrecisionHexadecS);
	RUN_TEST(test_printf_alterPaddHexadecS);
	RUN_TEST(test_printf_alter0Precision0HexadecS);
	RUN_TEST(test_printf_hexadecB);
	RUN_TEST(test_printf_maxHexadecB);
	RUN_TEST(test_printf_minHexadecB);
	RUN_TEST(test_printf_alterHexadecB);
	RUN_TEST(test_printf_alter0HexadecB);
	RUN_TEST(test_printf_0precision0HexadecB);
	RUN_TEST(test_printf_alterPrecisionHexadecB);
	RUN_TEST(test_printf_alterPaddHexadecB);
	RUN_TEST(test_printf_alter0Precision0HexadecB);
	RUN_TEST(test_printf_pct);
	RUN_TEST(test_printf_0paddNegInt);
	RUN_TEST(test_printf_paddNegInt);
	RUN_TEST(test_printf_precisionAtoiValue);
	RUN_TEST(test_printf_precisionNegInt);
	RUN_TEST(test_printf_precisionHexadec);
	RUN_TEST(test_printf_paddPct);
	RUN_TEST(test_printf_rightPaddChar);
	RUN_TEST(test_printf_output);
	// cp and sed test
	// check for precision - signs and spaces before int
	return (UNITY_END());
}
