
/* 
Author: Necati KARAGOZ
*/


#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>


/**
 * Complexity  = 0(N^3) = 
 */

int LargestSum_BruteForce(int arr[], int n)
{
    int largets_Sum = 0;
    for(int i = 0; i< n ; i++)
    {
        for(int j = i; j<n; j++)
        {
            int subarraySum = 0;
            for(int k = i; k<=j; k++)
            {
                subarraySum += arr[k];
            }

            largets_Sum = std::max(largets_Sum, subarraySum);
        }
    }
    return largets_Sum;

}

int LargestSum_BruteForce_vector(std::vector<int> A) 
{
    
    int largets_Sum = INT_MIN;
    for(int i = 0; i< A.size() ; i++)
    {
        for(int j = i; j<A.size(); j++)
        {
            int subarraySum = 0;
            for(int k = i; k<=j; k++)
            {
                subarraySum += A[k];
            }

            largets_Sum = std::max(largets_Sum, subarraySum);
        }
    }
    return largets_Sum;
    
}


/**
 * Complexity  = 0(N) + 0(N^2) =  0(N^2)
 */
int LargestSum_Prefix_Sum(int arr[], int n)
{
    //prefixsum
    int prefix[n] = {0};
    prefix[0] = arr[0];

    for(int i = 1; i<n; i++)
    {
        prefix[i] = prefix[i-1] + arr[i];

    }

    //largest sum logix

    int largets_Sum = 0;
    for(int i = 0; i< n ; i++)
    {
        for(int j = i; j < n; j++)
        {
            int subarraySum = (i > 0 ) ? prefix[j] - prefix[i -1] : prefix[j] ;

            largets_Sum = std::max(largets_Sum, subarraySum);
        }
    }

    return largets_Sum;
}


    

/**
 * Complexity  = 0(N) 
 */
int LargestSum_KadanesSum(int arr[], int n)
{
    //prefixsum
    int currentSum = 0;
    int largetsSum = 0;


    for(int i = 1; i< n ; i++)
    {
        currentSum = currentSum + arr[i];
        if(currentSum < 0)
        {
            currentSum = 0;

        }
        if(currentSum > largetsSum)
        {
            largetsSum = currentSum;
        }
    }

    return std::max(largetsSum, currentSum);
}


int LargestSum_KadanesSum_vector(std::vector<int> A) {
    
    int currentSum = 0;
    int largetsSum = 0;


    for(int i = 1; i< A.size() ; i++)
    {
        currentSum = currentSum + A[i];
        if(currentSum < 0)
        {
            currentSum = 0;

        }
        if(currentSum > largetsSum)
        {
            largetsSum = currentSum;
        }
    }

    return std::max(largetsSum, currentSum);
    
}

int lowerBound(std::vector<int> A, int Val) 
{
    // your code goes here
    
    int maxloverBound = -1;
    
    for(int i : A)
    {
        
        if(i <= Val)
        {
            maxloverBound = i;
        }
    }
    

    return maxloverBound;
    
}


int main ()
{
    std::cout << "FindLargestSumOfaSubArray\n";

    int testArr[] = {-2,3,4,-1,5,-12,6,1,3};
    
    int result = LargestSum_BruteForce(testArr, sizeof(testArr)/sizeof(int));

    std::cout << "LargestSum_BruteForce Sum  = " << result << std::endl;

    result = LargestSum_Prefix_Sum(testArr, sizeof(testArr)/sizeof(int));

    std::cout << "LargestSum_Prefix_Sum = " << result << std::endl;


    result = LargestSum_KadanesSum(testArr, sizeof(testArr)/sizeof(int));

    std::cout << "LargestSum_KadanesSum = " << result << std::endl;

    std::vector<int> vec = {-2,3,4,-1,5,-12,6,1,3};

    result = LargestSum_KadanesSum_vector(vec);

    std::cout << "LargestSum_KadanesSum = " << result << std::endl;

    std::vector<int> vecx = {-1,-1, 2,3,5 };
    //std::vector<int> vecx = {1, 2, 3,4,6 };
    
    result = lowerBound(vecx, 0);

    std::cout << "LlowerBound= " << result << std::endl;
}

