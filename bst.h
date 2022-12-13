#include <vector>
#include "nodes.h"
#include "matrixTemplate.h"
#include <iomanip>

class BST
{
    public:
        BST();
        ~BST();
        void insertKey(int newKey);
        int hasKey(int searchKey);
        std::vector<int> inOrder();
        void prettyPrint(Matrix<std::string> outputMatrix);

    private:
        void insertKeyHelper(Node *node, int key);
        int hasKeyHelper(Node *node, int key, int &height);
        Node *rootNode;
        int rows, columns;
        Matrix<std::string> outputMatrix(int rows, int columns);
        std::vector<int> inOrderHelper(Node *rootNode);
};

BST::BST()
{
    rootNode = nullptr;
}

BST::~BST()
{
    delete rootNode;
}

std::vector<int> BST::inOrder()
{
    if(rootNode == nullptr)
    {
        return {};
    }
    return inOrderHelper(rootNode);
}

std::vector<int> BST::inOrderHelper(Node *rootNode)
{
    if((rootNode->leftPtr == nullptr) && (rootNode->rightPtr == nullptr))
    {
        return {rootNode->key};
    }

    std::vector<int> sortedNums;

    if(rootNode->leftPtr != nullptr)
    {
        sortedNums = inOrderHelper(rootNode->leftPtr);
    }
    sortedNums.push_back(rootNode->key);

    if(rootNode->rightPtr != nullptr)
    {
        std::vector<int> tmp = inOrderHelper(rootNode->rightPtr);
        
        for(int i = 0; i < tmp.size(); i++)
        {
            sortedNums.push_back(tmp.at(i));
        }
    }
    return sortedNums;    
}

int BST::hasKey(int newKey)
{       
    int retHeight = 1;
    retHeight = hasKeyHelper(rootNode, newKey, retHeight);

    return retHeight;
}

int BST::hasKeyHelper(Node *node, int searchKey, int &height)
{
    if(node->key == searchKey)
    {
        return height;
    }

    if(node->key > searchKey)
    {
        ++height;
        return hasKeyHelper(node->leftPtr, searchKey, height);
    }
    else
    {
        ++height;
        return hasKeyHelper(node->rightPtr, searchKey, height);
    }
}

void BST::insertKeyHelper(Node *node, int keyToInsert)
{
    if(keyToInsert <= node->key)
    {
        if(node->leftPtr == nullptr)
        {
            node->leftPtr = new Node(keyToInsert);
            return;
        }
        insertKeyHelper(node->leftPtr, keyToInsert);
        return;
    }

    else 
    {
        if(node->rightPtr == nullptr)
        {
            node->rightPtr = new Node(keyToInsert);
            return;
        }
        insertKeyHelper(node->rightPtr, keyToInsert);
        return;
    }
}

void BST::insertKey(int keyToInsert)
{   
    if(rootNode == nullptr)
    {
        rootNode = new Node(keyToInsert);
    }
    else
    {
        insertKeyHelper(rootNode, keyToInsert);
    }
    return;
}

void BST::prettyPrint(Matrix<std::string> outputMatrix)
{
    int rows = outputMatrix.rows();
    int columns = outputMatrix.columns();    
    
    std::cout << "-";
    for(int j = 0; j < columns; j++)
    {
        std::cout << "-----";
    }
    std::cout << std::endl;

    for(int i = 0; i < rows; i++)
    {
        std::cout << "|";
        for(int j = 0; j < columns; j++)
        {
            if(outputMatrix.at(i, j) != "-")
            {
                std::cout << std::setw(4) << outputMatrix.at(i, j);
                std::cout << "|";
            }
            else
            {
                std::cout << std::setw(4) << " ";
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        std::cout << "-";

        for(int j = 0; j < columns; j++)
        {
            std::cout << "-----";
        }
        std::cout << std::endl;
    }
}
