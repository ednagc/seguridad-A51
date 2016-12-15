#include "A51.hpp"



//===========================================
//METODOS PUBLICOS.
//===========================================

A51::A51(vector<int> r1,vector<int> r2,vector<int> r3,int num_iter){
    
    r1_=r1;
    r2_=r2;
    r3_=r3;
    
    
    num_iter_ = num_iter;

    
}

A51::~A51(){};

void A51::encriptar(void){
    
    cout<< " a9 : " << r1_[9-1] << endl;
    cout<< " b11 : " << r2_[11-1] << endl;
    cout<< " c11 : " << r3_[11-1] << endl;
    
    cout<< endl;
    cout<<"Semilla : "<< endl;
    mostrar_r();
    
 
    int aux;
    int dato_z1=0;
    int dato_z2=0;
    int dato_z3=0;        
            
    for(int i=0;i<num_iter_;i++){
            
            
            
            
            cout << endl;
        
            aux = f_mayoria(r1_[9-1],r2_[11-1],r3_[11-1]);
            cout <<"F("<<r1_[9-1]<<","<<r2_[11-1]<<","<<r3_[11-1]<<") "<<"= "<< aux << endl;
         
        
            //====== Registro 1 ========
            if(r1_[9-1] == aux){
                
                int value1;
                value1 = r1_[19-1]^r1_[18-1]^r1_[17-1]^r1_[14-1];//1
                dato_z1=r1_[19-1];
                r1_.pop_back();
                r1_.insert(r1_.begin(),value1);
                
            }else{
                dato_z1=r1_[r1_.size()-1];
            }
            
            //====== Registro 2 ========
            
            if(r2_[11-1] == aux){
             int value2;
                value2 = r2_[22-1]^r2_[21-1];//1
                dato_z2=r2_[22-1];
                r2_.pop_back();
                r2_.insert(r2_.begin(),value2);
                
            }else{
                dato_z2=r2_[r2_.size()-1];
            }    
            
            //====== Registro 3 ========
            
            if(r3_[11-1] == aux){
            int value3;
                value3 = r3_[23-1]^r3_[22-1]^r3_[21-1]^r3_[8-1];//en la 1ª iteracion no se mueve
                dato_z3=r3_[23-1];
                r3_.pop_back();
                r3_.insert(r3_.begin(),value3);
                
            }else{
                dato_z3=r3_[r3_.size()-1];
            }   
            
            
            z_.push_back(dato_z1^dato_z2^dato_z3);
           
           cout <<"z(t) = "<<z_[i]<<endl;
           cout << endl;
           cout << "===== ITERACION " << i+1 <<"====="<<endl;
           mostrar_r();
           
        }
        
        //============ MOSTRAMOS z(t) ============
        
        cout <<"******************************* "<< endl;
        cout << endl;
        cout << "Tamaño z(t) : " << z_.size() << endl;
        cout << "Valore/s de z(t) : ";
        for(int i=z_.size()-1;i>=0;i--){
        cout << z_[i];
        }
        cout << endl;
        cout << endl;
    }

//===========================================
//METODOS PRIVADOS.
//===========================================


int A51::f_mayoria(int a,int b,int c){
    int aux1;
    int aux2;
    int aux3;
    int f_;
    
    aux1 = (a*b);
    aux2 = (a*c);
    aux3 = (b*c);
    
    f_= aux1^aux2^aux3;
    return f_;
}


void A51::mostrar_r(void){
    
    cout<< endl;
    for (int i = r1_.size()-1; i>=0 ;i--) {
        cout << r1_[i]; 
    }
    cout << endl;
    
    
    for (int i = r2_.size()-1; i>=0 ;i--) {
        cout << r2_[i]; 
    }
    cout << endl;
    
    
    for (int i = r3_.size()-1; i>=0 ;i--) {
        cout << r3_[i]; 
    }
    cout << endl;
    cout<< endl;
    
}