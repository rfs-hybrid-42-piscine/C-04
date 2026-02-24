/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:46:14 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/24 15:46:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX00
# define EX01
# define EX02
# define EX03
# define EX04
# define EX05
#endif

/* --- Prototypes --- */
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);

/* --- Main Testing Function --- */
int	main(void)
{
#ifdef EX00
	printf("--- EX00: ft_strlen ---\n");
	printf("Length of 'Hello': %d (Expected: 5)\n", ft_strlen("Hello"));
	printf("Length of '': %d (Expected: 0)\n\n", ft_strlen(""));
#endif

#ifdef EX01
	printf("--- EX01: ft_putstr ---\n");
	printf("Expected: Hello World!\n");
	printf("Result  : ");
	ft_putstr("Hello World!\n");
	printf("\n");
#endif

#ifdef EX02
	printf("--- EX02: ft_putnbr ---\n");
	printf("Expected: 42 | -42 | -2147483648 | 2147483647\n");
	printf("Result  : ");
	ft_putnbr(42);
	write(1, " | ", 3);
	ft_putnbr(-42);
	write(1, " | ", 3);
	ft_putnbr(-2147483648);
	write(1, " | ", 3);
	ft_putnbr(2147483647);
	printf("\n\n");
#endif

#ifdef EX03
	printf("--- EX03: ft_atoi ---\n");
	printf("String: ' ---+--+1234ab567' -> %d (Expected: -1234)\n", ft_atoi(" ---+--+1234ab567"));
	printf("String: '    +42' -> %d (Expected: 42)\n\n", ft_atoi("    +42"));
#endif

#ifdef EX04
	printf("--- EX04: ft_putnbr_base ---\n");
	printf("Decimal 42 in Binary (01)       : ");
	ft_putnbr_base(42, "01");
	printf(" (Expected: 101010)\n");
	
	printf("Decimal 255 in Hex (0123456789ABCDEF): ");
	ft_putnbr_base(255, "0123456789ABCDEF");
	printf(" (Expected: FF)\n");
	
	printf("Decimal -42 in Octal (poneyvif) : ");
	ft_putnbr_base(-42, "poneyvif");
	printf(" (Expected: -vno)\n");
	
	printf("Invalid base (empty)            : ");
	ft_putnbr_base(42, "");
	printf(" (Expected: nothing)\n\n");
#endif

#ifdef EX05
	printf("--- EX05: ft_atoi_base ---\n");
	printf("Binary '101010' to Dec      : %d (Expected: 42)\n", ft_atoi_base("101010", "01"));
	printf("Hex 'FF' to Dec             : %d (Expected: 255)\n", ft_atoi_base("FF", "0123456789ABCDEF"));
	printf("Octal '  ---+--+vno' to Dec : %d (Expected: -42)\n", ft_atoi_base("  ---+--+vno", "poneyvif"));
	printf("Invalid Base '012+3'        : %d (Expected: 0)\n\n", ft_atoi_base("FF", "012+3"));
#endif

	return (0);
}
