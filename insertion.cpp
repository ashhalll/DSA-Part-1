#include <iostream>
using namespace std;

void insertionSort(int arr[],int size)
{
    int i,j,key;
    for (i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void display(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={5,4,2,6,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before Sort: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertionSort(arr,n);

    cout<<"sorted array: ";
    display(arr,n);
}