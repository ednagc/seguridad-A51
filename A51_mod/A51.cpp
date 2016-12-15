#include "A51.hpp"



//===========================================
//METODOS PUBLICOS.
//===========================================

A51::A51(vector<int> s1,vector<int> s2,vector<int> s3,int num_iter){
    
    s1_=s1;
    s2_=s2;
    s3_=s3;
    
   
    num_iter_ = num_iter;
    
    for(int i = 0; i<s1.size();i++){
        r1_.push_back(0);
    }
    
    for(int i = 0; i<s2.size();i++){
        r2_.push_back(0);
    }
    
    for(int i = 0; i<s3.size();i++){
        r3_.push_back(0);
    }

    
}

A51::~A51(){};

void A51::encriptar(void){
    
    cout<< endl;
    cout<<"================== ENCRIPTAR ================== : "<< endl;
    cout << endl;
    
    
    cout<< " a9 : " << r1_[9-1] << endl;
    cout<< " b11 : " << r2_[11-1] << endl;
    cout<< " c11 : " << r3_[11-1] << endl;
    
    cout<< endl;
    cout<<"Semilla : "<< endl;
    cout << endl;
    mostrar_s();
    cout<<"Registro : "<< endl;
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
//MODIFICACION.
//===========================================


void A51::inicializacion(void){
    
    
    vector<int> semilla_completa;
    
    
    for(int i=0; i<19;i++){
        semilla_completa.push_back(s1_[i]);
    }
    for(int i=0; i<22;i++){
        semilla_completa.push_back(s2_[i]);
    }
    for(int i=0; i<23;i++){
        semilla_completa.push_back(s3_[i]);
    }
    
    
    
    cout<< " a9 : " << r1_[9-1] << endl;
    cout<< " b11 : " << r2_[11-1] << endl;
    cout<< " c11 : " << r3_[11-1] << endl;
    
    cout<< endl;
    cout<<"Semilla : "<< endl;
    mostrar_s();
    cout<<"Registro : "<< endl;
    mostrar_r();
    
   
    for(int i=0;i<num_iter_;i++){
            cout << endl;
     
        cout << endl;
        cout << "===== ITERACION " << i+1 <<"====="<<endl;
        //====== Registro 1 ========
      
            
            int value1;
            int value11;
            
            value1 = r1_[19-1]^r1_[18-1]^r1_[17-1]^r1_[14-1];//Valor del 1er XOR
            value11 = value1^semilla_completa[i];//XOR entre el valor anterior y semilla
            
           
            r1_.pop_back();
            r1_.insert(r1_.begin(),value11);
            
            cout <<"a["<<i+1<<"]"<<" = "<<"a["<<i+1<<"] xor k["<< i+1<< "]"<< " = "<< r1_[19-1]<< " xor "<<r1_[18-1] << " xor " << r1_[17-1]<< " xor "<<r1_[14-1] << " xor "<< semilla_completa[i] <<" = "<< value11 <<endl;
   
        
        //====== Registro 2 ========
        
    
            
            int value2;
            int value22;
         
            value2 = r2_[22-1]^r2_[21-1];//1
            value22 = value2^semilla_completa[i];
            
           
            r2_.pop_back();
            r2_.insert(r2_.begin(),value22);
            
            cout <<"b["<<i+1<<"]"<<" = "<<"b["<<i+1<<"] xor k["<< i+1<< "]"<< " = "<< r2_[22-1]<< " xor "<<r2_[21-1] << " xor "<< semilla_completa[i]<<" = "<< value22 <<endl;

       
        
        //====== Registro 3 ========
        
    
            
            int value3;
            int value33;
            
            value3 = r3_[23-1]^r3_[22-1]^r3_[21-1]^r3_[8-1];//en la 1ª iteracion no se mueve
            value33 = value3^semilla_completa[i];
            
            
            r3_.pop_back();
            r3_.insert(r3_.begin(),value33);
            
            cout <<"c["<<i+1<<"]"<<" = "<<"c["<<i+1<<"] xor k["<< i+1<< "]"<< " = "<< r3_[23-1]<< " xor "<<r3_[22-1] << " xor " << r3_[21-1]<< " xor "<<r3_[8-1]<< " xor "<< semilla_completa[i] << " = "<< value33 <<endl;

        
       mostrar_r();
       
    }
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

void A51::mostrar_s(void){
    
    cout<< endl;
    for (int i = s1_.size()-1; i>=0 ;i--) {
        cout << s1_[i]; 
    }
    cout << endl;
    
    
    for (int i = s2_.size()-1; i>=0 ;i--) {
        cout << s2_[i]; 
    }
    cout << endl;
    
    
    for (int i = s3_.size()-1; i>=0 ;i--) {
        cout << s3_[i]; 
    }
    cout << endl;
    cout<< endl;
    
}


