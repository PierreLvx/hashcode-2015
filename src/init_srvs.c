#include "srv.h"

struct server	*init_srvs(struct data* srv_data, FILE* fd)
{
	int				i;
	struct server	*srvs;

	srvs = malloc(sizeof(struct server) * srv_data->srvs);
	for (i = 0; i < srv_data->srvs; i++)
		fscanf(fd, "%i %i\n", &srvs[i].slots, &srvs[i].cap);
	return srvs;
}
