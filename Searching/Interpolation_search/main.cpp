#include <iostream>
#include <vector>
void printResults(int res);
int interpolationSearch(std::vector<int>arr, int start, int finish, int value);
int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin>>value;
    std::cout<<"Interpol search "<< std::endl;
    int res = interpolationSearch(arr,0,arr.size()-1,value);
    printResults(res);
    return 0;
}
int interpolationSearch(std::vector<int>arr, int start, int finish, int value)
{
    int tmp;
    if(arr.empty() == true)
        return -1;
    if(start <= finish && value >= arr[start] && value <= arr[finish])
    {
        tmp = start + (((double)(finish - start)/(arr[finish]-arr[start]))*(value-arr[start]));
        if(arr[tmp] == value)
            return tmp;
        else if(arr[tmp] < value)
            return interpolationSearch(arr,tmp+1,finish,value);
        else
            return interpolationSearch(arr,start,tmp-1,value);
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