#include <iostream>
#include <vector>
int bSearch(std::vector<int>arr, int value);

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> arr2 = {1};
    //Tests
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin >> value;
    int res = bSearch(arr, value);
    if(res == -1)
        std::cout << "The array is empty\n" << std::endl;
    if(res == -2)
        std::cout << "This number is not in the array\n" << std::endl;
    else
        std::cout << "Your required number is "<<res << std::endl;

    return 0;
}
int bSearch(std::vector<int>arr, int value)
{
    int size = arr.size();
    int start, finish;
    start = 0;
    finish = size;
    if(size == 0)
        return -1;
    if(start == finish)
        return arr[0];
    while(start < finish)
    {
        int mid = (start + finish) / 2;
        if(value == arr[mid])
            return arr[mid];
        else if(value > arr[mid])
            start = mid + 1;
        else
            finish = mid - 1;
    }
    return -2;
}
