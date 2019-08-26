#include <iostream>

using namespace std;
class Nodo_Actividades {
    public:
        string Actividad;
        Nodo_Actividades* siguiente;
        Nodo_Actividades* anterior;
        Nodo_Actividades(string act):Actividad(act),siguiente(0),anterior(0) {}
};
class Lista_Actividades {
    public:
        Nodo_Actividades* inicio=0;
        Nodo_Actividades* fin=0;
        void Insertar (string  dato){
            Nodo_Actividades* nue=new Nodo_Actividades(dato);
            if(inicio==0){
                inicio=nue;
                fin=nue;
            }else
            {
                Nodo_Actividades* temporal=fin;
                fin=nue;
                temporal->siguiente=nue;
                fin->anterior=temporal;
            }
        }

        void Mostrar(){
            Nodo_Actividades* temn=inicio;
            while(temn!=0){

                cout<<"Descripcion de la Actividad: "<<temn->Actividad<<endl;
                temn=temn->siguiente;
            }
        }
};
class Nodo_A {
    public:
        int fecha;
        string actvi;
        Lista_Actividades* listaactividades;
        Nodo_A* siguiente;
        Nodo_A(int datos, string ac, Lista_Actividades* lt): actvi(ac),fecha(datos),listaactividades(lt),siguiente(0){}
};
class Lista_A {
    public:
        Nodo_A* inicio=0;
        void Insertar (int dato,string ac, Lista_Actividades* lts){
            Nodo_A* tem=new Nodo_A(dato,ac,lts);
            tem->listaactividades->Insertar(ac);
            tem->siguiente=inicio;
            inicio=tem;
        }

        void InsertarActividad(int d, string cad){
            Nodo_A* tem=inicio;
            while(tem!=0){
                    if(d==tem->fecha){
                        tem->listaactividades->Insertar(cad);
                    }
                tem=tem->siguiente;
            }
        }
        void MostrarSemana(){
            Nodo_A* temn=inicio;
            while(temn!=0){

                cout<<"Imprimiendo dia de la semana:: "<<temn->fecha<<endl;
                temn->listaactividades->Mostrar();
                temn=temn->siguiente;
            }
        }
        void MostrarDia(int d){
            Nodo_A* tem=inicio;
            while(tem!=0){
                    if(d==tem->fecha){
                        tem->listaactividades->Mostrar();
                    }
                tem=tem->siguiente;
            }
        }
        int Buscar(int diabusqueda){
            Nodo_A* temn=inicio;

            while(temn!=0){
                    if(diabusqueda==temn->fecha){
                        return 1;
                    }
                temn=temn->siguiente;
            }
            return 0;
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
            cout << "Ingrese una actividad" << endl;
            string actividad;
            cin >> actividad;
            int busqueda=listap->Buscar(dia);
            if(busqueda==0){
                Lista_Actividades* listaacc=new Lista_Actividades();
                listap->Insertar(dia,actividad,listaacc);
            }else{
                listap->InsertarActividad(dia,actividad);
            }
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
                listap->MostrarDia(dia);
            }
            if(opcion2==2){

                cout << "Imprimiendo actividades de la semana: "<< endl;
                listap->MostrarSemana();
            }

        }
        if(opcion==3){
                pausa=1;
        }
    }
}
