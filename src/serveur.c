#include "srv.h"

#define RENDU

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



#ifdef RENDU
void	put_tab(struct data *srv_data, int **tab, struct server *srvs)
{
	int k, i;

	(void)tab;
	for (k = 0; k < srv_data->srvs; k++)
	{
		for (i = 0; i < srv_data->srvs; i++)
		{
			if (srvs[i].no == k)
			{
				if (i != 0 && srvs[i].row != 0 && srvs[i].col != 0)
					printf("%i %i %i\n", srvs[i].row, srvs[i].col, srvs[i].grp);
				else
					puts("x");
				break;
			}
		}
	}
	
}
#endif



#ifdef TEST
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
#endif
