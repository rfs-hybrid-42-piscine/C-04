/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:00 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/24 14:58:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn static int ft_is_base_valid(char *base)
 * @brief Validates the custom base alphabet for atoi processing.
 * @details Ensures no duplicates, no mathematical signs, and NO whitespaces.
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
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
 * @fn static int ft_get_base_index(char c, char *base)
 * @brief Finds the mathematical value of a character within the custom base.
 * @param c The character to search for.
 * @param base The custom alphabet string.
 * @return The index of the character, or -1 if the character is not in the base.
 */
static int	ft_get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @fn int ft_atoi_base(char *str, char *base)
 * @brief Converts a string in a custom base into a standard integer.
 * @details Parses leading whitespaces and signs. Accumulates the value of valid
 * base characters until an unrecognized character is encountered.
 * @param str The string to parse.
 * @param base The custom alphabet string.
 * @return The evaluated integer, or 0 if the base is invalid.
 */
int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	index;
	int	base_len;

	if (!ft_is_base_valid(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		index = ft_get_base_index(*str++, base);
		if (index == -1)
			break ;
		result = result * base_len + index;
	}
	return (result * sign);
}
