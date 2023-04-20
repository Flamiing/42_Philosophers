/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:54:36 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/18 13:44:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* |~~~ INCLUDES ~~~| */
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data	t_data;

/* |~~~ PHILOSOPHER STRUCT ~~~| */
typedef struct s_philo
{
	int	max_meals;
	long long	time;
	long long	id;
	long long	right_fork;
	long long	left_fork;
	pthread_t	thread_id;
	pthread_t	death_check;
	struct timeval	start;
	struct timeval	last_meal;
	bool	is_alive;
	struct s_data	*data;
}	t_philo;

/* |~~~ DATA STRUCT ~~~| */
typedef struct s_data
{
	long long	philo_count;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	bool	philo_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	death;
	pthread_mutex_t	lock;
	t_philo		*list;
}	t_data;

/* |~~~ ERROR CODES ~~~| */
# define WRONG_NUMBER_ARGS 666
# define THREADS_FAILED 1
# define NO_ERROR 0
/* |~~~ ERROR MSGs ~~~| */
# define PARSING_ERROR "Wrong arguments passed or parsing error\n"
# define THREADS_ERROR "There was a problem with the threads\n"
/* |~~~ ACTIONS ~~~| */
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "died\n"

/* |~~~ PROTOTYPES ~~~| */
int		ft_how_to_use(void); 
int		ft_print_error(char	*error);
int		ft_not_dead(t_philo *philo);
int		ft_create_threads(t_philo *list, long long size);
int		ft_print_action(t_philo *philo, long long tm, long long id, char *does);

long long	ft_strlen(const char *s);
long long	ft_atoll(const char *string);
long long	ft_get_time(struct timeval start);
long long	ft_time_to_ms(struct timeval time);
long long	ft_usleep(long long ms);
long long	ft_time_elapsed(struct timeval start, struct timeval end);

void	ft_free_data(t_data *data);

void	*ft_tasks(void *arg);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free_and_return(t_data *data);

t_philo		*ft_create_list(t_data *data, long long size, char *optional_arg);

t_data		*ft_parser(char **args);
t_data		*ft_init_data(char **args);

#endif