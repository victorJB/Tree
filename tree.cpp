#include "tree.h"
#include <iostream>

using namespace std;

Node::Node()
{
    parent = NULL;
    childs.clear();
    data = 0;

}

 Node::Node(int data,Node *parent):data(data),parent()
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

      for(int i = 0;i<data.size();i++)
      {
          Node *newNode = new Node(data[i]); //quien soy
          newNode->parent = current; //de donde vengo

          current->childs[i] = new Node;
      }

      return &current->childs;
  }
