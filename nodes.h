#include <iostream>

class Node
{
    public:
        Node(int keyVal);
        ~Node();
        Node *rightPtr = nullptr;
        Node *leftPtr = nullptr;
        int key;
    private:

};

Node::Node(int keyVal)
{
    key = keyVal;
}

Node::~Node()
{
    delete rightPtr;
    delete leftPtr;
}
