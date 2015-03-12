#include "srv.h"

int		fits(int sz, int** racks, int i, int j, struct data *srv_data)
{
	int k;

	if (i >= srv_data->rows)
		return 0;
	for (k = 0; k < sz && j + k < srv_data->cols; k++)
		if (racks[i][j + k])
			return (0);
	for (k = 0; k < sz; k++)
		racks[i][j + k] = 1;
	return 1;
}

int		place_in_row(int row, struct server* srv, int** rack, struct data* srv_data)
{
	int		j;

	for (j = 0; j < srv_data->cols; j++)
	{
		if (fits(srv->slots, rack, row, j, srv_data))
		{
			srv->row = row;
			srv->col = j;
			return 1;
		}
	}
	return 0;
}

void	place_srvs(struct data* srv_data, int** rack, struct server *srvs)
{
	int i, k, placed, grp;

	grp = 0;
	for (k = 0; k < srv_data->srvs; k++)
	{
		placed = 0;
		for (i = 0; i < srv_data->rows; i++)
		{
			if (place_in_row(i, &srvs[k], rack, srv_data))
			{
				srvs[k].grp = grp;
				k++;
				placed = 1;
			}
		}
		if (placed)
		{
			grp++;
			k--;
		}
	}
}
