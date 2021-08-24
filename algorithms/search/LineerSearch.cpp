
/* 
Author: Necati KARAGOZ
*/
//Lineer Search is a searching algorithm  to find the index of element in a given array

/* Run commands
 open terminal 
 cd .
 g++ -std=c++17 LineerSearch.cpp
 */



#include <iostream>
#include <array>


int LineerSearch_Ctype(int arr[], int n , int key)
{

    for(int  i=0; i< n; i++)
    {
        if(arr[i] == key)
            return i;
    }

    //key not found
    return -1;
}


template<std::size_t SIZE>
int LineerSearch_Cpp(std::array<int, SIZE>& arr, const int key) 
{
        for(int  i=0; i< arr.size(); i++)
        {
            if(arr.at(i) == key)
                return i;
        }   
    return -1;
}



template <class T>
int LinearSearch(T arr[], int n, T key) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == key)
			return i;

	}

	return -1;

}




int main ()
{
    std::cout << "Linear Search \n";

    int testArr[] = {1,2,3,4,5,6,7,8,10};
    
    int result = LineerSearch_Ctype(testArr, sizeof(testArr)/sizeof(int), 8);

    std::cout << "Ctype_result = " << result << std::endl;


    // Hint: After c++ 17
    std::array myArray {1,2,3,4,5,6,7,8,10};  

    int result2 = LineerSearch_Cpp(myArray, 8);

    std::cout << "Cpptype_result = " << result2 << std::endl;



    return 0;
}