//Alfredo Fernando Turpo Huillcara                              CCOMP3-1
#include <iostream>
using namespace std;

int Euclides_extendido(int a, int b){
    int x = 0, x_anterior = 1; 
    int y = 1, y_anterior = 0;
    int z = b, z_anterior = a;
    //declaro un auxiliar y un cociente
    int  aux,cociente;

    while(z != 0){
        cociente = z_anterior / z;
        //este codigo se encargara de hallar el mcd 
        aux = z;
        z= z_anterior-cociente*z;
        z_anterior = aux;               
        //este codigo se encargara de hallar el "x"
        aux = x;
        x = x_anterior-cociente*x;
        x_anterior = aux;
        //este codigo se encargara de hallar el "y"
        aux = y;
        y = y_anterior-cociente*y;
        y_anterior = aux;
    }
    cout<<"El maximo comun divisor es: "<<z_anterior<<endl;
    cout<<"(x,y)= "<<"("<<x_anterior<<","<<y_anterior<<")"<<endl;
}

int main(){
    int x=0,y=0;
    int a,b;
    cout<<"Ingrese a: ";
    cin>>a;
    cout<<"Ingrese b: ";
    cin>>b;
    Euclides_extendido(a,b);
}