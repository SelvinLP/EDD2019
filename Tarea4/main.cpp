#include <iostream>

using namespace std;

class Nodo_A {
    public:
        int dia;//eje x
        int hora;//eje y
        string actvi;
        Nodo_A* siguiente;
        Nodo_A* anterior;
        Nodo_A* arriba;
        Nodo_A* abajo;
        Nodo_A(int dias, string ac, int horas): actvi(ac),dia(dias),hora(horas),siguiente(0),anterior(0),arriba(0),abajo(0){}
};
class Lista_A {
    public:
        Nodo_A* inicio=0;

        void mostrardia(int day){
            Nodo_A* tem=inicio;
            while(tem !=0){
                if(tem->dia==day){
                    cout << "Hora: "<<tem->hora <<"  Actividad:  "<<tem->actvi <<"  dia:  "<<tem->dia << endl;
                    tem=tem->abajo;
                }else{
                    tem=tem->siguiente;
                }

            }
        }

        void mostrartodo(){
            Nodo_A* tem=inicio;
            Nodo_A* tem2=0;
            tem=tem->siguiente;
            while(tem !=0){
                tem2=tem;
                while(tem2!=0){
                    cout << "Hora: "<<tem2->hora <<"  Actividad:  "<<tem2->actvi <<"  dia:  "<<tem2->dia << endl;
                    tem2=tem2->abajo;
                }
                tem=tem->siguiente;
            }
        }

        Nodo_A* buscarY (int valory){
            Nodo_A* tem=inicio;
            while(tem !=0){
                if(tem->hora==valory){
                    return tem;
                }
                tem=tem->abajo;
            }
            return 0;
        }

        Nodo_A* buscarX (int valorx){

        Nodo_A* tem=inicio;
        while(tem !=0){
            if(tem->dia==valorx){
                return tem;
            }
            tem=tem->siguiente;
        }
        return 0;
    }

        Nodo_A* crearColumnaX(int valorx){
            Nodo_A* raizColumna=inicio;
            Nodo_A* tem=inicio;
            Nodo_A* fin=0;
            Nodo_A* nuevos=new Nodo_A(valorx,"COL",-1);
            bool bandera=false;
            while(raizColumna!=0){
                if(raizColumna->dia > valorx){
                    bandera=true;
                    tem=raizColumna;
                }
                if(raizColumna->siguiente==0){
                    fin=raizColumna;
                }
                raizColumna=raizColumna->siguiente;
            }
            if(bandera){
                //incertamos valores antes del temporal que es el encontrado
                nuevos->siguiente=tem;
                tem->anterior->siguiente=nuevos;
                nuevos->anterior=tem->anterior;
                tem->anterior=nuevos;
            }else{
                fin->siguiente=nuevos;
                nuevos->anterior=fin;
            }
            return nuevos;
        }

        Nodo_A* crearFilaY(int valory){
            Nodo_A* raizFila=inicio;
            Nodo_A* tem=inicio;
            Nodo_A* fin=0;
            Nodo_A* nuevo=new Nodo_A(-1,"FIL",valory);
            bool bandera=false;
            while(raizFila!=0){
                if(raizFila->hora>valory){
                    bandera=true;
                    tem=raizFila;
                    break;
                }
                if(raizFila->abajo==0){
                   fin=raizFila;
                }
                raizFila=raizFila->abajo;
            }
            if(bandera){
                //incertamos valores antes del temporal que es el encontrado
                nuevo->abajo=tem;
                tem->arriba->abajo=nuevo;
                nuevo->arriba=tem->arriba;
                tem->arriba=nuevo;
            }else{
                fin->abajo=nuevo;
                nuevo->arriba=fin;
            }
            return nuevo;
        }

        void insertarenX(Nodo_A* nuevo, Nodo_A* Cabeza){
            bool bandera=false;
            Nodo_A* tem=Cabeza;
            Nodo_A* fin=0;
            while(Cabeza!=0){
                if(Cabeza->hora>nuevo->hora){
                    bandera=true;
                    tem=Cabeza;
                    break;
                }
                if(Cabeza->abajo==0){
                    fin=Cabeza;
                }
                Cabeza=Cabeza->abajo;
            }
            if(bandera){
                //incertamos valores antes del temporal que es el encontrado
                nuevo->abajo=tem;
                tem->arriba->abajo=nuevo;
                nuevo->arriba=tem->arriba;
                tem->arriba=nuevo;
            }else{
                fin->abajo=nuevo;
                nuevo->arriba=fin;
            }

        }

