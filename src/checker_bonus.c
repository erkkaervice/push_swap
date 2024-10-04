/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/08/19 15:19:15 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_compare(char *line, t_stack **sta, t_stack **stb)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa(sta);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sb(stb);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(sta, stb);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa(sta, stb);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pb(sta, stb);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra(sta);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rb(stb);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(sta, stb);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rra(sta);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrb(stb);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(sta, stb);
	else
		ft_error(sta, stb);
	return (0);
}

void	ft_arnew(int ac, char **av, char ***new_av)
{
	int	i;

	*new_av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!*new_av)
		ft_error(NULL, NULL);
	i = 0;
	while (i < ac)
	{
		(*new_av)[i] = av[i];
		i++;
	}
	(*new_av)[ac] = NULL;
}

void	ft_pipe(int ac, char **av, int *pipe_fd)
{
	pid_t	pid;
	char	**new_av;

	if (pipe(pipe_fd) == -1)
		ft_error(NULL, NULL);
	pid = fork();
	if (pid == -1)
		ft_error(NULL, NULL);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		ft_arnew(ac, av, &new_av);
		if (execvp("./push_swap", new_av) == -1)
		{
			free(new_av);
			ft_error(NULL, NULL);
		}
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_comparison(int fd, t_stack **sta, t_stack **stb)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_compare(line, sta, stb))
		{
			free(line);
			ft_error(sta, stb);
		}
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	int		fd;
	int		pipe_fd[2];

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_error(NULL, NULL);
	sta = ft_value(ac, av);
	if (!sta)
		ft_error(&sta, NULL);
	stb = NULL;
	ft_pipe(ac, av, pipe_fd);
	fd = pipe_fd[0];
	ft_comparison(fd, &sta, &stb);
	close(fd);
	if (ft_sorted(sta) && !stb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freee(&sta);
	ft_freee(&stb);
	return (0);
}
