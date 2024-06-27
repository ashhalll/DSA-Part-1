#include <iostream>
using namespace std;

void bubbleSort(int arr[],int size)
{
    int i,j;
    bool swapped;
    for (i=0; i<size-1; i++)
    {
        swapped=false;
        for (j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }

        if (swapped==false)
        {
            break;
        }
    }
}

void PrintArray(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={23,12,56,34,67};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before Sort: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort(arr,n);

    cout<<"\nSorted Array: ";
    PrintArray(arr,n);
}