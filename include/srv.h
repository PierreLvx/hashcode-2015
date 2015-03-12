#ifndef		SRV_H
# define	SRV_H

# include <stdio.h>
# include <stdlib.h>

struct data
{
	int		rows;
	int		cols;
	int		unavail;
	int		grps;
	int		srvs;
};

struct server
{
	int		slots;
	int		cap;
	int		row;
	int		col;
	int		grp;
};

struct data	get_data(FILE*);
int**		make_tab(struct data*);
void		init_racks(int**, struct data*, FILE*);

struct server	*init_srvs(struct data*, FILE*);
void			sort_srvs(struct data*, struct server*);
void			place_srvs(struct data*, int**, struct server*);

void			put_tab(struct data*, int **, struct server*);

#endif
