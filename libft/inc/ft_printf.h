/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:56:02 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/22 13:56:04 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_ret
{
	int	output_count;
	int	error_return;
}	t_ret;

int		ft_printf(const char *s, ...);
void	ft_format_check(va_list args, char spec, t_ret *ret);
void	ft_print_char(int c, t_ret *ret);
void	ft_print_str(char *s, t_ret *ret);
void	ft_print_unsigned_decimal(unsigned int c, t_ret *ret);
void	ft_print_ptr(unsigned long long ptr, t_ret *ret);
void	ft_print_hex_lower(unsigned long long ptr, t_ret *ret);
void	ft_print_hex_upper(unsigned int nbr, t_ret *ret);
void	ft_print_decimal(long long nbr, t_ret *ret);

#endif