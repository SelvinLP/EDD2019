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
        Nodo_A* inicio=new Nodo_A(-1,"raiz",-1);

        void mostrardia(int day){
            Nodo_A* tem=inicio;
            while(tem !=0){
                if(tem->dia==day){
                    cout << "Hora: "<<tem->hora <<"  Actividad:  "<<tem->actvi << endl;
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

        Nodo_A* insertarOrdenadOX(Nodo_A* nuevo, Nodo_A* cabeza){
            Nodo_A* tem=cabeza;
            //bandera indica si se incerta antes o despues
            bool bandera=false;
            while(true){
                //metodo de ordenamiento
                //si son iguales
                if(tem->dia==nuevo->dia){
                    tem->hora=nuevo->hora;
                    tem->actvi=nuevo->actvi;
                    return tem;
                }else{
                    //en caso de que no sean iguales
                    if(tem->dia > nuevo->dia){
                        bandera=true;
                        break;
                    }
                }
                //fin comprobacion de ordenamiento
                if(tem->siguiente!=0){
                    tem=tem->siguiente;
                }else{
                    //se incerta despues para eso la bandera debe ser falsa
                    break;
                }
            }
            if(bandera){
                //incertamos valores antes del temporal que es el encontrado
                nuevo->siguiente=tem;
                tem->anterior->siguiente=nuevo;
                nuevo->anterior=tem->anterior;
                tem->anterior=nuevo;
            }else{
                tem->siguiente=nuevo;
                nuevo->anterior=tem;
            }
            return nuevo;
        }

        Nodo_A* insertarOrdenadOY(Nodo_A* nuevo, Nodo_A* cabeza){
            Nodo_A* tem=cabeza;
            //bandera indica si se incerta antes o despues
            bool bandera=false;
            while(true){
                //metodo de ordenamiento
                //si son iguales
                if(tem->hora==nuevo->hora){
                    tem->dia=nuevo->dia;
                    tem->actvi=nuevo->actvi;
                    return tem;
                }else{
                    //en caso de que no sean iguales
                    if(tem->hora > nuevo->hora){
                        bandera=true;
                        break;
                    }
                }
                //fin comprobacion de ordenamiento
                if(tem->abajo!=0){
                    tem=tem->abajo;
                }else{
                    //se incerta despues para eso la bandera debe ser falsa
                    break;
                }

                if(bandera){
                    //incertamos valores antes del temporal que es el encontrado
                    nuevo->abajo=tem;
                    tem->arriba->abajo=nuevo;
                    nuevo->arriba=tem->arriba;
                    tem->arriba=nuevo;
                }else{
                    tem->abajo=nuevo;
                    nuevo->arriba=tem;
                }
                return nuevo;
            }
        }

        Nodo_A* crearColumnaX(int valorx){
            Nodo_A* raizColumna=inicio;
            Nodo_A* columna=insertarOrdenadOX(new Nodo_A(valorx,"COL",-1),raizColumna);
            return columna;
        }

        Nodo_A* crearFilaY(int valory){
            Nodo_A* raizFila=inicio;
            Nodo_A* fila=insertarOrdenadOY(new Nodo_A(-1,"FILA",valory),raizFila);
            return fila;
        }

        void InsertarActividad(int horaY,int diaX, string actividad){


        //crecion de nuevo nodo con los datos
        Nodo_A* nuevo=new Nodo_A(diaX,actividad,horaY);
        Nodo_A* columna=buscarX(diaX);
        Nodo_A* fila=buscarY(horaY);
        //casos de insercion
        //primer caso columna y fila no existe
        if(columna==0 && fila==0){
            columna=crearColumnaX(diaX);
            fila=crearFilaY(horaY);
            nuevo=insertarOrdenadOX(nuevo,columna);
            nuevo=insertarOrdenadOY(nuevo,fila);

        }else{
            //segundo caso de inserccion columna no exista y fila si
            if(columna==0 && fila!=0){
                columna=crearColumnaX(diaX);
                nuevo=insertarOrdenadOX(nuevo,columna);
                nuevo=insertarOrdenadOY(nuevo,fila);

            }else{
                //tercer caso de inserccion columna exosta y fila no exista
                if(columna!=0 && fila==0){
                    fila=crearFilaY(horaY);
                    nuevo=insertarOrdenadOX(nuevo,columna);
                    nuevo=insertarOrdenadOY(nuevo,fila);

                }else{
                    //cuarto caso de inserccion columna exista y fila exista
                    if(columna!=0 && fila!=0){
                        nuevo=insertarOrdenadOX(nuevo,columna);
                        nuevo=insertarOrdenadOY(nuevo,fila);
                    }
                }
            }
        }

        //fin de casis de inserccion
    }
};
int main()
{
    int pausa=0;
    Lista_A* listap=new Lista_A();
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

            }

        }
        if(opcion==3){
                pausa=1;
        }
    }
}
