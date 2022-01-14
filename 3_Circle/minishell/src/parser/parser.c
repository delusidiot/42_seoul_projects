#include "parser.h"

t_node	*parse_simple_command(t_token *token)
{
	if (!token)
		return NULL;
	
	t_node	*cmd = new_node(NODE_COMMAND);
	if (!cmd)
	{
		free_token(token);
		return (NULL);
	}

	t_source	*src = token->src;
	token = tokenize(src);
	while (token != NULL) //eoftoken
	{
		if (token->text[0] == '\n')
		{
			free_token(token);
			break;
		}
		t_node *word = new_node(NODE_VAR);
		if (!word)
		{
			free_node_tree(cmd);
			free_token(token);
			return NULL;
		}
		set_node_val_str(word, token->text);
		add_child_node(cmd, word);
		free(token);
		token = tokenize(src);
	}
	return (cmd);
}