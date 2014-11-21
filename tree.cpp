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

 Tree::Tree():root(NULL),current(NULL)
 {     
 }

 Node *Tree::init(int data)
 {
     if(root==NULL)
     {
         root = new Node(data);
         current = root;
     }

     return root;
 }

  vector<Node*> *Tree::insert(Node *ref,vector <int> data)
  {
      current = ref;
      current->childs.resize(data.size());

      for(unsigned int i = 0;i<data.size();i++)
      {
          Node *newNode = new Node(data[i]); //quien soy
          newNode->parent = current; //de donde vengo

          current->childs[i] = newNode;
      }

      return &current->childs;
  }

void Tree::preorder(Node* n) //Raiz-Izquierda-Derecha
{
    if(n==NULL) return;

    cout<<n->data<<endl;

    for(unsigned int i = 0;i<n->childs.size();i++)
    {
        preorder(n->childs[i]);

    }

}

void Tree::postOrden(Node* n) //Izquierda-Derecha-Raiz
{
    if(n==NULL) return;

    for(unsigned int i = 0;i<n->childs.size();i++)
    {
        postOrden(n->childs[i]);


    }

     cout<<n->data<<endl;
}
