#include <iostream>
#include <vector>
int ternarySearch(std::vector<int>arr, int start, int finish, int value);
void printResults(int res);
int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin>>value;
    std::cout<<"Ternary search "<< std::endl;
    int res = ternarySearch(arr,0,arr.size()-1,value);
    printResults(res);
    return 0;
}
int ternarySearch(std::vector<int>arr, int start, int finish, int value)
{
    if(arr.empty() == true)
        return -1;
    if(start <= finish)
    {
        int mid1 = start + (finish - start)/3;
        int mid2 = mid1 + (finish - start)/3;
        if(arr[mid1] == value)
            return mid1;
        if(arr[mid2] == value)
            return mid2;
        if(arr[mid1] > value)
            return ternarySearch(arr, start, mid1-1, value);
        if(arr[mid2] < value)
            return ternarySearch(arr, mid2+1, finish, value);
        return ternarySearch(arr, mid1 +1, mid2-1, value);
    }
    return -2;
}

void printResults(int res)
{
    if(res == -1)
        std::cout << "The array is empty\n" << std::endl;
    else if(res == -2)
        std::cout << "This number is not in the array\n" << std::endl;
    else
        std::cout << "Your required number at index "<<res << std::endl;
}