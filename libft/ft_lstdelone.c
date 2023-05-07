/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/04 15:48:41 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL )
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
	return ;
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  ft_lstnew(malloc(1));
// 	ft_lstdelone(l, free);

// 	return (0);
// }