#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include <algorithm>
#include "stdlib.h"
#include <string> 
#include <cmath>
using namespace std;

class A51 {
    
    private:
    
    
    //REGISTROS
    vector<int> r1_;
    vector<int> r2_;
    vector<int> r3_;
    vector<int> z_;
    int         num_iter_;
    
    public:
    
    A51(vector<int>,vector<int>,vector<int>,int);
    ~A51();
    void encriptar(void);
    
    private:
    int f_mayoria(int,int,int);
    void mostrar_r(void);
    
};