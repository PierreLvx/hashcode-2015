#include "srv.h"

int		main(int argc, char **argv)
{
	struct data	srv_data;
	FILE		*fd;
	int			**srv_rack;

	if (argc < 2)
		return -1;
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return -2;
	srv_data = get_data(fd);
	srv_rack = make_tab(&srv_data);
	init_racks(srv_rack, &srv_data, fd);
	return 0;
}
