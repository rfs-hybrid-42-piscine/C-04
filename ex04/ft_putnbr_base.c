/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:26:11 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/24 15:45:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @fn static int ft_is_base_valid(char *base)
 * @brief Validates the custom base alphabet.
 * @details A base is invalid if it is empty, length 1, contains duplicate 
 * characters, or contains '+' or '-'.
 * @param base The string representing the mathematical base.
 * @return 1 if valid, 0 if invalid.
 */
static int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @fn static void ft_putnbr_recursive(unsigned int nbr, char *base,
 * unsigned int len)
 * @brief Recursively prints the absolute number in the specified base.
 * @param nbr The absolute value of the number to print.
 * @param base The custom alphabet string.
 * @param len The length of the base.
 */
static void	ft_putnbr_recursive(unsigned int nbr, char *base, unsigned int len)
{
	if (nbr >= len)
		ft_putnbr_recursive(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

/**
 * @fn void ft_putnbr_base(int nbr, char *base)
 * @brief Prints an integer in a given custom base.
 * @details Validates the base, safely casts the integer to unsigned to avoid
 * overflow from INT_MIN, and initiates the recursive print.
 * @param nbr The number to print.
 * @param base The custom alphabet to use for output.
 */
void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	n;

	if (!ft_is_base_valid(base))
		return ;
	len = 0;
	while (base[len])
		len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-nbr);
	}
	else
		n = (unsigned int)nbr;
	ft_putnbr_recursive(n, base, len);
}
