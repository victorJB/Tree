#include <iostream>
#include <fstream>
#include "tree.h"
#include "node.h"
#include <vector>

using namespace std;

int main()
{

    Tree <double> t1;
    int i = 0;
    int counter = 0;
    int opcion = 0;
    double dato = 0;
    int numero1 = 0; //Hijos a Insertar

   //system("C://graph1.gv");

     while(i != 1)
    {
        cout<<"0  -- Crear Nodo Padre"<<endl;
        cout<<"1  -- Crear Hijos"<<endl;
        cout<<"2  -- PreOrden"<<endl;
        cout<<"3  -- PostOrden"<<endl;
        cout<<"4  -- Ver Arbol"<<endl;
        cout<<"27 -- Salir de la aplicacion"<<endl;

        cin>>opcion;

        switch(opcion)
        {
          case 0:
            if(t1.getRoot() == NULL)
            {
               t1.init();

            }

            else
                cout<<"Ya existe Nodo Padre"<<endl;
            break;

          case 1:


            if(t1.getRoot() == NULL)
                cout<<"No existe Nodo padre"<<endl;
            else
            {
                cout<<"Ingresar dato a buscar : ";
                cin>>dato;
                cout<<"Numero de hijos a Insertar : ";
                cin>>numero1;

                for(counter = 0;counter<numero1;counter++)
                {
                     t1.insertarPorBusqueda(t1.getRoot(),dato);
                }

            }

            break;

          case 2:
            if(t1.getRoot() == NULL)
                cout<<"No existe Nodo padre"<<endl;
            else
            {
                cout<<endl;
                t1.preorder(t1.getRoot());
                cout<<endl;
            }

            break;

          case 3:

            if(t1.getRoot() == NULL)
                cout<<"No existe Nodo padre"<<endl;

            else
            {

                cout<<endl;
                t1.postOrden(t1.getRoot());
                cout<<endl;
            }

            break;

          case 4:
             system("C://graph1.gv");
             break;

          case 27:
            i = 1;
            break;


        }
    }









    return 0;
}
