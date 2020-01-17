#include <iostream>
#include <fstream>
#include "Action.h"
using namespace std;
class Load : public Action
{
private:
	string Address;  
	int n_components; //storing number of components
	int n_connections; //storing number of connections
public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);
	virtual void Execute();

	//void MatrixRead(string** comp_str, int** comp_int, int** con);

};
