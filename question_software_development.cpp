#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

int depth = 0 , maxSum = 0;
stack<int> sumStack;
vector< vector<int> > pyramid;

bool isPrime(int a)
{
    int squareRoot = sqrt(a);

    if(a <= 1)
        return false;
    else if(a <= 3)
        return true;
    else if(a % 2 == 0 || a % 3 == 0)
        return false;
    else    
    {
        for (int i = 5; i <= squareRoot; i = i + 6)
        {
            if(a % i == 0 || a % (i+2) == 0)
                return false;
        }
    }
    return true;   
}

void findMax(int i , int j)
{
    if(isPrime(pyramid[i][j]) == false)
    {
        
        if(i == 0)
            sumStack.push(pyramid[i][j]);
        else
            sumStack.push(sumStack.top() + pyramid[i][j]);
           
        if(i < depth-1)
        {
            findMax(i+1 , j);
            findMax(i+1 , j+1);
        }
        else if(i == depth-1)
        {
            if(sumStack.top() > maxSum )
                maxSum = sumStack.top();
        }
        sumStack.pop();
    }
}

int main()
{
    ifstream dataInput;
    string fileName;
    cout << "Give file name: " << endl;

    cin >> fileName;
    
    dataInput.open(fileName , ios::in);

    while(!dataInput.eof())
    {
        vector<int> tempVec;
        int tempInt;
        for (int j = 0; j <= depth; j++)
        {
            dataInput >> tempInt;
            tempVec.push_back(tempInt);
        }
        pyramid.push_back(tempVec);
        depth++;
    }

    findMax(0 , 0);

    cout << maxSum << endl;

    return 0;
}