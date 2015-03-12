void	init_rack(int **srv_rack, struct data *srv_data, FILE *fd)
{
	int 	x,y;
	int 	i;

	i = 0;
	fscanf(fd, "/n");
	while (i < srd_data->unavail)
	{
		fscanf(fd, "%i %i\n", x, y);
		srv_rack[x][y] = -1;
		i++;
	}
}
