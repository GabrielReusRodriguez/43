/* ************************************************************************** */
/*                                                                            */
/*   test_ft_printf.c — compara ft_printf con printf (glibc)                   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ft_printf.h"

static int	g_ok;
static int	g_fail;

static void	check(const char *label, int r_ref, int r_ft, const char *ref,
		const char *mine)
{
	if (r_ref == r_ft && strcmp(ref, mine) == 0)
	{
		g_ok++;
		return ;
	}
	g_fail++;
	fprintf(stderr, "FAIL: %s\n", label);
	fprintf(stderr, "  ref ret=%d out=\"%s\"\n", r_ref, ref);
	fprintf(stderr, "  ft  ret=%d out=\"%s\"\n", r_ft, mine);
}

#define CAPTURE(fn, buf, buflen, ret, fmt, ...) \
	do { \
		int		_p[2]; \
		int		_saved; \
		ssize_t	_n; \
		\
		memset((buf), 0, (buflen)); \
		if (pipe(_p) < 0) \
		{ \
			(ret) = -1; \
			break ; \
		} \
		_saved = dup(STDOUT_FILENO); \
		dup2(_p[1], STDOUT_FILENO); \
		close(_p[1]); \
		(ret) = fn(fmt, ##__VA_ARGS__); \
		fflush(stdout); \
		dup2(_saved, STDOUT_FILENO); \
		close(_saved); \
		_n = read(_p[0], (buf), (buflen) - 1); \
		close(_p[0]); \
		if (_n < 0) \
			_n = 0; \
		(buf)[_n] = '\0'; \
	} while (0)

#define TEST(label, fmt, ...) \
	do { \
		char	_ref[8192]; \
		char	_mine[8192]; \
		int		_r1; \
		int		_r2; \
		\
		CAPTURE(printf, _ref, sizeof(_ref), _r1, fmt, ##__VA_ARGS__); \
		CAPTURE(ft_printf, _mine, sizeof(_mine), _r2, fmt, ##__VA_ARGS__); \
		check((label), _r1, _r2, _ref, _mine); \
	} while (0)

int	main(void)
{
	int		n;
	char	*s;
	char	*null_s;
	void	*p;

	g_ok = 0;
	g_fail = 0;
	null_s = NULL;

	/* --- Obligatorio: literales y %% --- */
	TEST("literal", "hola mundo");
	TEST("percent", "%%");
	TEST("percent2", "%% %%");
	TEST("mixed_pct", "100%% done");

	/* --- %c --- */
	TEST("c_a", "%c", 'a');
	TEST("c_zero", "%c", '\0');
	TEST("c_nl", "%c", '\n');
	TEST("c_mix", "x%cy", 'Z');

	/* --- %s --- */
	TEST("s_hello", "%s", "hello");
	TEST("s_empty", "%s", "");
	TEST("s_null", "%s", null_s);
	TEST("s_mix", "<%s>", "42");

	/* --- %d / %i --- */
	TEST("d_0", "%d", 0);
	TEST("d_42", "%d", 42);
	TEST("d_neg", "%d", -42);
	TEST("d_max", "%d", INT_MAX);
	TEST("d_min", "%d", INT_MIN);
	TEST("i_42", "%i", 42);
	TEST("i_neg", "%i", -1);

	/* --- %u --- */
	TEST("u_0", "%u", 0u);
	TEST("u_42", "%u", 42u);
	TEST("u_max", "%u", UINT_MAX);

	/* --- %x / %X --- */
	TEST("x_0", "%x", 0u);
	TEST("x_42", "%x", 42u);
	TEST("x_ff", "%x", 0xffu);
	TEST("x_max", "%x", UINT_MAX);
	TEST("X_42", "%X", 42u);
	TEST("X_ff", "%X", 0xabcdu);

	/* --- %p --- */
	n = 42;
	p = &n;
	TEST("p_stack", "%p", p);
	TEST("p_null", "%p", (void *)NULL);
	TEST("p_heapish", "%p", (void *)0xdeadbeefUL);

	/* --- combinaciones obligatorias --- */
	TEST("combo1", "c=%c s=%s d=%d", 'A', "str", -7);
	TEST("combo2", "u=%u x=%x X=%X", 255u, 255u, 255u);
	TEST("combo3", "p=%p %%", p);

	/* --- Bonus básicos (si están, deben coincidir) --- */
	TEST("width_d", "%5d", 42);
	TEST("width_left", "%-5d", 42);
	TEST("zero_d", "%05d", 42);
	TEST("prec_d", "%.5d", 42);
	TEST("prec_0", "%.0d", 0);
	TEST("prec_s", "%.3s", "abcdef");
	TEST("plus_d", "%+d", 42);
	TEST("plus_neg", "%+d", -42);
	TEST("space_d", "% d", 42);
	TEST("hash_x", "%#x", 42u);
	TEST("hash_X", "%#X", 42u);
	TEST("hash_0", "%#x", 0u);
	TEST("width_s", "%10s", "hi");
	TEST("width_c", "%5c", 'Z');
	TEST("mix_bonus", "%+08d", 42);
	TEST("mix_hex", "%#08x", 42u);
	TEST("prec_hash_x", "%#.8x", 42u);
	TEST("hash_width_x", "%#8x", 42u);
	TEST("prec_width", "%8.5d", 42);
	TEST("prec_width_neg", "%8.5d", -42);

	s = "Barcelona";
	TEST("long_s", ">%s<", s);

	fprintf(stderr, "\n=== ft_printf: %d ok, %d fail ===\n", g_ok, g_fail);
	return (g_fail != 0);
}
