/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:32:04 by mumutlu           #+#    #+#             */
/*   Updated: 2023/10/17 14:32:05 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	space_or_empty_check(char	**av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (!(av[i][j]))
			return 1;;
		while (av[i][j] && (av[i][j] == 32 
		|| (av[i][j] >= 9 && av[i][j] <= 13)))
		{
			if (av[i][j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	diff_char_check(char	**av)
{
	int	i;
	int	j;

	i = -1;
	if (space_or_empty_check(av))
		return (1);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if ((av[i][j + 1] == '\0' || (!(av[i][j + 1] >= '0' && \
					av[i][j + 1] <= '9'))) || (j > 0 && (!(av[i][j] == \
					'+' || av[i][j] == '-') || !(av[i][j - 1] == 32 \
					|| (av[i][j - 1] >= 9 && av[i][j - 1] <= 13)))))
					return (1);
			}
			else if (!(av[i][j] >= '0' && av[i][j] <= '9')
				&& !(av[i][j] == 32 || (av[i][j] >= 9 && av[i][j] <= 13)))
				return (1);
		}
	}
	return (0);
}