        void insertarenY(Nodo_A* nuevo, Nodo_A* Cabeza){
            bool bandera=false;
            Nodo_A* tem=Cabeza;
            Nodo_A* fin=0;
            while(Cabeza!=0){
                if(Cabeza->dia>nuevo->dia){
                    bandera=true;
                    tem=Cabeza;
                    break;
                }
                if(Cabeza->siguiente==0){
                    fin=Cabeza;
                }
                Cabeza=Cabeza->siguiente;
            }
            if(bandera){
                //incertamos valores antes del temporal que es el encontrado
                nuevo->siguiente=tem;
                tem->anterior->siguiente=nuevo;
                nuevo->anterior=tem->anterior;
                tem->anterior=nuevo;
                bandera=false;
            }else{
                fin->siguiente=nuevo;
                nuevo->anterior=fin;
            }
        }

        void InsertarActividad(int horaY,int diaX, string actividad){
            //crecion de nuevo nodo con los datos
            Nodo_A* nuevo=new Nodo_A(diaX,actividad,horaY);
            Nodo_A* columna=buscarX(diaX);
            Nodo_A* fila=buscarY(horaY);
            //casos de insercion
            //primer caso columna y fila no existe
            if(columna==0 && fila==0){
                cout << "crea c y f"<< endl;
                columna=crearColumnaX(diaX);
                fila=crearFilaY(horaY);
                insertarenX(nuevo,columna);
                insertarenY(nuevo,fila);
            }else{
                if(columna!=0 && fila==0){
                    cout << "crea f"<< endl;
                    //segundo caso si columna existe
                    fila=crearFilaY(horaY);
                    insertarenX(nuevo,columna);
                    insertarenY(nuevo,fila);
                }
                else{
                    if(columna==0 && fila!=0){
                        cout << "crea c "<< endl;
                        //tercer caso si fila existe
                        columna=crearColumnaX(diaX);
                        insertarenX(nuevo,columna);
                        insertarenY(nuevo,fila);
                    }else{
                        if(columna!=0 && fila!=0){
                            cout << "no crea c y f"<< endl;
                            //si los dos existen
                            insertarenX(nuevo,columna);
                            insertarenY(nuevo,fila);
                        }
                    }
                }
            }

    }
};
int main()
{
    int pausa=0;
    Lista_A* listap=new Lista_A();
    listap->inicio=new Nodo_A(-1,"Raiz",-1);
    while(pausa==0){
        cout << "Tarea 4 Clase 201701133" << endl;
        cout << "1.Ingresar Actividad" << endl;
        cout << "2. Mostrar Actividad" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una Opcion" << endl;
        int opcion;
        cin >> opcion;
        if(opcion==1){
            cout << "Ingrese un dia" << endl;
            int dia;
            cin >> dia;
            cout << "Ingrese una hora" << endl;
            int horaopcion;
            cin >> horaopcion;
            cout << "Ingrese una actividad" << endl;
            string actividad;
            cin >> actividad;
            listap->InsertarActividad(horaopcion,dia,actividad);

        }
        if(opcion==2){
            cout << "1.Mostrar dia" << endl;
            cout << "2. Mostrar Semana" << endl;
            cout << "3. Salir" << endl;
            int opcion2;
            cin >> opcion2;
            if(opcion2==1){
                cout << "Ingrese un dia" << endl;
                int dia;
                cin >> dia;
                cout << "Imprimiendo actividades del dia: "<<dia << endl;
                listap->mostrardia(dia);
            }
            if(opcion2==2){

                cout << "Imprimiendo actividades de la semana: "<< endl;
                listap->mostrartodo();
            }

        }
        if(opcion==3){
                pausa=1;
        }
    }
    return 0;
}
