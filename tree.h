#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"

using namespace std;




template <class T>
class Tree
{

private:
    Node <T> *root; //private
    Node <T> *current;   //private

public:

     Tree();
     void init();
     void insert(Node<T> *ref, vector <Node <T>*> data);
     void preorder(Node <T>* n);
     void postOrden(Node <T>* n);
     Node<T>* getCurrent();
     Node<T>* getRoot();
     void insertarPorBusqueda(Node<T> *n, T dato);
     void insertarNuevoHijo(Node<T>* ref);






};

 template <class T>
 Tree<T>::Tree()
 {
     root = NULL;
     current = NULL;
 }

 template <class T>
 void Tree<T>::init()
 {
     T data;
     cout<<""<<endl;
     cout<<"Dato del padre = ";
     cin>>data;
     cout<<""<<endl;

     if(root==NULL)
     {
         root = new Node<T>(data);
         current = root;

     }
 }

  template <class T>
  void Tree<T>::insert(Node<T> *ref, vector<Node<T> *> data)
  {
      current = ref;
      current->dimensionarChilds(data.size());

      for(unsigned int i = 0;i<data.size();i++)
      {
          Node <T> *newNode = new Node<T>(data[i]); //quien soy
          newNode->asignarPadre(current); //de donde vengo

          current->insertarChild(i,newNode);
      }

  }

template <class T>
void Tree<T>::preorder(Node<T> *n) //Raiz-Izquierda-Derecha
{
    if(n==NULL) return;

    cout<<n->getData()<<endl;

    for(int i = 0;i<n->tamanoChilds();i++)
    {
        preorder(n->getChild(i));

    }

}

template <class T>
void Tree<T>::postOrden(Node<T> *n) //Izquierda-Derecha-Raiz
{
    if(n==NULL) return;

    for(int i = 0;i<n->tamanoChilds();i++)
    {
        postOrden(n->getChild(i));


    }

     cout<<n->getData()<<endl;
}

template <class T>
Node<T> *Tree<T>::getCurrent()
{
    return this->current;
}

template <class T>
Node<T>* Tree<T>::getRoot()
{
    return this->root;
}

template <class T>
void Tree<T>::insertarPorBusqueda(Node<T> *n, T dato)
{
    if(n==NULL) return;

    if(dato == n->getData())
    {
       this->insertarNuevoHijo(n);
    }

    else
    {
        for(int i = 0;i<n->tamanoChilds();i++)
        {
            //cout<<"Tamano Hijos = "<<n->tamanoChilds()<<endl;

            insertarPorBusqueda(n->getChild(i),dato);

        }

    }

}

template <class T>
void Tree<T>::insertarNuevoHijo(Node<T> *ref)
{
    vector <T> copia;
    copia.clear();
    int j = 0;

   // cout<<"Tamano cadena = "<<this->current->cadena.size()<<endl;

    for(j=0;j<current->cadena.size();j++)
    {
        copia.push_back(current->cadena[j]);
    }
    current = ref;
    current->cadena.clear();

    for(j=0;j<copia.size();j++)
    {
        current->cadena.push_back(copia[j]);
    }
   // cout<<"Size Childs antes de redimensionar = "<<current->tamanoChilds()<<endl;

    current->dimensionarChilds(ref->tamanoChilds()+1);

    //cout<<"Size Childs despues de redimensionar = "<<current->tamanoChilds()<<endl;

    T dato = 0;
    cout<<"Nuevo dato a insertar: ";
    cin>>dato;

    for(unsigned int i = 0;i<1;i++)
    {
        Node <T> *newNode = new Node<T>(dato); //quien soy
        newNode->asignarPadre(current); //de donde vengo

        //cout<<"Posicion en la que se insertara = "<<current->tamanoChilds()<<endl;

        current->exportarDatos("C://Users/Vic/Documents/Arcsoft/graph1.gv",dato);
        current->insertarChild(current->tamanoChilds()-1,newNode);

    }
}


#endif // TREE_H
