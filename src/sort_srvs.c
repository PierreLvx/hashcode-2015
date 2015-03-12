#include "srv.h"

int is_lesser(struct server frst, struct server sec)
{
	if (frst.cap > sec.cap)
		return 1;
	else if (frst.cap == sec.cap && frst.slots > sec.slots)
		return 1;
	return 0;
}

void	sort_srvs(struct data* srv_data, struct server* srvs)
{
	int min;
	int curs;
	int idx;
	struct server swap;

	idx = 0;
	while (idx < srv_data->srvs - 1)
	{
		curs = idx + 1;
		min = idx;
		while (curs < srv_data->srvs)
		{
			if (is_lesser(srvs[curs], srvs[min]))
				min = curs;
			curs++;
		}
		swap = srvs[min];
		srvs[min] = srvs[idx];
		srvs[idx] = swap;
		idx++;
	}
}
