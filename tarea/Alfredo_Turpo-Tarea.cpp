//AlFredo Fernando Turpo Huillcara                                          CCOMP2-1

//1. Crear una función que imprima una persona P en el peldaño correcto en una escalera 
//   doble de tamaño fijo (3 peldaños)

/*

#include <iostream>
using namespace std;

void escaleradoble(int b){
    for(int i=0;i<=3;i++){
        for(int j=0;j<i;j++){
         cout<<"    ";    
        }
    if( -((i*-1)+b)==3)
    cout<<"|_P_"; 
    else
    cout<<"|___"; 
    for(int k=(3*2)-1-(2*i);k>=0;k-=(1)){
        cout<<"    ";
        }
    if(i==3-b && b!=0)
    cout<<"_P_|\n";
    else
    cout<<"___|\n";
        
    }

}
int main(){
    int a;
    cout<<"Ingresa el numero de escalon donde se encuentra la persona: ";
    cin>>a;

    escaleradoble(a);
}

*/

//2.  Crear la animación que la persona suba y baje la escalera dos veces.

//Imprima por ejemplo escaleraDoble(-3)
//Luego borre la pantalla  con los comandos system("cls") en windows, o system("clear") en linux.
//Imprima escaleraDoble(-2)
//Siga sucesivamente hasta el valor de 3 y regrese nuevamente al -3.

/*

#include <iostream>

using namespace std;

//Permite que la animacion vaya mas lento
void retraso(){
    for(int a=0;a<20000;a++){
        for(int b=0;b<20000;b++){

        }
    }
}
void escaleradoble(int b){
    for(int i=0;i<=3;i++){
        for(int j=0;j<i;j++){
         cout<<"    ";    
        }
        if( -((i*-1)+b)==3)
        cout<<"|_P_"; 
        else
        cout<<"|___"; 
        for(int k=(3*2)-1-(2*i);k>=0;k-=(1)){
            cout<<"    ";
        }
        if(i==3-b && b!=0)
        cout<<"_P_|\n";
        else
        cout<<"___|\n";
        
    }
}
int main(){
    int a=3;
    for (int b=-3;b<=a;b++){
        escaleradoble(b);
        retraso();
        system("cls");}
    for (int b=2;b>=-3;b--){
        escaleradoble(b);
        retraso();
        system("cls");
    
    }
}

*/

//3. Generar una escalera doble con animación de tamaño npeldanhos. 
//   Es decir, la cantidad de peldaños ahora es variable.

#include <iostream>

using namespace std;
//Permite que la animacion vaya mas lento
void retraso(int e){
    for(int a=0;a<20000;a+=e*1){
        for(int b=0;b<20000;b+=e*1){

        }
    }
}
//En esta funcion solo "a" estara fija, "b" es la que ira cambiando de valor
void escaleranpeldanos(int a, int b ){
    for(int i=0;i<=a;i++){
        for(int j=0;j<i;j++){
         cout<<"    ";    
        }
        if( -((i*-1)+b)==a)
        cout<<"|_P_"; 
        else
        cout<<"|___"; 
        for(int k=(a*2)-1-(2*i);k>=0;k-=(1)){
            cout<<"    ";
        }
        if(i==a-b && b!=0)
        cout<<"_P_|\n";
        else
        cout<<"___|\n";
        
    }


}
int main(){
    int a,e;
    cout<<"Ingresa el numero de peldanos: ";
    cin>>a;
    cout<<"Escoja la velocidad del 1 al 5: ";
    cin>>e;
    for(int b=(a*-1);b<=a;b++){
        escaleranpeldanos(a,b);
        retraso(e);
        system("cls");
    }

    for(int b=a-1;b>=(a*-1);b--){
        escaleranpeldanos(a,b);
        retraso(e);
        system("cls");

    }
    
    
}
