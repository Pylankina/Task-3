#include "DB.h"

class Solver:public DB{
public:
    Solver(ifstream &fin);
    bool graphColorUtil(int m, int v);
    bool isSafe(int v, int c);
};