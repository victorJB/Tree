#ifndef TREE_H
#define TREE_H

#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *parent;
    vector <Node*> childs;
    Node();
    Node(int data,Node *parent);

};

class Tree
{

private:
    Node *root;
    Node *current;

public:
     Tree();
     Node* init(int data);
     vector<Node*> *insert(Node* ref, vector <int> data);
     void preorder(Node* n);
     void postOrden(Node* n);

};

#endif // TREE_H
