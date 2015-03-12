#include "srv.h"

int		**make_tab(struct data *d)
{
	int		**ret;
	int		i;

	i = -1;
	ret = (int**)malloc(sizeof(int*) * d->rows);
	while (++i < d->rows)
		ret = (int*)malloc(sizeof(int) * d->cols);
	return (ret);
}

void	put_tab(struct data *d, int **tab)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->rows)
	{
		j = -1;
		while (++j < d->cols)
			printf("%d", tab[i][j]);
		printf("\n");
	}
}
