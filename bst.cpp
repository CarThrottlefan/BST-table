#include <iostream>
#include <cstdlib>
#include "bst.h"
#include "matrixTemplate.h"
#include <iomanip>

int main()
{
    BST *tree = nullptr;
    tree = new BST();
    
    int numInput, searchKey;
    int rows, columns;
    int maxHeight = 0;

    std::vector<int> sortedOrder;
    std::vector< std::pair<int, int>> heightForNode;

    std::cout << "Enter the numbers to be stored: ";
    
    while(std::cin >> numInput)
    {
        tree->insertKey(numInput);
        heightForNode.push_back(std::make_pair(numInput, tree->hasKey(numInput)));
        
        if(tree->hasKey(numInput) > maxHeight)
        {
            maxHeight = tree->hasKey(numInput);
        }   
    }

    std::cin.clear();
    std::cin.ignore();

    sortedOrder = tree->inOrder();
    std::cout << "The numbers in sorted order: ";
    
    for(int i = 0; i < sortedOrder.size(); i++)
    {
        std::cout << sortedOrder.at(i) << " ";
    }
    std::cout << std::endl;
    
    columns = sortedOrder.size();
    rows = maxHeight;

    Matrix<std::string> outputMatrix(rows, columns, "-");
    
    for(int i = 0; i < rows; i++)    
    {
        for(int j = 0; j < columns; j++)
        {
            int tempRow, tempCol; 
            std::string currNum;

            tempCol = sortedOrder.at(j);
            currNum = std::to_string(tempCol);

            for(int l = 0; l < heightForNode.size(); l++)
            {
                if(heightForNode.at(l).first == tempCol)
                {
                    tempRow = heightForNode.at(l).second - 1;
                    break;
                }
            }
            outputMatrix.at(tempRow, j) = currNum;
        }
    }

    if(rows != 0)
    {
        tree->prettyPrint(outputMatrix);
    }

    delete tree;

    return 0;
}
