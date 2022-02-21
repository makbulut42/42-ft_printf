/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:39:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/02/10 01:39:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char str, va_list variable)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(variable, int));
	else if (str == 's')
		count += ft_str(va_arg(variable, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(variable, int), 10, 0);
	else if (str == 'x')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 0);
	else if (str == 'X')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 1);
	else if (str == 'u')
		count += ft_putnbr(va_arg(variable, unsigned int), 10, 0);
	else if (str == 'p')
		count += ft_pointer(va_arg(variable, unsigned long), 16, 0);
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	variable;
	int		count;

	count = 0;
	va_start(variable, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_control(*(str + 1), variable);
			str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(variable);
	return (count);
}

// int main()
// {
// 	int orj;
// 	int my;

// 	my = ft_printf("%1c\n", 'a');
// 	orj = printf("%1c\n", 'a');
// 	// my = ft_printf("sayi: %s\n\n", "ruveyda");
// 	// orj =   printf("sayi: %s\n\n", "ruveyda");
// 	printf("orj: %d --- my: %d", orj, my);
// }