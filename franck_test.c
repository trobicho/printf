#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	char lol[] = "salut";
	char mdr[] = "ok";

	(void) argc;
	(void) argv;

	ft_printf("ft = _%s_\n", NULL);
	printf("lc = _%s_\n", NULL);

	ft_printf("lolßœ∑´Ω≈ç∂ƒ®©®øˆ∆†    %s\n", "ππ¨©µ˜µ∫∫–ª•¢§¢¶•º45÷÷≥≤æ»'´ÔÓ");

	ft_printf("-%8.3f-\n", 5.126);

	ft_printf("ft = _%f_%f_%.0f_%f_%f_%f_\n", 156., 18446744073709550000., 184.6, 28446744073709551615., 98446744073709551615., 10000000000000000000000000.);
	printf("lc = _%f_%f_%.0f_%f_%f_%f_\n", 156., 18446744073709550000., 184.6, 28446744073709551615., 98446744073709551615., 10000000000000000000000000.);
	ft_printf("ft = _% .1f_%+ f_%010.2f_%f_%.f_%#.f_%f_%f_%f_\n", 1.6, 5., 1.23456, 2., 2., 2., 5., 5.5, 5.55555555555555555);
	printf("lc = _% .1f_%+ f_%010.2f_%f_%.f_%#.f_%f_%f_%f_\n", 1.6, 5., 1.23456, 2., 2., 2., 5., 5.5, 5.55555555555555555);

	ft_printf("ft = _%d_%d_% d_% d_%+d_%+d_% +d_% +d_\n", 10, -10, 10, -10, 10, -10, 10, -10);
	printf("lc = _%d_%d_% d_% d_%+d_%+d_% +d_% +d_\n", 10, -10, 10, -10, 10, -10, 10, -10);

	ft_printf("ft = _% 4d_% 4d_% 04d_% 04d_% .0d_% .0d_% .2d_% .2d_% .3d_% .3d_% .4d_% .4d_\n", 10, -10, 10, -10, 10, -10, 10, -10, 10, -10, 10, -10);
	printf("lc = _% 4d_% 4d_% 04d_% 04d_% .0d_% .0d_% .2d_% .2d_% .3d_% .3d_% .4d_% .4d_\n", 10, -10, 10, -10, 10, -10, 10, -10, 10, -10, 10, -10);

	ft_printf("ft = _%p_%20p_%#p_%.2p_%020p_%.20p_\n", lol, mdr, lol, mdr, lol, mdr);
	printf("lc = _%p_%20p_%#p_%.2p_%020p_%.20p_\n", lol, mdr, lol, mdr, lol, mdr);

	ft_printf("ft = _%+u_% u_\n", 123, 123);
	printf("lc = _%+u_% u_\n", 123, 123);
	ft_printf("ft = _%'u_%15'u_%20.10'u_%015'u_\n", 1234567, 1234567, 1234567, 1234567);

	ft_printf("ft = _%o_%o_%#o_%#o_%.2o_%.2o_%#.3o_%#.3o_%05o_%05#o_%05.3o_%5#o_\n", 0, 10, 0, 10, 0, 10, 0, 10, 10, 10, 10, 10);
	printf("lc = _%o_%o_%#o_%#o_%.2o_%.2o_%#.3o_%#.3o_%05o_%05#o_%05.3o_%5#o_\n", 0, 10, 0, 10, 0, 10, 0, 10, 10, 10, 10, 10);

	ft_printf("ft = _%x_%x_%#x_%#x_%.2x_%.2x_%#.3x_%#.3x_%08x_%08#x_%08.3x_%8#x_\n", 0, 20, 0, 20, 0, 20, 0, 20, 20, 20, 20, 20);
	printf("lc = _%x_%x_%#x_%#x_%.2x_%.2x_%#.3x_%#.3x_%08x_%08#x_%08.3x_%8#x_\n", 0, 20, 0, 20, 0, 20, 0, 20, 20, 20, 20, 20);
	ft_printf("ft = _%X_%X_%#X_%#X_%.2X_%.2X_%#.3X_%#.3X_%08X_%08#X_%08.3X_%8#X_\n", 0, 20, 0, 20, 0, 20, 0, 20, 20, 20, 20, 20);
	printf("lc = _%X_%X_%#X_%#X_%.2X_%.2X_%#.3X_%#.3X_%08X_%08#X_%08.3X_%8#X_\n", 0, 20, 0, 20, 0, 20, 0, 20, 20, 20, 20, 20);

	ft_printf("ft = _%.0u_%_.0u_%.1u_%_.1u_%u_%u_\n", 0, 5, 0, 5, 0, 5);
	printf("lc = _%.0u_%_.0u_%.1u_%_.1u_%u_%u_\n", 0, 5, 0, 5, 0, 5);
	ft_printf("ft = _%010u_%_010u_%10.5u_%010.5u_%_10.5u_%_010.5u_%05.2u_\n", 123, 123, 123, 123, 123, 123, 123);
	printf("lc = _%010u_%_010u_%10.5u_%010.5u_%_10.5u_%_010.5u_%05.2u_\n", 123, 123, 123, 123, 123, 123, 123);

	ft_printf("ft = _%s_%s_\n", "bonjour", lol);
	printf("lc = _%s_%s_\n", "bonjour", lol);

	ft_printf("ft = _%15s_%3s_%.15s_%.3s_%.0s_%.s_\n", "bonjour", "machin", lol, "arfnonnon", "okbonjour", "okbonjour");
	printf("lc = _%15s_%3s_%.15s_%.3s_%.0s_%.s_\n", "bonjour", "machin", lol, "arfnonnon", "okbonjour", "okbonjour");

	ft_printf("ft = _%s_%5.5s_%_5s_%.s_%.0s_%05s_%0_5s_%.*s_%*s_\n", mdr, mdr, mdr, mdr, mdr, mdr, mdr, 1, mdr, 5, mdr);
	printf("lc = _%s_%5.5s_%_5s_%.s_%.0s_%05s_%0_5s_%.*s_%*s_\n", mdr, mdr, mdr, mdr, mdr, mdr, mdr, 1, mdr, 5, mdr);

	ft_printf("ft = _%c_%5.5c_%_5c_%.c_%.0c_%05c_%0_5c_%.*c_%*c_%c_%.c_%.0c_\n", 'a', 'b', mdr[0], 'd', 'e', 'f', 'g', 1, lol[0], 5, 'i', 74, 'k', 'l');
	printf("lc = _%c_%5.5c_%_5c_%.c_%.0c_%05c_%0_5c_%.*c_%*c_%c_%.c_%.0c_\n", 'a', 'b', mdr[0], 'd', 'e', 'f', 'g', 1, lol[0], 5, 'i', 74, 'k', 'l');

	ft_printf("ft = _%010.5s_\n", "bonjouroutlemonde");
	printf("lc = _%010.5s_\n", "bonjouroutlemonde");

	ft_printf("ft = _%hhlh^_%5.5^_%_5^_%.^_%.0^_%05^_%0_5^_%2h3^_\n");
	printf("lc = _%hhlh^_%5.5^_%_5^_%.^_%.0^_%05^_%0_5^_%2h3^_\n");

	ft_printf("ft = _%hhlh%_%5.5%_%_5%_%.%_%.0%_%05%_%0_5%_%2h3%_\n");
	printf("lc = _%hhlh%_%5.5%_%_5%_%.%_%.0%_%05%_%0_5%_%2h3%_\n");

	ft_printf("ft = mdr_%");
	ft_printf("_\n");
	printf("lc = mdr_%");
	printf("_\n");

	ft_printf("ft = lol_%5hhhhhlhhhh");
	ft_printf("_\n");
	printf("lc = lol_%5hhhhhlhhhh");
	printf("_\n");
	return (0);
}
