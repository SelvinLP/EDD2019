
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
public class Nodo_Bolsa {
    Object x,y;
    Nodo_Bolsa siguiente;
    public Nodo_Bolsa(Object x1, Object x2){
        this.x=x1;
        this.y=x2;
        this.siguiente=null;
    }
}