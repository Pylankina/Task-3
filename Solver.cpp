#include "Solver.h"
#include <algorithm>


 Solver::Solver(ifstream &fin):DB(fin){
    int m = 3; 
    graphColorUtil(m, 0);
   
}

bool Solver::graphColorUtil(int m, int r) {
        if (r == v) 
            return true;
        for (int c = 1; c <= m; c++) 
            if (cheking(r, c)) {
                colour[r] = c; // Присваиваем цвет
                if (graphColorUtil(m, r + 1)) // Пытаемся раскрасить последующие вершины
                    return true;
                colour[r] = 0; // Откат
            }
        return false;
}

bool Solver::cheking(int r, int c) {
    for (int i = 0; i < graph[r].size(); i++)
        if (graph[r][i] == 1 && colour[i] == c) // Проверяем только соседей
            return false;
    return true;
}
    
