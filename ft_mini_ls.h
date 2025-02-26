# include <dirent.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/stat.h>

typedef struct  s_file
{
    char            *name;
    long            mtime;
    struct s_file   *next;
}   t_file;

void	ft_qsort_list(t_file *files);
