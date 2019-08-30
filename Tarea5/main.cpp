#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Nodo_A {
    public:
        int dia;//eje x
        int hora;//eje y
        std::string actvi;
        Nodo_A* siguiente;
        Nodo_A* anterior;
        Nodo_A* arriba;
        Nodo_A* abajo;
        Nodo_A(int dias, std::string ac, int horas): actvi(ac),dia(dias),hora(horas),siguiente(0),anterior(0),arriba(0),abajo(0){}
};
class Lista_A {
    public:
        Nodo_A* inicio=0;

        void Imprimir(){
            std::ofstream file;
            file.open("Grafica.dot");
            Nodo_A* tem=inicio;
            Nodo_A* tem2=0;
            int a=1;

            std::stringstream ss;
            ss.str(std::string());
            ss.clear();
            ss<<tem->hora;

            std::string CadenaImprimir= "digraph Grafica { \n";
            CadenaImprimir += "size=\"9,9\" \n";
            CadenaImprimir += "node[shape=record,style=filled] \n" ;
            CadenaImprimir +=  "\""+ tem->actvi+ss.str()+"\"" +"[label ="+"\""+"{";
            //CadenaImprimir = CadenaImprimir + " Hora: "+tem->actvi+ '}"]' + '\n';

            //tem=tem->siguiente;
            //while(tem !=0){
              //  tem2=tem;
               // while(tem2!=0){
                 //   cout << "Hora: "<<tem2->hora <<"  Actividad:  "<<tem2->actvi <<"  dia:  "<<tem2->dia << endl;
                   // tem2=tem2->abajo;
                //}
                //tem=tem->siguiente;
            //}

            //file << "primera l�nea\n";
            //file << "segunda l�nea\n";
            //file << "tercera l�nea\n";
            file<< CadenaImprimir;
            //system("Grafica.dot");
            file.close();
        }

        void mostrardia(int day){
            Nodo_A* tem=inicio;
            while(tem !=0){
                if(tem->dia==day){
                    std::cout << "Hora: "<<tem->hora <<"  Actividad:  "<<tem->actvi <<"  dia:  "<<tem->dia << std::endl;
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
                    std::cout << "Hora: "<<tem2->hora <<"  Actividad:  "<<tem2->actvi <<"  dia:  "<<tem2->dia << std::endl;
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

        void InsertarActividad(int horaY,int diaX, std::string actividad){

            //crecion de nuevo nodo con los datos
            Nodo_A* nuevo=new Nodo_A(diaX,actividad,horaY);
            Nodo_A* columna=buscarX(diaX);
            Nodo_A* fila=buscarY(horaY);
            //casos de insercion
            //primer caso columna y fila no existe
            if(columna==0 && fila==0){
                std::cout << "crea c y f"<< std::endl;
                columna=crearColumnaX(diaX);
                fila=crearFilaY(horaY);
                insertarenX(nuevo,columna);
                insertarenY(nuevo,fila);
            }else{
                if(columna!=0 && fila==0){
                    std::cout << "crea f"<< std::endl;
                    //segundo caso si columna existe
                    fila=crearFilaY(horaY);
                    insertarenX(nuevo,columna);
                    insertarenY(nuevo,fila);
                }
                else{
                    if(columna==0 && fila!=0){
                        std::cout << "crea c "<< std::endl;
                        //tercer caso si fila existe
                        columna=crearColumnaX(diaX);
                        insertarenX(nuevo,columna);
                        insertarenY(nuevo,fila);
                    }else{
                        if(columna!=0 && fila!=0){
                           std:: cout << "no crea c y f"<< std::endl;
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
    listap->Imprimir();
    while(pausa==0){
        std::cout << "Tarea 4 Clase 201701133" << std::endl;
        std::cout << "1.Ingresar Actividad" << std::endl;
        std::cout << "2. Mostrar Actividad" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una Opcion" << std::endl;
        int opcion;
        std::cin >> opcion;
        if(opcion==1){
            std::cout << "Ingrese un dia" << std::endl;
            int dia;
            std::cin >> dia;
            std::cout << "Ingrese una hora" << std::endl;
            int horaopcion;
            std::cin >> horaopcion;
            std::cout << "Ingrese una actividad" << std::endl;
            std::string actividad;
            std::cin >> actividad;
            listap->InsertarActividad(horaopcion,dia,actividad);

        }
        if(opcion==2){
            std::cout << "1.Mostrar dia" << std::endl;
            std::cout << "2. Mostrar Semana" << std::endl;
            std::cout << "3. Salir" <<std:: endl;
            int opcion2;
            std::cin >> opcion2;
            if(opcion2==1){
               std:: cout << "Ingrese un dia" <<std:: endl;
                int dia;
                std::cin >> dia;
               std:: cout << "Imprimiendo actividades del dia: "<<dia << std::endl;
                listap->mostrardia(dia);
            }
            if(opcion2==2){

                std::cout << "Imprimiendo actividades de la semana: "<< std::endl;
                listap->mostrartodo();
            }

        }
        if(opcion==3){
                pausa=1;
        }
    }
    return 0;
}
