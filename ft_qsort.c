#include "ft_mini_ls.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_qsort(long *elements, size_t start, size_t end)
{
	long	pivot;
	size_t	i;
	size_t	j;

	if (start >= end)
		return ;
	pivot = elements[(start + end) / 2];
	i = start;
	j = end;
	while (true)
	{
		while (elements[i] < pivot)
			i++;
		while (elements[j] > pivot)
			j--;
		if (i >= j)
			break ;
		swap(&elements[i], &elements[j]);
		i++;
		j--;
	}
	ft_qsort(elements, start, j);
	ft_qsort(elements, j + 1, end);
}
