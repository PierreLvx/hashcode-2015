#include "srv.h"

void	init_racks(int **srv_rack, struct data *srv_data, FILE *fd)
{
	int 	x, y, i, j;

	for (i = 0; i < srv_data->rows; i++)
		for (j = 0; j < srv_data->cols; j++)
			srv_rack[i][j] = 0;
	while (i < srv_data->unavail)
	{
		fscanf(fd, "%i %i\n", &x, &y);
		srv_rack[x][y] = -1;
		i++;
	}
}
