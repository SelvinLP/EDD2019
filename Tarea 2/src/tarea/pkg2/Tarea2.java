/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tarea.pkg2;
import java.util.Scanner;
/**
 *
 * @author Aragon Perez
 */
public class Tarea2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int contador_ciclo_al_salir=0;
        Scanner Ing_teclado = new Scanner(System.in);
        Lista_Bolsa listBolsa=new Lista_Bolsa();
        while(contador_ciclo_al_salir==0){

            System.out.println("Estructura de Datos |Tarea 2|");
            System.out.println("1.Insertar En Bolsa");
            System.out.println("2.Comprobar si esta vacio");
            System.out.println("3.Contar elementos en la lista");
            System.out.println("4.Salir");
            int opcion= Ing_teclado.nextInt();

            switch(opcion){
                case 1:
                    System.out.println("Ingrese el elemento a ingresar");
                    int opcion1= Ing_teclado.nextInt();
                    int opcion2= Ing_teclado.nextInt();
                    listBolsa.insertar(opcion1, opcion2);
                    break;
                case 2:
                    boolean retorno=listBolsa.Vacia();
                    if(retorno){
                        System.out.println("La lista esta vacia");
                    }else{
                        System.out.println("La lista no esta vacia");
                    }
                    break;
                case 3:
                    int resultado=listBolsa.Contar();
                    System.out.println("La cantidad de Datos es: "+resultado);
                    break;
                case 4:
                    contador_ciclo_al_salir=1;
                    break;
            }
        }
        
    }
    
}
