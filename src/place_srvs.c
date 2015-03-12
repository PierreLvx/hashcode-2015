#include "srv.h"

int		fits(int sz, int** racks, int i, int j)
{
	int k;

	for (k = 0; k < sz; k++)
		if (racks[i][j])
			return (0);
	for (k = 0; k < sz; k++)
		racks[i][j] = 1;
	return 1;
}

int		place(struct server* srv1, struct server* srv2, int** rack, struct data* srv_data)
{
	int		placed1 = 0;
  	int		placed2 = 0;
	int		i = 0, j = 0;
	static int grp = 0;

	while ((!placed1 && !placed2) || (i < srv_data->rows && j < srv_data->cols))
	{
		for (j = 0; j < srv_data->cols - srv1->slots; j++)
			if (fits(srv1->slots, rack, i, j))
			{
				i = -1;
				placed1 = i;
				srv1->row = i;
				srv1->col = j;
				srv1->grp = grp;
				break;
			}
		if (placed1)
			for (j = 0; j < srv_data->cols - srv1->slots; j++)
				if (i != placed1 && fits(srv1->slots, rack, i, j))
				{
					placed2 = i;
					srv2->row = i;
					srv2->col = j;
					srv2->grp = grp;
					break;
				}
		i++;
	}
	if (placed1 && placed2)
		grp++;
	return (placed1 && placed2);
}

int		space_in(struct data *srv_data, int **rack, struct server *srvs)
{
	int i, j;

	(void)srvs;
	for (i = 0; i < srv_data->rows; i++)
		for (j = 0; j < srv_data->cols; j++)
			if (rack[i][j] == 0)
				return (1);
	return 0;
}

void	place_srvs(struct data* srv_data, int** rack, struct server *srvs)
{
	int i = 0;

	while (space_in(srv_data, rack, srvs) && i < srv_data->srvs - 1)
	{
		if (place(&srvs[i], &srvs[i + 1], rack, srv_data))
			i += 2;
		else
			i++;
	}
}
