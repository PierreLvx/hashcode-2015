#ifndef		SRV_H
# define	SRV_H

struct data
{
	int		rows;
	int		cols;
	int		unavail;
	int		grps;
	int		srvs;
};

struct data	get_data(int*);
int**		make_tab(struct data*);
void		init_racks(int**, int*);

#endif
