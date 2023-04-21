/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:09:10 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/21 18:10:19 by alaaouam         ###   ########.fr       */
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

/* |~~~ BOOLEANS ~~~| */
# define TRUE 1
# define FALSE 1
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

typedef struct s_data	t_data;
/* |~~~ PHILOSOPHER STRUCT ~~~| */
typedef struct s_philo
{
	long long	id;
	long long	meal_count;
	long long	right_fork;
	long long	left_fork;
	long long	start;
	long long	last_meal;
	pthread_t	thread_id;
	struct s_data	*data;
}	t_philo;

/* |~~~ DATA STRUCT ~~~| */
typedef struct s_data
{
	long long	philo_count;
	long long	max_meals;
	long long	have_to_eat;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	int		philo_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	death;
	t_philo		*list;
}	t_data;

/* |~~~ PROTOTYPES ~~~| */
int	ft_how_to_use(void);
int	ft_print_error(char	*error);
int	ft_create_threads(t_philo *list, long long size);
int	ft_print_action(t_philo *philo, char *does);

long long	ft_gettime(void);
long long	ft_time(t_philo *philo);
long long	ft_strlen(const char *s);
long long	ft_atoll(const char *string);

void		ft_free_data(t_data *data);

void		*ft_tasks(void *arg);
void		ft_usleep(long long ms);
void		*ft_calloc(size_t count, size_t size);
void		*ft_free_and_return(t_data *data);

t_philo		*ft_create_list(t_data *data, long long size);

t_data		*ft_parser(char **args);
t_data		*ft_init_data(char **args);

#endif
