/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:40:01 by mumutlu           #+#    #+#             */
/*   Updated: 2023/10/17 12:42:51 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_mutex
{
	pthread_mutex_t	mutex_id;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	eat_mutex;
	int				i_m;
}	t_mutex;

typedef struct s_vars
{
	int		n_of_philo;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		eat_per_phil;
}	t_vars;

typedef struct s_philo
{
	pthread_t	thread;
	t_mutex		mutex;
	t_vars		vars;
	t_time		time_start;
	t_time		time_end;
	t_time		starving_start;
	t_time		starving_end;
	int			current_time;
	int			die_time;
	int			is_died;
}	t_philo;

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

int		space_or_empty_check(char	**av);
int		diff_char_check(char	**av);

int		ft_philo_create(t_philo *philo);
void	*ft_life_cycle(t_philo *philo);

int		ft_detach_pthread(t_philo *philo);

int		ft_current_time(t_philo *philo);
int		ft_die_time(t_philo *philo);
int		ft_starve_time(t_philo *philo);
void	ft_usleep(int time);

int		ft_died_check(t_philo *philo);
int		ft_last_eat_check(t_philo *philo);
int		ft_starve_time_check(t_philo *philo, int i);

#endif
