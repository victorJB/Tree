#include <iostream>
#include "tree.h"

using namespace std;

int main()
{

    Tree t1;
    Node *aux;
    vector <Node*> *aux2;
    vector <int> num;


    num.push_back(2);
    num.push_back(3);

    aux = t1.init(1);
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back(4);
    num.push_back(5);
    num.push_back(99);

    t1.insert(aux2->at(0),num);

    num.clear();
    num.push_back(6);
    num.push_back(7);
    num.push_back(77);
     num.push_back(66);

    t1.insert(aux2->at(1),num);

    cout<<"PreOrden"<<endl;

    t1.preorder(aux);

    cout<<"PostOrden"<<endl;

    t1.postOrden(aux);


    return 0;
}
