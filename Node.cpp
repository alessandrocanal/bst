#include "Node.h"

#include <iostream>

Node::Node(int k, Node* lchild, Node* rchild)
{
    data = k;
    this->lchild = lchild;
    this->rchild = rchild;
}

int Node::getData() { return data; }

Node* Node::getLchild() { return lchild; }

Node* Node::getRchild() { return rchild; }

void Node::setData(int k) { data = k; }

void Node::setLchild(Node* l) { lchild = l; }

void Node::setRchild(Node* r) { rchild = r; }

Node* Node::insertRecursive(int k)
{
    if(this == nullptr) {
        return new Node(k);
    }
    if(this->data == k) {
        return this;
    }
    if(k > this->data) {

        this->rchild = (this->rchild)->insertRecursive(k);
    } else {
        this->lchild = (this->lchild)->insertRecursive(k);
    }
    return this;
}

Node* Node::insertIterative(int k)
{
    Node* current{ this };
    while(current != nullptr) {
        if(current->data == k) {
            break;
        }
        if(k > current->data) {
            if(current->rchild == nullptr) {
                current->rchild = new Node(k);
                break;
            } else {
                current = current->rchild;
            }
        } else {
            if(current->lchild == nullptr) {
                current->lchild = new Node(k);
                break;
            } else {
                current = current->lchild;
            }
        }
    }
    return this;
}

void Node::inOrderTraversal()
{
    if(this == nullptr) {
        return;
    }
    (this->lchild)->inOrderTraversal();
    std::cout << this->data << ' ';
    (this->rchild)->inOrderTraversal();
}

void Node::fillVec(std::vector<int> &v) {
    if(this == nullptr) {
        return;
    }
    (this->lchild)->findPrevAndNext(v);
    v.push_back(this->data);
    (this->rchild)->findPrevAndNext(v);
}

bool Node::isFull()
{
    // caso base banale: il nodo è nullo, sicuramente è pieno
    if(this == nullptr) {
        return true;
    }

    // secondo caso base: il nodo è una foglia => è pieno
    if(this->rchild == nullptr && this->lchild == nullptr) {
        return true;
    }

    // caso generale: il nodo ha entrambi i figli, quando lo consideriamo pieno? pensa ai suoi sottoalberi...
    if(this->rchild != nullptr && this->lchild != nullptr) {
        return this->lchild->isFull() && this->rchild->isFull();
    }

    // caso rimanente
    return false;
}

int Node::findHeight()
{
    int l{ 0 }, r{ 0 };
    if(this == nullptr) {
        return 0;
    }
    l = this->lchild->findHeight();
    r = this->rchild->findHeight();
    return std::max(l, r) + 1;
}

int Node::findDepth(int k)
{
    if(this == nullptr) {
        return -1;
    }
    Node* curr = this;
    int depth{ 0 };
    while(curr != nullptr) {
        if(k < curr->getData()) {
            depth++;
            curr = curr->getLchild();
        } else if(k > curr->getData()) {
            depth++;
            curr = curr->getRchild();
        } else {
            return depth;
        }
    }
    return -1;
}

void Node::kthSmallestUtil(int& k, int& result) {
    if (this == nullptr) return;

    this->lchild->kthSmallestUtil(k, result);

    if (--k == 0) {
        result = this->data;
        return;
    }

    this->rchild->kthSmallestUtil(k, result);
}

int Node::kthSmallest(int k) {
    int result = -1;
    this->kthSmallestUtil(k, result);
    return result;
}

bool Node::areIdentical(Node* root2) {
    if (this == nullptr && root2 == nullptr) return true;
    if (this == nullptr || root2 == nullptr) return false;
    return (this->data == root2->data) &&
           this->lchild->areIdentical(root2->lchild) &&
           this->rchild->areIdentical(root2->rchild);
}

Node::~Node() {}
