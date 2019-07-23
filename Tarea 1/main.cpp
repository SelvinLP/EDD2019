#include <iostream>

using namespace std;

int main()
{
    int day,mounth,year;
    int r1,r2,r3,r4,r5;
    int normal[]={0,3,3,6,1,4,6,2,5,0,3,5};
    int Bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
    int verificador[200];
    int tamanio;
    cout << "Tarea 1" << endl;
    cout << "Selvin Lisandro Aragon Perez 201701133" << endl;
    cout << "1. Determinar el día de la semana de cualquier fecha desde enero de 1700." << endl;
    cout << "2. Algoritmo 'Criba de Eratostenes'. Determinar todos los numeros primos a partir de un numero natural dato. " << endl;
    cout << "Ingrese una Opcion" << endl;
    int opcion;
    cin >> opcion;
    if(opcion==1){
        cout << "1. Determinar el día de la semana de cualquier fecha desde enero de 1700." << endl;
        cout << "Ingrese Dia" << endl;
        cin >> day;
        cout << "Ingrese Mes" << endl;
        cin >> mounth;
        cout << "Ingrese Anio" << endl;
        cin >> year;
        if((year%4)==0 && !(year%100==0)){
            mounth=Bisiesto[mounth-1];
        }else{
            if((year%400)==0){
            mounth=Bisiesto[mounth-1];
            }else{
                mounth=normal[mounth-1];
            }
        }
        r1=(year-1)%7;
        r2=(year-1)/4;
        r3=(3*(((year-1)/100)+1))/4;
        r4=(r2-r3)%7;
        r5=day%7;
        day=(r1+r4+mounth+r5)%7;
        if(day==1){
                cout << "El dia es Lunes" << endl;
            }
            if(day==2){
                cout << "El dia es Martes" << endl;
            }
            if(day==3){
                cout << "El dia es Miercoles" << endl;
            }
            if(day==4){
                cout << "El dia es Jueves" << endl;
            }
            if(day==5){
                cout << "El dia es Viernes" << endl;
            }
            if(day==6){
                cout << "El dia es Sabado" << endl;
            }
            if(day==0){
                cout << "El dia es Domingo" << endl;
            }

    }else{
        //opcion 2
        cout << "Ingrese Limite o Tamanio" << endl;
        cin >> tamanio;
        verificador[0] = false;
        verificador[1] = false;
        //siempre se empieza de la posicion 2
        for(int i = 2; i <= tamanio; ++i){
            verificador[i] = true;
        }


        for(int i = 2; i*i <= tamanio; ++i) {
            if(verificador[i]) {
                for(int j = 2; i*j <= tamanio; ++j){
                    verificador[i*j] = false;
                }
            }
        }
        for(int i = 2; i <= tamanio; ++i){
            if(verificador[i]) {
                 cout << "Numero Primo "<<i << endl;
            }
        }
    }
    return 0;
}
