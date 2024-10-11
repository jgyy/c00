/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:09:35 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/04 14:14:27 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_end(char *tab, int size)
{
	int	count;
	int	index;

	while (index < size)
	{
		if (tab[index] == '9')
			count++;
		index++;
	}
	if (count == size)
		return (1);
	else
		return (0);
}

void	ft_print_number(char *tab, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		ft_putchar(tab[index]);
		index++;
	}
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		index;

	index = 0;
	while (index < n)
		tab[index++] = '0';
	tab[index + 1] = '\0';
	while (ft_end(tab, n) != 1)
	{
		if (tab[n - 1] == '9')
		{
			index = n - 1;
			while (tab[index] == '9')
				index--;
			tab[index]++;
			index++;
			while (index < n)
				tab[index++] = '0';
		}
		else
			tab[n - 1]++;
		ft_print_number(tab, n);
	}
}
