#ifndef NODE_H
#define NODE_H
enum e_node_type
{
    NODE_COMMAND,           /* simple command */
    NODE_VAR,               /* variable name (or simply, a word) */
};
enum e_val_type
{
    VAL_SINT = 1,       /* signed int */
    VAL_UINT,           /* unsigned int */
    VAL_SLLONG,         /* signed long long */
    VAL_ULLONG,         /* unsigned long long */
    VAL_FLOAT,          /* floating point */
    VAL_LDOUBLE,        /* long double */
    VAL_CHR,            /* char */
    VAL_STR,            /* str (char pointer) */
};
union u_symval
{
    long               sint;
    unsigned long      uint;
    long long          sllong;
    unsigned long long ullong;
    double             sfloat;
    long double        ldouble;
    char               chr;
    char              *str;
};
typedef struct s_node
{
    enum   e_node_type type;
    enum   e_val_type val_type;
    union  u_symval val;
    int    children;
    t_node *first_child;
    t_node *next_sibling, *prev_sibling;
} t_node;
struct  node_s *new_node(enum e_node_type type);
void    add_child_node(t_node *parent, t_node *child);
void    free_node_tree(t_node *node);
void    set_node_val_str(t_node *node, char *val);
#endif