/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:32:27 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/24 14:52:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @fn void ft_putnbr(int nb)
 * @brief Prints any valid integer to the standard output.
 * @details Casts the absolute value to an unsigned int to safely prevent
 * integer overflow from INT_MIN. Uses recursive division to isolate digits.
 * @param nb The integer to print.
 */
void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-nb);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
