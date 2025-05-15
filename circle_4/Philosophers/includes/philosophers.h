/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:54:14 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/23 00:42:52 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "%ld %d has taken a fork\n"
# define EAT "%ld %d is eating\n"
# define SLEEP "%ld %d is sleeping\n"
# define THINK "%ld %d is thinking\n"
# define DEAD "%ld %d died\n"
# define ALLFINISH "%ld All the philosophers have eaten\n"

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	int				count_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	long			nbr_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			start_time;
	long			nbr_meals;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	check_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_t		*threads;
	t_philo			*philos;
}					t_data;

/*  ACTION  */

/*  CHECK_ARG  */
int					check_is_numeric(char *str);
int					check_int(char **av);
int					check_arg(char **av);

/*  DIE  */
int					mutex_death(t_data *data_philo, int i);
int					check_philo(t_data *data_philo, int i, int *end);
void				check_monitor(t_data *data_philo);
int					check_end(t_data *data_philo, int end);

/*  EAT  */
void				eating(t_philo *philo);
int					end_eating(t_philo *philo);

/*  FORK  */
void				take_fork(t_philo *philo);
void				end_fork(t_philo *philo);

/*  FREE  */
void				ft_free(t_data *data_philo);

/*  INIT_VAR  */
void				init_var(t_data *data_philo, t_philo *philo);
int					init_data(char **av, t_data *data_philo);

/*  PRINT_MSG  */
void				print_msg(int msg, t_philo *philo, int id);

/*  PROCESS  */
int					one_philo(t_philo *philo);
int					philo_fork_n_eat(t_philo *philo);
void				*philo(void *arg);
int					init_process(t_data *data_philo);
int					ft_process(t_data *data_philo);

/*  SLEEP  */
void				ft_sleep(long timer_sleep);

/*  THINK  */

/*  TIMER  */
long				ft_timer(void);

/*  UTILS  */
long				ft_atol(char *str);
int					check_stop(t_philo *philo);
void				set_stop(t_data *data_philo);

#endif