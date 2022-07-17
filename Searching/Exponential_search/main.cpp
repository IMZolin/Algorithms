#include <iostream>
#include <vector>
int bRecSearch(std::vector<int>arr, int start, int finish, int value);
int expSearch(std::vector<int>arr, int value);
void printResults(int res);
int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin>>value;
    std::cout<<"Exponential search "<< std::endl;
    int res = expSearch(arr,value);
    printResults(res);
    std::cout<<"Binary search "<< std::endl;
    res = bRecSearch(arr,0,arr.size()-1,value);
    printResults(res);
    return 0;
}

int expSearch(std::vector<int>arr, int value)
{
    if(arr.size()== 0)
        return -1;
    if(arr[0] == value)
        return 0;
    int i = 1;
    while(i < (arr.size()-1) && arr[i] <= value)
        i *= 2;
    return bRecSearch(arr,i/2, fmin(i,arr.size()-1),value);
}

int bRecSearch(std::vector<int>arr, int start, int finish, int value)
{
    if(arr.size()== 0)
        return -1;
    if(finish >= start)
    {
        int mid = start + (finish - start) / 2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] > value)
            return bRecSearch(arr,start,mid-1,value);
        else
            return bRecSearch(arr,mid+1,finish,value);
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
