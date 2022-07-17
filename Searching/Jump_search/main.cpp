#include <iostream>
#include <vector>
void printResults(int res);
int jumpSearch(std::vector<int>arr, int value);
int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin>>value;
    std::cout<<"Jump search "<< std::endl;
    int res = jumpSearch(arr,value);
    printResults(res);
    return 0;
}
int jumpSearch(std::vector<int>arr, int value)
{
    int n = arr.size()-1;
    if(arr.size()== 0)
        return -1;

    int step = sqrt(n);
    int prev = 0;
    while(arr[fmin(step,n)-1] < value)
    {
        prev = step;
        step += sqrt(n);
        if(prev >= n)
            return -2;
    }
    while(arr[prev] < value)
    {
        prev++;
        if(prev == fmin(step,n))
            return -2;
    }
    if(arr[prev] == value)
        return prev;
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