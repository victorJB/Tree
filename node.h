#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class Node
{
private:
    T data;// private
    Node *parent; //private
    Node *hijo; //private
    vector <Node*> childs; //private


public:

    vector <T> cadena; //private
    Node();
    Node(T data,Node *parent);
    T getData();
    Node<T> *getChild(int posicion);
    void dimensionarChilds(unsigned int tamano);
    int tamanoChilds();
    void insertarChild(int position, Node *nuevoNodo);
    void asignarPadre(Node *padre);
    vector<Node<T> *> *getChilds();
    void exportarDatos(string A, T dato);


};

template <class T>
Node<T>::Node()
{
    parent = NULL;
    childs.clear();
    data = 0;

}

template <class T>
 Node<T>::Node(T data, Node *parent=NULL):data(data),parent(parent)
 {
     childs.clear();
 }

 template <class T>
  T Node<T>::getData()
  {
      return this->data;
  }

  template <class T>
  vector<Node<T> *> *Node<T>::getChilds()
  {
      return &this->childs;
  }

  template <class T>
  Node<T> *Node<T>::getChild(int posicion)
  {
      return this->childs[posicion];
  }

  template <class T>
  void Node<T>::dimensionarChilds(unsigned int tamano)
  {
      this->childs.resize(tamano);
  }

  template <class T>
  int Node<T>::tamanoChilds()
  {
      unsigned int sizes = this->childs.size();
      return sizes;
  }

  template <class T>
  void Node<T>::insertarChild(int position,Node* nuevoNodo)
  {
      this->childs[position] = nuevoNodo;

  }

  template <class T>
  void Node<T>::asignarPadre(Node* padre)
  {
      this->parent = padre;
  }


  template <class T>
  void Node<T>::exportarDatos(string A,T dato)
  {
      int i = 0;
      int j = 0;
      this->cadena.push_back(this->data);
      this->cadena.push_back(dato);

     // cout<<"Tamano Vector = "<<this->cadena.size()<<endl;

      ofstream file;
      file.open(A.c_str());
      if(file.is_open())
      {

          file <<"Digraph G {"<<endl;
          for(i=0;i<this->cadena.size();i = i+2)
          {
               file << this->cadena[i] << " -> "<<this->cadena[i+1]<<endl;
          }
          file<<"}";


        file.close();




      }

  }


#endif // NODE_H
