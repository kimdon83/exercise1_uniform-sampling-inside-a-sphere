#ifndef _MCMAN_H_KDH_
#define _MCMAN_H_KDH_

#include "define.h"

class Cmcmanager{
private:
	int i,j,k;
	double loc[3];
	rng RN;
	double rad_in;
	double rad;
	int Num_history;
	double loc_aver[3], rad_aver;//average of location vector and radius

public:
	Cmcmanager();
	~Cmcmanager();
	int readINPUT(void);
	int mcrun(void);
};
#endif