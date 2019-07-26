#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
       string nro;//nro es la variable_elemento
       struct nodo *sgte;//sgte es siguiente
};

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, string valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}
void buscarElemento(Tlista lista, string valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
void reportarLista(Tlista lista)
{
     int i = 0;

     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}
void eliminarElemento(Tlista &lista, string valor)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void menu1()
{
    cout<<"\n\t\tBOLSA\n\n";
    cout<<" 1. INSERTAR                "<<endl;
    cout<<" 2. MOSTRAR LISTA                   "<<endl;
    cout<<" 3. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 4. ELIMINAR ELEMENTO            "<<endl;
    cout<<" 5. SALIR                            "<<endl;

    cout<<"\n INGRESE UNA OPCION ";
}

                       //Funcion Principal
int main()
{
    Tlista lista = NULL;
    int opcion;     // opcion del menu
    string valor;  // elemenento
    int pos;    // posicion
    do
    {
        menu1();
        cin>> opcion;
        switch(opcion)
        {
            case 1:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> valor;
                 insertarInicio(lista, valor);
            break;
            case 2:
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;
            case 3:
                 cout<<"\n Valor a buscar: "; cin>> valor;
                 buscarElemento(lista, valor);
            break;
            case 4:
                cout<<"\n Valor a eliminar: "; cin>> valor;
                eliminarElemento(lista, valor);
            break;
                    }
        cout<<endl<<endl;
        system("pause");  system("cls");
    }while(opcion!=5);
   system("pause");
   return 0;
}
