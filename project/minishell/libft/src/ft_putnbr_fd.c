/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:49:55 by mmacedo-          #+#    #+#             */
/*   Updated: 2024/12/07 18:40:33 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;

	numb = n;
	if (numb < 0)
	{
		ft_putchar_fd('-', fd);
		numb = numb * -1;
	}
	if (numb >= 0 && numb <= 9)
	{
		ft_putchar_fd(numb + '0', fd);
	}
	if (numb > 9)
	{
		ft_putnbr_fd(numb / 10, fd);
		ft_putnbr_fd(numb % 10, fd);
	}
}
