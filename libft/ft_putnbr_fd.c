/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:50:34 by alam              #+#    #+#             */
/*   Updated: 2016/11/03 16:50:35 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		neg_check(int num, int *minflag, int fd)
{
	if (num < 0)
	{
		if (num == -2147483648)
		{
			*minflag = 1;
			num++;
			ft_putchar_fd('-', fd);
			num *= -1;
		}
		else
		{
			ft_putchar_fd('-', fd);
			num *= -1;
			*minflag = 0;
		}
	}
	else
		*minflag = 0;
	return (num);
}

static	void	print_loop(int i, char number[], int fd)
{
	int msd_found;

	msd_found = 0;
	while (i > 0)
	{
		if (((i - 1) == 0) && (msd_found == 0))
		{
			ft_putchar_fd(number[i - 1], fd);
			i--;
		}
		else if ((number[i - 1] != '0') && (msd_found == 0))
		{
			msd_found = 1;
		}
		else if (msd_found)
		{
			ft_putchar_fd(number[i - 1], fd);
			i--;
		}
		else
		{
			i--;
		}
	}
	return ;
}

void			ft_putnbr_fd(int n, int fd)
{
	char	number[10];
	int		i;
	int		j;
	int		msd_found;
	int		minflag;

	i = 10;
	j = 0;
	msd_found = 0;
	n = neg_check(n, &minflag, fd);
	while (j < 10)
	{
		number[j] = (n % 10) + 48;
		n /= 10;
		if (minflag)
		{
			number[0]++;
			minflag = 0;
		}
		j++;
	}
	print_loop(i, number, fd);
	return ;
}
