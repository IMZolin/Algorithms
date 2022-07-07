#include <iostream>
#include <vector>
int bSearch(std::vector<int>arr, int value);
int bRecSearch(std::vector<int>arr, int start, int finish, int value);
int linearSearch(std::vector<int>arr, int value);
void printResults(int res);

int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    //Tests
    int value;
    std::cout<<"Enter your number "<< std::endl;
    std::cin >> value;
    int res = linearSearch(arr, value);
    std::cout<<"Linear search "<< std::endl;
    printResults(res);
    res = bSearch(arr, value);
    std::cout<<"Binary search "<< std::endl;
    printResults(res);
    int size = arr.size();
    res = bRecSearch(arr, 0,size-1,value);
    std::cout<<"Binary search using recursion "<< std::endl;
    printResults(res);
    return 0;
}
int bSearch(std::vector<int>arr, int value)
{
    int mid;
    int start = 0, finish = arr.size()-1;
    //printf("%d",finish);
    if(arr.size() == 0)
        return -1;
    while(finish - start > 1)
    {
        mid = (start + finish) / 2;
        if(arr[mid] < value)
            start = mid + 1;
        else
            finish = mid;
    }
    if(arr[start] == value)
        return start;
    if(arr[finish] == value)
        return finish;
    return -2;
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

int linearSearch(std::vector<int>arr, int value)
{
    if(arr.size() == 0)
        return -1;
    for(int i=0; i<arr.size(); ++i)
    {
        if(arr[i] == value)
            return i;
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