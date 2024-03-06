/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:25:32 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/10 15:25:36 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_intmin(int n)
{
	char	*minstr;
	int		num;
	long	mint;
	int		temp;

	minstr = malloc(12);
	if (!minstr)
		return (NULL);
	mint = n;
	num = 11;
	minstr[11] = '\0';
	minstr[0] = '-';
	num--;
	while (num > 0)
	{
		temp = mint % 10;
		temp = -temp;
		minstr[num] = temp + '0';
		mint = mint / 10;
		num--;
	}
	return (minstr);
}

static char	*ft_ptralloc(char *ptr, int count, int n)
{
	if (n >= 0)
	{
		ptr[count + 1] = '\0';
		while (count >= 0)
		{
			ptr[count] = '0' + (n % 10);
			n = n / 10;
			count--;
		}
	}
	else
	{
		ptr[count + 1] = '\0';
		n = n * -1;
		while (count >= 1)
		{
			ptr[count] = '0' + (n % 10);
			n = n / 10;
			count--;
		}
	}
	return (ptr);
}

static char	*ft_iszero(void)
{
	char	*zero;

	zero = malloc(2);
	if (!zero)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

static int	ft_numcount(int n, int len)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		len = len * -1;
		l++;
	}
	while (len >= 10)
	{
		len = len / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		count;

	if (n == -2147483648)
		return (ft_intmin(n));
	if (n == 0)
		return (ft_iszero());
	len = n;
	count = ft_numcount(n, len);
	if (n > 0)
		ptr = malloc(count + 2);
	else
		ptr = malloc(count + 2);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
	}
	ptr = ft_ptralloc(ptr, count, n);
	return (ptr);
}
