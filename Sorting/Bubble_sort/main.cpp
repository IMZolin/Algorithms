#include <iostream>
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
int main() {
    //std::cout << "Hello, World!" << std::endl;
    int arr[] = {3, 5, 7, 1, 2, 8, 9, 4,6};
    int N = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Start array"<<std::endl;
    printArray(arr,N);
    bubbleSort(arr,N);
    std::cout<<"After bubble sort"<<std::endl;
    printArray(arr,N);
    return 0;
}
void bubbleSort(int arr[], int n)
{
    int tmp;
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}