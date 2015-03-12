#include "srv.h"

struct data	get_data(FILE* fd)
{
	struct data srv_data;

	fscanf(
		fd,
		"%i %i %i %i %i\n",
		&srv_data.rows,
		&srv_data.cols,
		&srv_data.unavail,
		&srv_data.grps,
		&srv_data.srvs
	);
	return srv_data;
}
