#include <iostream>
using namespace std;

void selectionSort(int arr[],int size)
{
    int i,j,minIND;
    for (i=0; i<size-1; i++)
    {
        minIND=i;
        for(j=i+1; j<size; j++)
        {
            if (arr[j]<arr[minIND])
        {
            minIND=j;
        }
        }
        if(minIND!=i)
        {
            swap(arr[minIND],arr[i]);
        }
    }
}

void display(int arr[],int size)
{
    cout<<"\nSorted Array: ";
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={5,4,8,1,2,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before Sort: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    selectionSort(arr,size);
    display(arr,size);
}