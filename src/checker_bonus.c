/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:29:55 by eala-lah          #+#    #+#             */
/*   Updated: 2024/12/05 14:32:02 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
 * ft_compare - Processes a command and applies it to the stacks.
 *
 * This function reads an operation from the input and applies the appropriate
 * transformation to the stacks. Supported operations include:
 * - "sa", "sb", "ss": Swap operations for one or both stacks.
 * - "pa", "pb": Push operations to transfer values between stacks.
 * - "ra", "rb", "rr": Rotate operations for one or both stacks.
 * - "rra", "rrb", "rrr": Reverse rotate operations for one or both stacks.
 *
 * If the command is invalid, the function triggers an error by calling 
 * `ft_errorr()`, terminating the program.
 *
 * Parameters:
 * - line: The command string to process.
 * - sta: Pointer to the main stack.
 * - stb: Pointer to the auxiliary stack.
 *
 * Returns:
 * - Always 0, as the function does not produce a meaningful result.
 */
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
		ft_errorr(sta, stb);
	return (0);
}

/*
 * ft_arnew - Creates a duplicate argument array for child process execution.
 *
 * This function dynamically allocates a new array of strings, copying the 
 * arguments passed to the program. The resulting array is terminated by a 
 * `NULL` pointer, ensuring compatibility with standard C-style argument arrays.
 *
 * This function is critical for safe execution of the push_swap program in 
 * a separate process, as it isolates the memory usage of the argument array.
 *
 * Parameters:
 * - ac: The number of arguments to copy.
 * - av: The original argument array.
 * - new_av: Pointer to the allocated array, populated with duplicates of `av`.
 */
void	ft_arnew(int ac, char **av, char ***new_av)
{
	int	i;

	*new_av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!*new_av)
		ft_errorr(NULL, NULL);
	i = 0;
	while (i < ac)
	{
		(*new_av)[i] = av[i];
		i++;
	}
	(*new_av)[ac] = NULL;
}

/*
 * ft_pipe - Sets up interprocess communication and executes push_swap.
 *
 * This function creates a pipe and forks a new process. The child process 
 * executes the `push_swap` program, redirecting its output to the write end 
 * of the pipe. The parent process reads this output for further processing.
 *
 * On failure (e.g., inability to fork or create the pipe), the function 
 * triggers `ft_errorr()`, ensuring the program terminates safely.
 *
 * Parameters:
 * - ac: The number of arguments passed to push_swap.
 * - av: The argument vector for the program.
 * - pipe_fd: File descriptor array for the pipe.
 */
void	ft_pipe(int ac, char **av, int *pipe_fd)
{
	pid_t	pid;
	char	**new_av;

	if (pipe(pipe_fd) == -1)
		ft_errorr(NULL, NULL);
	pid = fork();
	if (pid == -1)
		ft_errorr(NULL, NULL);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		ft_arnew(ac, av, &new_av);
		if (execvp("./push_swap", new_av) == -1)
		{
			free(new_av);
			ft_errorr(NULL, NULL);
		}
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}

/*
 * ft_comparison - Reads and executes commands from a file descriptor.
 *
 * This function processes commands line-by-line, calling `ft_compare()` to 
 * execute each operation on the provided stacks. It ensures that the input 
 * sequence is valid, triggering `ft_errorr()` for any invalid command.
 *
 * Parameters:
 * - fd: The file descriptor to read commands from.
 * - sta: Pointer to the main stack.
 * - stb: Pointer to the auxiliary stack.
 */
void	ft_comparison(int fd, t_stack **sta, t_stack **stb)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_compare(line, sta, stb))
		{
			free(line);
			ft_errorr(sta, stb);
		}
		free(line);
		line = get_next_line(fd);
	}
}

/*
 * main - Entry point for the checker program.
 *
 * The program validates input arguments, initializes stacks, and processes 
 * commands using a pipe to communicate with the push_swap program. Once all 
 * commands are executed, the program verifies if the main stack is sorted and 
 * the auxiliary stack is empty, printing "OK" or "KO" accordingly.
 *
 * Parameters:
 * - ac: The number of arguments provided to the program.
 * - av: The argument vector containing the input values.
 *
 * Returns:
 * - Always 0, as the program concludes successfully or exits on error.
 */
int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	int		fd;
	int		pipe_fd[2];

	if (ac < 2)
		return (0);
	if (!ft_valid(av))
		ft_errorr(NULL, NULL);
	sta = ft_value(ac, av);
	if (!sta)
		ft_errorr(&sta, NULL);
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
