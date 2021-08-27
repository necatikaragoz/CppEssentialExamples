
/* 
Author: Necati KARAGOZ
*/


#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> Krotate(std::vector<int> a, int k) 
{
    std::vector<int> tempArr;

    std::cout << " k = "<< k << endl; 

    int j = 0;
    int offset = a.size() - k ;
    for(int i = offset; i < a.size(); i++)
    {
        tempArr.emplace_back( a[i] );
        std::cout << " tempArr i = "<< tempArr[j] << endl; 
        j++; 
    }

    for(int i = 0; i< offset; i++)
    {
        tempArr.emplace_back( a[i] );
        std::cout << " tempArr i = "<< tempArr[j] << endl; 
        j++;
         
    }

    return tempArr;
}


int main ()
{
    std::cout << "Krotate\n";

    std::vector<int> vec = {10, 22, 28, 29, 30, 40};
    std::vector<int> expected = {28, 29, 30, 40, 10, 22};
    
    vector<int> vecResult = Krotate(vec, 4);

    std::cout << " vecResult<< \n";

    for(int i = 0; i< vec.size(); i++)
    {
        cout << "expected = " <<  expected[i]  << " result " << vecResult[i] << endl; 
    }
}

