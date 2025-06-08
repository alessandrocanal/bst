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

int printPrev(vector<int> v, int k) {
    int index{-1};
    for (int i{0}; i<v.size(); i++) {
        if (v.at(i) == k) {
            index = i;
            break;
        }
            
    }
    return index;
}


int main()
{

    Node* root = new Node(50);
    vector<int> v;
    root->insertRecursive(17)->insertRecursive(53)->insertRecursive(27)->insertRecursive(14)->insertRecursive(21);
    root->inOrderTraversal();
    cout << endl;
    cout << root->findHeight();
    cout << endl;
    cout << root->findDepth(14) << endl;
    cout << root->findDepth(13) << endl;
    cout << root->findDepth(21) << endl;
    cout << root->findDepth(29) << endl;
    
    Node* root2 = new Node(50);
    root2->insertRecursive(17)->insertRecursive(23)->insertRecursive(27)->insertRecursive(14)->insertRecursive(21);
    
    cout << root->areIdentical(root2)<< endl;
    
    //root->fillVec(v);
    
    int index = printPrev(v,27);
    if (index == -1) {
        
    }
    
/*    for(int i{ 0 }; i < 10; i++) {
        int k = rand() % 30 + 1;
        cout << k << endl;
        //root = insert(root, k);
        root = root->insertRecursive(k);
    }*/
    cout << endl;

    
    //vector<int> s;
    //sorted(root, s);

    

    return 0;
}