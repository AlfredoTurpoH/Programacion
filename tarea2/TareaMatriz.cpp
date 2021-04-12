//AlFredo Fernando Turpo Huillcara                                          CCOMP2-1
#include<iostream>
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
}

// Funcion que pide la posicion en donde colocar X u O
char posicin(){
    char posicion;
    cout<<"Escoge la posicion donde quieres colocar: ";
    cin>>posicion;
    return posicion;

}

//Funcion que coloca la opcion X u Y en la posicion indicada en el
//3 en raya 
void colocar(char m[3][3],char p,char o){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (m[i][j]==p)
                m[i][j]=o;
            cout<<m[i][j];
            
            if((j+1)%3==0)
                cout<<"\n";
            else
                cout<<"|";

        }
    if((i+1)%3!=0)
    cout<<"-|-|-\n";
    
    }
}



int main(){
    char tablero[3][3];
    char opcion = escoger();
    char posicion = posicin();
    
    iniciar(tablero);
    colocar(tablero,posicion,opcion);
  

}