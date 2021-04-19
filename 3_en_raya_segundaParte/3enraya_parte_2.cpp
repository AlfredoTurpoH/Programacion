//AlFredo Fernando Turpo Huillcara                                          CCOMP2-1
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Funcion para iniciar la matriz desde 1 al 9
void iniciar( char matriz[3][3] ){
    char x='1';
    for(int z=0;z<3;z++){
        for(int b=0;b<3;b++){
            matriz[z][b]=x++;
        }  
    cout<<endl;
    }
}
//Funcion que verifica si las casillas estan ocupadas
int ocupado(int matriz[9],int casilla){
    for(int z=0;z<9;z++){
        if(matriz[z]==casilla){
            matriz[z]=0;
            return true;
        }

    }  
    return false;
}


//Funcion para escoger ser X u O
char escoger() {
  char opcion;
  
  while(true) {
    cout<<"Escoja ser X u O: ";
    cin>>opcion;
    if( opcion != 'X' && opcion != 'O' && opcion != 'x' && opcion != 'o' )
      cout << "Debe escoger X u O" <<endl;
    else
        return opcion; 
  }
}


//Funcion que construye el 3 en raya
void tablero(char m[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<m[i][j];
            if((j+1)%3==0)
            cout<<"\n";
            else
            cout<<"|";

        }
    if((i+1)%3!=0)
    cout<<"-|-|-\n";
    
    }
    cout<<endl;
}

// Funcion que pide la posicion en donde colocar X u O
int posicin(int matriz [9]){
    while(true){
    int posicion;
    cout<<"Escoge la posicion donde quieres colocar: ";
    cin>>posicion;
    if(posicion>=1 && posicion<=9 && ocupado(matriz,posicion)==true){
        posicion+=48;
        return posicion;
    }   
    else
    cout<<"debes escoger dentro de 1 y 9 y que no este ocupada \n";
    }
}

//Funcion que coloca la opcion X u O en la posicion indicada en el
//3 en raya 
void colocar(char m[3][3],char posicion,char o){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (m[i][j]==posicion)
                m[i][j]=o;
    }  
}
tablero(m);
}
//Funcion para verificar si el tablero esta lleno
int verificartablero(char matriz[3][3]){
   char x='1';
    for(int z=0;z<3;z++){
        for(int b=0;b<3;b++){
            if(matriz[z][b]==x++)
            return true;
        }
    }
    return false; 
}


//Creando la maquina
int maquinaposicion(int matriz[9],char tablero[3][3]){
    int aleatorio;
    srand(time(NULL));
    do
    {
        aleatorio=1 + rand()%9;
    } while (ocupado(matriz,aleatorio)==false && verificartablero(tablero)==true);
    aleatorio+=48;
    return aleatorio;
    
        
    
   
}

//Verificando si se completo un tres en raya 
int verificar(char tablero[3][3]){
    char a,b,c,d,e,f,g,h,i;
    a=tablero[0][0];
    b=tablero[0][1];
    c=tablero[0][2];
    d=tablero[1][0];
    e=tablero[1][1];
    f=tablero[1][2];
    g=tablero[2][0];
    h=tablero[2][1];
    i=tablero[2][2];
    if ((a==b && b==c) || (a==d && d==g) || (a==e && e==i) || (b==e && e==h) || 
        (c==f && f==i) || (c==e && e==g) || (d==e && e==f) || (g==h && h==i))
        return false;
    else
        return true;
}

//Funcion para que la maquina tome el otro simbolo Ejemplo: el usuario es "x" entonces 
//la maquina sera "o"
char opcionmaquina(char opcionusuario){
    char z;
    if(opcionusuario=='x')
        z='o';
    else if(opcionusuario=='X')
        z='O';
    else if(opcionusuario=='o')
        z='x';
    else if(opcionusuario=='O')
        z='X';
    return z;  

}

//iniciando el juego
void juego(char tablero[3][3], char opcion, int casillas[9]){
    do
    {
        char opcionpc=opcionmaquina(opcion);
        int posicion=posicin(casillas);
        colocar(tablero,posicion,opcion);
        int pc= maquinaposicion(casillas,tablero);
        colocar(tablero,pc,opcionpc);

    } while (verificartablero(tablero) && verificar(tablero));
}

int main(){
    char tablero[3][3];
    char opcion = escoger();
    int casillas[9]{1,2,3,4,5,6,7,8,9};
    iniciar(tablero);
    juego(tablero,opcion,casillas);

}
