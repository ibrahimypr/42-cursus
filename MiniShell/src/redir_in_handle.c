/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:14:37 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:14:38 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc(char *file, char *eof)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_RDWR | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(file, flags, 0777);
	while (ft_strcmp(line, eof))
	{
		free(line);
		line = readline("heredoc> ");
		if (line && ft_strcmp(line, eof))
			ft_putstrendl_fd(line, fd);
		else
			break ;
	}
	close(fd);
	unlink(file);
	free(line);
}

void	mixed_redir2(char *str, char *temp, int fd, t_envp *s_envp)
{
	int		fdd;
	int		stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0, s_envp);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}

void	mixed_redir(char *str, char *temp, int fd, t_envp *s_envp)
{
	int		fdd;
	int		stdout_copy;

	stdout_copy = dup(1);
	fdd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fdd, 1);
	close(fdd);
	execute_dir(temp, fd, 0, s_envp);
	dup2(stdout_copy, 1);
	close(stdout_copy);
}

void	redir_in_handle(char **str, int i, t_envp *s_envp)
{
	char	*file;
	int		fd;
	char	*temp;

	temp = sub_redir(str, i);
	file = ft_strdup(str[i + 1]);
	fd = open(file, O_RDONLY, 0777);
	if (str[i + 2] && str[i + 2][0] == '>')
	{
		if (str[i + 2][1] || str[i + 2][1] == '>')
			mixed_redir2(str[i + 3], temp, fd, s_envp);
		else
			mixed_redir(str[i + 3], temp, fd, s_envp);
	}	
	else
		execute_dir(temp, fd, 0, s_envp);
	free (file);
	free (temp);
}

void	redir2_in_handle(char **str, int i, t_envp *s_envp)
{
	int		fd;
	char	*eof;
	char	*temp;

	temp = sub_redir(str, i);
	eof = ft_strdup(str[i + 1]);
	here_doc(TMP_FILE, eof);
	fd = open(TMP_FILE, O_RDONLY, 0777);
	execute_dir(temp, fd, 0, s_envp);
	if (eof[0] != '\0')
		free(eof);
	if (temp[0] != '\0')
		free(temp);
}
