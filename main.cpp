#include <iostream>
#include "tree.h"

using namespace std;

int main()
{

    Tree t1;
    Node *aux;
    vector <Node*> aux2;
    vector <int> num;

    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    aux = t1.init(0);
    aux2 = t1.insert(aux,num);

    return 0;
}

