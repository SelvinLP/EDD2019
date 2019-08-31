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
        void CargaDatos(char ruta[]){
            int x=1;
            int y=1;
            std::fstream archivo(ruta);
            if(archivo.fail()){
                std::cout << "No se pudo abrir el archivo"<< std::endl;
            }else{
                std::cout << "Se abrio Correctamente"<< std::endl;
                for (std::string linea; std::getline(archivo, linea); )
                {
                    std::stringstream registro(linea);
                    for (std::string dato; std::getline(registro, dato, ';'); )
                    {
                        if(dato!="x" && dato!="X"){
                            std::cout << "Insertar en Dia: "<<x<<"  Hora: "<<y<<"  Actividad: "<<dato << std::endl;
                            InsertarActividad(y,x,dato);
                        }
                        std::cout << dato << std::endl;

                        x+=1;
                    }
                    y+=1;
                    x=1;
                }
            }
        }
        void Imprimir(){
            std::ofstream file;
            file.open("Grafica.dot");
            Nodo_A* tem=inicio;
            Nodo_A* tem2=0;
            int a=1;


            std::string Cadenaant="";
            std::string Cadenades="";
            std::string CadenaImprimir= "digraph Grafica { \n";
            CadenaImprimir += "size=\"9,9\" \n";
            CadenaImprimir += "node[shape=record,style=filled] \n" ;

            while(tem !=0){
                tem2=tem;
                CadenaImprimir +=  "\""+ tem->actvi+"\"" +"[label ="+"\""+"{";
                CadenaImprimir +=  tem->actvi+ "}\"] \n" ;
                tem2=tem2->abajo;
                while(tem2!=0){
                    CadenaImprimir +=  "\""+ tem2->actvi+"\"" +"[label ="+"\""+"{";
                    CadenaImprimir +=  tem2->actvi+ "}\" ] \n" ;

                    tem2=tem2->abajo;
                }
                tem=tem->siguiente;
            }
            //cracion de relaciones
            tem=inicio;
            while(tem!=0){
                    tem2=tem;
                    CadenaImprimir+="{rank = same;";
                    while(tem2!=0){
                         CadenaImprimir+="\""+ tem2->actvi+"\";";
                        tem2=tem2->siguiente;
                    }
                    CadenaImprimir+="}\n";
                tem=tem->abajo;
            }
            //fon de posicionamiento
            tem=inicio;
            while(tem !=0){
                tem2=tem;
                while(tem2!=0){
                    if(tem2->abajo!=0){
                        CadenaImprimir+="\""+ tem2->actvi+"\" -> \""+ tem2->abajo->actvi+"\""+"\n";
                        CadenaImprimir+="\""+ tem2->actvi+"\" -> \""+ tem2->abajo->actvi+"\""+"[dir=back]\n";
                    }
                    if(tem2->siguiente!=0){
                        CadenaImprimir+="\""+ tem2->actvi+"\" -> \""+ tem2->siguiente->actvi+"\""+"[constraint=false]\n";
                        CadenaImprimir+="\""+ tem2->actvi+"\" -> \""+ tem2->siguiente->actvi+"\""+"[constraint=false,dir=back]\n";
                    }
                    tem2=tem2->abajo;
                }
                tem=tem->siguiente;
            }


            CadenaImprimir+="}";
            file<<CadenaImprimir;
            file.close();
            system("dot -Tpng Grafica.dot -o  Grafica.png");
            system("Start Grafica.png");
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
            std::stringstream ss;
            std::string stconver;
            ss.str(std::string());
            ss.clear();
            ss<<valorx;
            ss>>stconver;

            Nodo_A* raizColumna=inicio;
            Nodo_A* tem=inicio;
            Nodo_A* fin=0;
            Nodo_A* nuevos=new Nodo_A(valorx,("Dia: "+stconver),-1);
            bool bandera=false;
            while(raizColumna!=0){
                if(raizColumna->dia > valorx){
                    bandera=true;
                    tem=raizColumna;
                    break;
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
                bandera=false;
            }else{
                fin->siguiente=nuevos;
                nuevos->anterior=fin;
            }
            return nuevos;
        }

        Nodo_A* crearFilaY(int valory){
            std::stringstream ss;
            std::string stconver;
            ss.str(std::string());
            ss.clear();
            ss<<valory;
            ss>>stconver;

            Nodo_A* raizFila=inicio;
            Nodo_A* tem=inicio;
            Nodo_A* fin=0;
            Nodo_A* nuevo=new Nodo_A(-1,("Hora: "+stconver),valory);
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

    listap->InsertarActividad(2,2,"si2");
    listap->InsertarActividad(1,1,"no");


    while(pausa==0){
        std::cout << "Tarea 4 Clase 201701133" << std::endl;
        std::cout << "1.Ingresar Actividad" << std::endl;
        std::cout << "2. Mostrar Actividad" << std::endl;
        std::cout << "3. Graficar" << std::endl;
        std::cout << "4. Carga Masiva" << std::endl;
        std::cout << "5. Salir" << std::endl;
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
            std::cout << "Graficando Actividades "<< std::endl;
            listap->Imprimir();
        }
        if(opcion==4){
            std:: cout << "Ingrese ruta o nombre del documento" <<std:: endl;
            char ruta[150];
            std::cin >> ruta;
            listap->CargaDatos(ruta);
        }
        if(opcion==5){
                pausa=1;
        }
    }
    return 0;
}
