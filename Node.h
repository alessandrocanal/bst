#ifndef NODE_H
#define NODE_H
#include <vector>
class Node
{
private:
    int data;
    Node* lchild;
    Node* rchild;
    void kthSmallestUtil(int& k, int& result);
public:
    //Node(int k);
    Node(int k, Node* lchild=nullptr, Node* rchild=nullptr);
    int getData();
    Node* getLchild();
    Node* getRchild();
    void setData(int k);
    void setLchild(Node* l);
    void setRchild(Node* r);
    Node* insertRecursive(int k);
    Node* insertIterative(int k);
    void inOrderTraversal();
    void fillVec(std::vector<int> &v);
    int findDepth(int k);
    int findHeight();
    bool isFull();
    int kthSmallest(int k);
    bool areIdentical(Node* root2);
    ~Node();

};

#endif // NODE_H
