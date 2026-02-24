/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:26:03 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/24 14:13:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @fn void ft_putstr(char *str)
 * @brief Prints a null-terminated string to the standard output.
 * @details Includes a safety check to prevent dereferencing a NULL pointer.
 * Uses pointer arithmetic to iterate through the memory addresses, writing 
 * each character to file descriptor 1 until the null byte is reached.
 * @param str A pointer to the first character of the string to be printed.
 */
void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}
