/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addresslen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:21:14 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:09:40 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pointer_len(unsigned long long ptr)
{
	int len = 0;
	if (ptr == 0)
		return 1;
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return len;
}