#include "Node.h"
#include <iostream>
#include <vector>
using namespace std;

Node* insert(Node* root, int x)
{
    Node* temp = new Node(x);

    // If tree is empty
    if(root == NULL)
        return temp;
    Node *parent = NULL, *curr = root;
    while(curr != NULL) {
        parent = curr;
        if(curr->getData() > x)
            curr = curr->getLchild();
        else if(curr->getData() < x)
            curr = curr->getRchild();
        else
            return root;
    }
    if(parent->getData() > x)
        parent->setLchild(temp);
    else
        parent->setRchild(temp);
    return root;
}

void sorted(Node* root, vector<int>& sortedInorder)
{
    if(root == nullptr) {
        return;
    }
    sorted(root->getLchild(), sortedInorder);
    sortedInorder.push_back(root->getData());
    sorted(root->getRchild(), sortedInorder);
}


int main()
{

    Node* root = new Node(17);
    
    root->insertRecursive(12)->insertRecursive(24);
    
    
/*    for(int i{ 0 }; i < 10; i++) {
        int k = rand() % 30 + 1;
        cout << k << endl;
        //root = insert(root, k);
        root = root->insertRecursive(k);
    }*/
    cout << endl;

    root->inOrderTraversal();
    //vector<int> s;
    //sorted(root, s);

    cout << endl;

    return 0;
}