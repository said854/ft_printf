/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:19:54 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:12:05 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_unsint_len(unsigned int n)
{
	int len = 0;
	if (n == 0)
		return 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return len;
}