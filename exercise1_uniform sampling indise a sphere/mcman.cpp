#include "mcman.h"
#include "define.h"

Cmcmanager::Cmcmanager(){
	Num_history = 100;
	loc_aver[0] = 0; loc_aver[1] = 0; loc_aver[2] = 0;
	rad_aver = 0;

}
Cmcmanager::~Cmcmanager(){

}

int Cmcmanager::readINPUT(void){
	cout << "--------------------------------------------------" << endl;
	cout << "|        Uniform sampling inside a shpere        |" << endl;
	cout << "--------------------------------------------------" << endl;

	cout << "      input the length of radius of sphere" << endl;
	cin >> rad_in;
	cout << "      input the number of history " << endl;
	cin >> Num_history;
	
	return 0;
}
int Cmcmanager::mcrun(void){

	for (j = 0; j < Num_history; j++){
		do{
			for (i = 0; i < 3; i++){
				loc[i] = 2 * RN.gnRN() - 1;
			}
			rad = loc[0] * loc[0] + loc[1] * loc[1] + loc[2] * loc[2];
		} while (rad > 1);
		rad = sqrt(rad)*rad_in;
		for (i = 0; i < 3; i++){
			loc[i]*=rad_in;
			loc_aver[i] += loc[i];
		}
		rad_aver += rad;

	}
	for (i = 0; i < 3; i++){
		loc_aver[i] /= Num_history;
	}
	rad_aver /= Num_history;
	cout << rad_aver << endl;
	//cout << loc_aver[0] << "\t" << loc_aver[1] << "\t" << loc_aver[2] << "\t" << endl;
	system("pause");

	return 0;
}
