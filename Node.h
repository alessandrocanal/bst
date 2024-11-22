#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int data;
    Node* lchild;
    Node* rchild;
public:
    Node(int k);
    int getData();
    Node* getLchild();
    Node* getRchild();
    void setData(int k);
    void setLchild(Node* l);
    void setRchild(Node* r);
    Node* insertRecursive(int k);
    void inOrderTraversal();
    ~Node();

};

#endif // NODE_H
