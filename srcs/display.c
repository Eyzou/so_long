/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:17:52 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/28 10:17:23 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_foot(int key, t_data *game)
{
	int		i;
	int		j;
	int		moves;
	char	**map;

	map = game->map;
	moves = game->moves;
	i = game->x;
	j = game->y;
	if (is_down(key) && map[j + 1][i] != '1' && map[j + 1][i] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_up(key) && map[j - 1][i] != '1' && map[j - 1][i] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_right(key) && map[j][i + 1] != '1' && map[j][i + 1] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_left(key) && map[j][i - 1] != '1' && map[j][i - 1] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
}
