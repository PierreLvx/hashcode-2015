#ifndef		SRV_H
# define	SRV_H

# include <stdio.h>

struct data
{
	int		rows;
	int		cols;
	int		unavail;
	int		grps;
	int		srvs;
};

struct data	get_data(FILE*);
int**		make_tab(struct data*);
void		init_racks(int**, struct data*, FILE*);

#endif
