
/* 
Author: Necati KARAGOZ
*/


#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

pair<int, int> ClosestSum(std::vector<int> arr, int x) 
{
    pair <int,  int>  result ; 
    int offset = INT_MAX;

    for(int i = 0; i<arr.size() -1; i++)
    {
        for(int j = i+1; j<arr.size(); j++)
        {
            int subarraySum = 0;
            int test = abs((arr[i] + arr[j]) - x);
            if ( test < offset)
            {
                offset = test;
                std::cout << "i = "<< i << " j=" << j <<  " ofset " << offset << endl;
                result.first = arr[i];
                result.second = arr[j];
            }
        }
    }

    return result;


    
}


int main ()
{
    std::cout << "ClosestSum\n";

    std::vector<int> vec = {10,22,28,29,30,40};
    
    pair<int, int > result = ClosestSum(vec, 54);

    std::cout << "LlowerBound= " << result.first << " " << result.second << " expected = 22, 30 " << std::endl;
}

