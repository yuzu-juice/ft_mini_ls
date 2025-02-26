#include "ft_mini_ls.h"

static _Bool    is_hidden_file(char *filename)
{
    if (filename[0] == '.')
        return (true);
    return (false);
}

static long get_st_mtime(char *filepath)
{
    struct stat stat_info;

    if (stat(filepath, &stat_info) == -1)
        return (0);
    return (stat_info.st_mtime);
}

static int  get_file_count(DIR *dir)
{
    struct dirent  *dp;
    int             count;

    count = 0;
    while (true)
    {
        dp = readdir(dir);
        if (dp == NULL)
            break ;
        if (is_hidden_file(dp->d_name))
            continue ;
        count++;
    }
    return (count);
}

int main()
{
    DIR *dir;
    struct dirent *dp;
    t_file  file;
    int     file_count;

    // count files
    dir = opendir("./");
    if (dir == NULL)
        return (perror(NULL), 1);
    file_count = get_file_count(dir);
    closedir(dir);

    // aaaa
    dir = opendir("./");
    if (dir == NULL)
        return (perror(NULL), 1);
    while (true)
    {
        dp = readdir(dir);
        if (dp == NULL)
            break ;
        file.name = get_filename(dp);
        file.mtime = get_st_mtime(file.name);
        printf("%s, %ld\n", file.name, file.mtime);
    }
    return (0);
}
