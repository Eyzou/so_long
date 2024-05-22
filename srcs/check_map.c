/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:11 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 16:33:35 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_elements(t_data *game)
{
	count_elements(game);
	if (game->collectible_num < 1 || game->player_num < 1 || game->exit_num < 1)
	{
		ft_printf("Error!\nSome elements of the game are missing\n");
		return (1);
	}
	if (game->player_num > 1 || game->exit_num > 1)
	{
		ft_printf("Error!\nThere is a doublon on the map\n");
		return (1);
	}
	return (0);
}

int	check_around_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->colls_num)
	{
		if (game->map[0][i] != '1')
			return (1);
		if (game->map[game->row_num - 1][i] != '1')
			return (1);
		i++;
	}
	if (game->colls_num < 3)
		return (1);
	j = 1;
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][game->colls_num - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_map(t_data *game)
{
	if (check_rectangle(game) == 1)
	{
		ft_printf("Error!\nThe map is not a rectangle!\n");
		return (1);
	}
	if (check_around_map(game) == 1)
	{
		ft_printf("Error!\nThe map should be surronded by trees-souches!\n");
		return (1);
	}
	if (check_char(game) == 1)
	{
		ft_printf("Error!\nInvalid character in the map\n");
		return (1);
	}
	if (check_elements(game) == 1)
		return (1);
	return (0);
}
