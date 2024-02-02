/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:04:38 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:14:14 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX || size * nmemb >= SIZE_MAX)
		return (NULL);
	dest = malloc(nmemb * size);
	if (dest == NULL)
		return (NULL);
	ft_memset((unsigned char *)dest, 0, size * nmemb);
	return (dest);
}
/*int main()
{
    void *str;
    str = ft_calloc(SIZE_MAX + 1, SIZE_MAX);
    free(str);
    return (0);
}*/