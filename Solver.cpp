#include "Solver.h"
#include <algorithm>


 Solver::Solver(ifstream &fin):DB(fin){
    int m = 3; 
    Coloring(m, 0);
   
}

bool Solver::Coloring(int m, int r) {
        if (r == v) 
            return true;
        for (int c = 1; c <= m; c++) 
            if (cheking(r, c)) {
                colour[r] = c; // Присваиваем цвет
                if (Coloring(m, r + 1)) // Пытаемся раскрасить последующие вершины
                    return true;
                colour[r] = 0; // пробуем другой узел
        
            }
        return false;
}

bool Solver::cheking(int r, int c) {
    for (int i = 0; i < graph[r].size(); i++)
        if (graph[r][i] == 1)// Проверяем только соседей
          if (colour[i] == c) 
              return false;
    return true;
}
    
