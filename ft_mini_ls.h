# include <dirent.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/stat.h>

typedef struct  s_file
{
    char    *name;
    long    mtime;
}   t_file;

void	ft_qsort(long *elements, size_t start, size_t end);