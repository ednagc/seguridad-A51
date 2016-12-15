#include "A51.hpp"
using namespace std;


int main(){
    
    /*
        Semilla:     1001000100011010001
                  0101100111100010011010
                 10111100110111100001111
    
        Polinomio Registro 1 : f(x1) = x19+x18+x17+x14+1
        Polinomio Registro 2 : f(x2) = x22+x21+1
        Polinomio Registro 3 : f(x3) = x23+x22+x21+x8+1
    
    
    */
    
    int size_r1=19;
    int size_r2=22;
    int size_r3=23;
    int iter;
    
    vector<int> registro1;
    vector<int> registro2;
    vector<int> registro3;
    
    //19--> 10010001 0001 1010 001
   
    registro1.push_back(1);
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(1);
    registro1.push_back(0);
    registro1.push_back(1);
    registro1.push_back(1);
    registro1.push_back(0);//9
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(1);
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(1);
    registro1.push_back(0);
    registro1.push_back(0);
    registro1.push_back(1);
    
    //22 --> 0101 1001 1110 0010 0110 10
    
    registro2.push_back(0);
    registro2.push_back(1);
    registro2.push_back(0);
    registro2.push_back(1);
    registro2.push_back(1);
    registro2.push_back(0);
    registro2.push_back(0);
    registro2.push_back(1);
    registro2.push_back(0);
    registro2.push_back(0);
    registro2.push_back(0);//11
    registro2.push_back(1);
    registro2.push_back(1);
    registro2.push_back(1);
    registro2.push_back(1);
    registro2.push_back(0);
    registro2.push_back(0);
    registro2.push_back(1);
    registro2.push_back(1);
    registro2.push_back(0);
    registro2.push_back(1);
    registro2.push_back(0);
    
    // 23 -->  1011 1100 1101 1110 0001 111
    
    
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(0);
    registro3.push_back(0);
    registro3.push_back(0);
    registro3.push_back(0);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(1);//11
    registro3.push_back(1);
    registro3.push_back(0);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(0);
    registro3.push_back(0);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(1);
    registro3.push_back(0);
    registro3.push_back(1);
    
    iter = 10;
    
    /*
    cout << " Introduzca el primer registro : " << endl;
    for(int i = 0;i < registro1.size();i++){
        int it;  
        cin >> it;
        registro1.push_back(it);
    }    
    
    cout << " Introduzca el segundo registro : " << endl;
    for(int i = 0;i < registro2.size();i++){
        int it;  
        cin >> it;
        registro2.push_back(it);
    }   
    
    cout << " Introduzca el primer registro : " << endl;
    for(int i = 0;i < registro3.size();i++){
        int it;  
        cin >> it;
        registro3.push_back(it);
    }   
    
    cout << "Introduzca el numero de iteraciones : " << endl;
    cin << iter;
    
    
    */
    
    A51 A(registro1,registro2,registro3,iter);
    A.inicializacion();
    A.encriptar();
    
    
    
    
    
}