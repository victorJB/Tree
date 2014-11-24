#include "tree.h"
#include <iostream>

using namespace std;

Node::Node()
{
    parent = NULL;
    childs.clear();
    data = 0;

}

 Node::Node(int data,Node *parent=NULL):data(data),parent(parent)
 {
     childs.clear();
 }

 int Node::getData()
 {
     return this->data;
 }

 vector <Node*> *Node::getChilds()
 {
     return &this->childs;
 }

 void Node::aumentarTamanoChilds()
 {

 }

 Node *Node::getChild(int posicion)
 {
     return this->childs[posicion];
 }

 void Node::dimensionarChilds(unsigned int tamano)
 {
     this->childs.resize(tamano);
 }

 int Node::tamanoChilds()
 {
     unsigned int sizes = this->childs.size();
     return sizes;
 }

 Tree::Tree():root(NULL),current(NULL)
 {     
 }

 void Tree::init(int data)
 {
     if(root==NULL)
     {
         root = new Node(data);
         current = root;
     }
 }

  void Tree::insert(Node *ref, vector <int> data)
  {
      current = ref;
      current->dimensionarChilds(data.size());

      for(unsigned int i = 0;i<data.size();i++)
      {
          Node *newNode = new Node(data[i]); //quien soy
          newNode->asignarPadre(current); //de donde vengo

          current->insertarChild(i,newNode);
      }

  }

void Tree::preorder(Node* n) //Raiz-Izquierda-Derecha
{
    if(n==NULL) return;

    cout<<n->getData()<<endl;

    for(int i = 0;i<n->tamanoChilds();i++)
    {
        preorder(n->getChild(i));

    }

}

void Tree::postOrden(Node* n) //Izquierda-Derecha-Raiz
{
    if(n==NULL) return;

    for(int i = 0;i<n->tamanoChilds();i++)
    {
        postOrden(n->getChild(i));


    }

     cout<<n->getData()<<endl;
}

Node* Tree::getCurrent()
{
    return this->current;
}

Node* Tree::getRoot()
{
    return this->root;
}

void Tree::insertarPorBusqueda(Node *n,int dato)
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
            cout<<"Tamano Hijos = "<<n->tamanoChilds()<<endl;

            insertarPorBusqueda(n->getChild(i),dato);

        }
    }
}

void Tree::insertarNuevoHijo(Node *ref)
{
    current = ref;
    cout<<"Size Childs antes de redimensionar = "<<current->tamanoChilds()<<endl;

    current->dimensionarChilds(ref->tamanoChilds()+1);

    cout<<"Size Childs despues de redimensionar = "<<current->tamanoChilds()<<endl;

    int dato = 0;
    cout<<"Nuevo dato a insertar: ";
    cin>>dato;

    for(unsigned int i = 0;i<1;i++)
    {
        Node *newNode = new Node(dato); //quien soy
        newNode->asignarPadre(current); //de donde vengo

        cout<<"Posicion en la que se insertara = "<<current->tamanoChilds()<<endl;


        current->insertarChild(current->tamanoChilds()-1,newNode);
    }
}

void Node::insertarChild(int position,Node* nuevoNodo)
{
    this->childs[position] = nuevoNodo;

}

void Node::asignarPadre(Node* padre)
{
    this->parent = padre;
}



