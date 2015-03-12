#include "srv.h"

int		**make_tab(struct data *d)
{
	int		**ret;
	int		i;

	i = -1;
	ret = (int**)malloc(sizeof(int*) * d->rows);
	while (++i < d->rows)
		ret[i] = (int*)malloc(sizeof(int) * d->cols);
	return (ret);
}

void	put_tab(struct data *d, int **tab, struct server *srvs)
{
	int		i;
	int		j;

	i = -1;
	printf("%i %i %i %i %i\n\n", d->rows, d->cols, d->unavail, d->grps, d->srvs);
	while (++i < d->rows)
	{
		j = -1;
		while (++j < d->cols)
			printf("%d", tab[i][j]);
		printf("\n");
	}
	puts("");
	for (i = 0; i < d->srvs; ++i)
		printf("%d %d %d %d %d\n", srvs[i].slots, srvs[i].cap, srvs[i].row, srvs[i].col, srvs[i].grp);
}
