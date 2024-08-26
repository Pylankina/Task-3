#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "DB.h"


DB::DB (ifstream &f_in): Parser(f_in){
    int i;
    for (i=0; i<v; i++)//инициализация, т.е. каждая вершина - белая
        answer.push_back(make_pair(i,0));
    for(i=0; i<answer.size(); i++)
        colour.push_back(0);
};
void DB::function(){
    for (int i=0; i<colour.size(); i++){
        answer[i].second=colour[i];
    }
}

void DB::writting(){ // функция записи ответа в файл
    ofstream out;
    out.open("answer.txt");
    function();
    if (out.is_open()){
       for (const auto& item : answer) 
        out << "Вершина: " << item.first << ", Цвет: " << item.second << endl;
    }
    out.close();
}