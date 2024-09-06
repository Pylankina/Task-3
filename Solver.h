#include "DB.h"

class Solver:public DB{
public:
    Solver(ifstream &fin);
    bool graphColorUtil(int m, int v);
    bool cheking(int v, int c);
};
