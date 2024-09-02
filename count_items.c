/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:05:06 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 14:05:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_items(char **map, char item)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == item)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
