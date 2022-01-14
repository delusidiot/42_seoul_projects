#include "minishell.h"

static char	*prompt_line(char *prompt, char *str)
{
	char *temp;

	temp = ft_strjoin(prompt, str);
	free(prompt);
	return (temp);
}

static char	*get_pwd(t_user *user)
{
	char *temp;
	char *pwd;
	int home_dir_len;
	int pwd_len;

	home_dir_len = ft_strlen(user->home_dir);
	pwd_len = ft_strlen(user->pwd);
	pwd = NULL;
	if (home_dir_len == pwd_len && !ft_strncmp(user->home_dir, user->pwd, home_dir_len))
		temp = ft_strdup("~");
	else if (home_dir_len < pwd_len && !ft_strncmp(user->home_dir, user->pwd, home_dir_len))
	{
		temp = ft_strdup(user->pwd + home_dir_len);
		pwd = ft_strjoin("~", temp);
		free(temp);
	}
	else
		pwd = ft_strdup(user->pwd);
	return (pwd);
}

char	*prompt1(t_user *user)
{
	char	*prompt;
	char	*pwd;
	
	free(user->pwd);
	user->pwd = getcwd(NULL, 1024);
	prompt = NULL;
	prompt = prompt_line(prompt, BGRN);
	prompt = prompt_line(prompt, user->username);
	prompt = prompt_line(prompt, "@MINISHELL:");
	prompt = prompt_line(prompt, BBLU);
	pwd  = get_pwd(user);
	prompt = prompt_line(prompt, pwd);
	free(pwd);
	prompt = prompt_line(prompt, WHT);
	prompt = prompt_line(prompt, "$ ");
	prompt = prompt_line(prompt, EOC);
	return (prompt);
}

char	*prompt2(t_user *user)
{
	(void)user;
	return (ft_strdup(">"));
}