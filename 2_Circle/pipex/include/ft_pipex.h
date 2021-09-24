/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:06:34 by jjeon             #+#    #+#             */
/*   Updated: 2021/08/09 23:15:28 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

/*
** Dependencies
*/

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>//
# include <sys/types.h>
# include "libft.h"
# include "get_next_line.h"

# define ERROR_MESSAGE "Usage : ./pipex infile cmd1 cmd.. cmdn outfile\n"
# define ERROR_MESSAGE2 "Usage : ./pipex LIMIT infile cmd1 cmd.. cmdn outfile\n"
# define READ 0
# define WRITE 1

typedef struct s_pipex
{
	char	**envp;
	char	***cmds;
	char	*infile;
	char	*outfile;
	int		end_index;
	int		here_doc;
	int		pipe_a[2];
	int		pipe_b[2];
	char	*temp;
}	t_pipex;

/*
** argument setting
*/

int		set_param(int argc, char **argv, char **envp, t_pipex *p);
char	*get_file_path(char *pwd, char *name);
char	**get_cmd_path(char **path, char *name);
char	*get_env_pwd(char *pwd);
char	*join_path(char *prev, char *name);
char	**get_env_path(char *path);
void	free_env(char *pwd, char **path);
void	free_pipex(t_pipex *p);
void	init_pipex(t_pipex *p);
char	**ft_cmd_split(char const *s, char c);
int		quotes_skip(char **s, int size);

/*
** process
*/
void	infile(t_pipex *p);
void	outfile(int index, t_pipex *p);
void	execute(int index, t_pipex *p);
void	error_exit(char *message, t_pipex *p);
void	pipex(t_pipex *p);

#endif
