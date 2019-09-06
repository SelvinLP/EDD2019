#include <iostream>

using namespace std;

class Nodo_A {
    public:
        int CodigoProducto;
        int Stock;
        int StockMinimo;
        string CodigoProveedor;
        Nodo_A* siguiente;
        Nodo_A(int codigoproducto, int stock,int stockminimo,string codigoproveedor): CodigoProducto(codigoproducto),Stock(stock),StockMinimo(stockminimo),CodigoProveedor(codigoproveedor),siguiente(0){}
};
class Lista_A {
    public:
        Nodo_A* inicio=0;

        void CopiarElementos(Lista_A*Lista2){
            //creacion de la nueva lista
            Nodo_A*tem=inicio;

            while(tem!=0){
                if(tem->StockMinimo>tem->Stock){
                    //copia los elementos
                    cout << "Inserta copia " << tem->Stock<<endl;
                    Nodo_A* n=new Nodo_A(tem->CodigoProducto,tem->Stock,tem->StockMinimo,tem->CodigoProveedor);
                    InsertarOrdenado(Lista2,n);
                }
                tem=tem->siguiente;
            }
        }
        void ModstrarDatos(Lista_A*lt){
            Nodo_A*tem=lt->inicio;
            while(tem!=0){
                cout << "Codigo Producto: "<<tem->CodigoProducto << endl;
                cout << "Stock: "<<tem->Stock << endl;
                cout << "StockMinimo: "<<tem->StockMinimo << endl;
                cout << "Codigo Proveedor: "<<tem->CodigoProveedor << endl;
                tem=tem->siguiente;
            }
        }

        void InsertarOrdenado(Lista_A* nuevo,Nodo_A* dato){
            Nodo_A *tem=nuevo->inicio;
            bool bandera=false;
            Nodo_A* cambio=nuevo->inicio;
            Nodo_A* fin=0;
            if(nuevo->inicio==0){
                nuevo->inicio=dato;
            }else{

                while(tem!=0){
                    if(tem->CodigoProducto>dato->CodigoProducto){
                        bandera=true;
                        break;
                    }
                    if(tem->siguiente==0){
                        fin=tem;
                    }else{
                        cambio=tem;
                    }
                    tem=tem->siguiente;
                }
                if(bandera){

                  dato->siguiente=cambio->siguiente;
                  cambio->siguiente=dato;
                  bandera=false;
                }else{
                    //inserta al final
                    fin->siguiente=dato;
                }
            }
        }


        void EliminarConCondicion(){

            if(inicio->CodigoProducto>100){
                if(inicio->siguiente==0){
                    inicio=0;
                }else{
                    inicio=inicio->siguiente;
                }
            }
            Nodo_A *tem=inicio;
            while(tem!=0){
                if(tem->siguiente!=0){
                   if(tem->siguiente->CodigoProducto>100){
                        if(tem->siguiente->siguiente==0){
                            tem->siguiente=0;
                            EliminarConCondicion();
                            break;
                        }else{
                            tem->siguiente=tem->siguiente->siguiente;
                            EliminarConCondicion();
                            break;

                        }
                    }
                }

                tem=tem->siguiente;
            }
        }

};
int main()
{
    Lista_A*Lista=new Lista_A();
    //insercion de datos ya ordenados
    Nodo_A *dato=new Nodo_A(10,50,100,"Jos");
    Lista->InsertarOrdenado(Lista,dato);
    Nodo_A *dato2=new Nodo_A(120,110,100,"Jos2");
    Lista->InsertarOrdenado(Lista,dato2);
    Nodo_A *dato3=new Nodo_A(140,90,100,"Jos3");
    Lista->InsertarOrdenado(Lista,dato3);
    Nodo_A *dato4=new Nodo_A(30,120,100,"Jos4");
    Lista->InsertarOrdenado(Lista,dato4);

    cout << "Tarea 6  201701133"  << endl;
    cout << "######################  METODO COPIAR LISTA #########################" << endl;
    Lista_A*Lista2=new Lista_A();
    Lista->CopiarElementos(Lista2);
    cout << "######################  DATOS DE NUEVA LISTA #########################" << endl;
    Lista->ModstrarDatos(Lista2);
    cout << "######################  ELIMINAR CONDICION #########################" << endl;
    Lista->EliminarConCondicion();
    cout << "######################  DATOS DE NUEVA LISTA #########################" << endl;
    Lista->ModstrarDatos(Lista);
    return 0;
}
