
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tarea.pkg2;

/**
 *
 * @author Aragon Perez
 */
public class Lista_Bolsa {
    private Nodo_Bolsa Inicio;
    private Nodo_Bolsa Fin;
    public Lista_Bolsa(){
        this.Inicio=null;
        this.Fin=null;
    }

    //metodo insertar
    public void insertar(Object x_ingresado, Object y_ingresado){
        Nodo_Bolsa nuevo=new Nodo_Bolsa(x_ingresado, x_ingresado);
        if(Vacia()){
            Inicio=nuevo;
            Fin=nuevo;
        }else{
            Fin.siguiente=nuevo;
            Fin=nuevo;
            nuevo.siguiente=Inicio;
        }
        
    }
    public boolean Vacia(){
        boolean vacio=false;
        if(Inicio==null){
            vacio=true;
        }
        return vacio;
    }
    public void mostrar(){
        Nodo_Bolsa iterador=Inicio;
        while(iterador!=null){
            if(iterador.x.equals("")){
            }else{
                System.out.println(iterador.x);
                iterador=iterador.siguiente;
            }
            
        }
    }
    public int Contar(){
        int contador_datos=0;
        Nodo_Bolsa iterador=Inicio;
        while(iterador!=null){
            if(iterador.x.equals("")){
            }else{
                System.out.println("Datos de la lista a contar:  "+iterador.x+"   "+iterador.y);
                iterador=iterador.siguiente;
                contador_datos++;
            }
            
        }
        return contador_datos;
    }
}
