/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_output_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:22:58 by alam              #+#    #+#             */
/*   Updated: 2017/02/01 16:23:06 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append_flags(char *str, char sign, t_mod mods, int out_len)
{
	int		i;
	int		num_len;
	char	*out;

	i = 0;
	num_len = (str[0] == '-') ? ft_strlen(str) - 1 : ft_strlen(str);
	if ((mods.flags & LEADING_0X) && (mods.spec == 'o' || mods.spec == 'O'))
		num_len += get_prefix_len(mods);
	out = ft_memalloc(sizeof(char) * out_len);
	if (sign > 0)
		out[0] = sign;
	while (i < mods.precision - num_len)
	{
		ft_strlcat(out, "0", out_len);
		i++;
	}
	if (str[0] == '-')
		ft_strlcat(out, str + 1, out_len);
	else
		ft_strlcat(out, str, out_len);
	out[out_len - 1] = 0;
	return (out);
}

char	*check_mods(char *str, t_mod mods)
{
	int		num_len;
	int		out_len;
	char	sign;
	char	*out;

	num_len = (str[0] == '-') ? ft_strlen(str) - 1 : ft_strlen(str);
	sign = (str[0] == '-') ? '-' : 0;
	out_len = (mods.precision >= 0 && mods.precision > num_len) ?
				mods.precision + 1 : ft_strlen(str) + 1;
	if ((mods.flags & PLUS_SIGN) && sign != '-')
		sign = '+';
	else if ((mods.flags & SPACE) && sign != '-')
		sign = ' ';
	if (sign != 0 && is_signed_spec(mods.spec))
		out_len++;
	out = append_flags(str, sign, mods, out_len);
	if (ft_strcmp(out, "0") == 0 && mods.precision == 0)
		out[0] = 0;
	free(str);
	return (out);
}

void	write_number_output(char *num, t_mod m, int pad_len, int prefix_len)
{
	int		prefix_skip;
	int		sign_skip;
	char	pad_char;

	prefix_skip = 0;
	sign_skip = 0;
	pad_char = (m.flags & LEFT_PAD_ZERO) ? '0' : ' ';
	if (prefix_len != 0 && (m.flags & LEFT_PAD_ZERO))
		prefix_skip = print_octhex_prefix(m);
	if (!(m.flags & LEFT_JUSTIFY))
	{
		if (m.width >= 0 && m.precision < 0 && (m.flags & LEFT_PAD_ZERO) &&
			(num[0] == '-' || num[0] == ' ' || num[0] == '+'))
			sign_skip = ft_putchar(num[0]);
		pad_len = pad_output(pad_len, pad_char);
	}
	if (prefix_len != 0 && prefix_skip == 0)
		print_octhex_prefix(m);
	if (ft_strcmp(num, "0") == 0 && m.precision == 0)
		num[0] = 0;
	ft_putstr(num + sign_skip);
	pad_output(pad_len, ' ');
	free(num);
}

int		format_number_output(char *str, t_mod mods)
{
	int		pad_len;
	int		prefix_len;
	int		output_length;
	char	*num;

	pad_len = 0;
	prefix_len = 0;
	if ((mods.flags & LEADING_0X) && ft_strcmp(str, "0") != 0)
		prefix_len = get_prefix_len(mods);
	else if ((mods.flags & LEADING_0X) &&
				(mods.spec == 'o' || mods.spec == 'O') && mods.precision >= 0)
		prefix_len = get_prefix_len(mods);
	else if (mods.spec == 'p')
		prefix_len = get_prefix_len(mods);
	num = check_mods(str, mods);
	if (((int)ft_strlen(num) + prefix_len) < mods.width)
		pad_len = mods.width - (ft_strlen(num) + prefix_len);
	if (mods.spec == 'x' || mods.spec == 'p')
		ft_strlower(num);
	write_number_output(num, mods, pad_len, prefix_len);
	output_length = ft_strlen(num) + pad_len + prefix_len;
	return (output_length);
}
