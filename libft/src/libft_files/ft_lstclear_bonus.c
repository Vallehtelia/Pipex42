/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:48:57 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/19 17:48:59 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next_node;

	if (!del || !lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next_node = temp->next;
		ft_lstdelone(temp, *del);
		temp = next_node;
	}
	*lst = NULL;
}
