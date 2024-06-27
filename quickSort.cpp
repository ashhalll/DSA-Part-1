#include <iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
    int count=0;
    int pivot=arr[s];
    for (int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

    int pivotInd=s+count;
    swap(arr[pivotInd],arr[s]);

    int i=s;
    int j=e;

    while(i<pivotInd && j>pivotInd)
    {
        if (arr[i]>arr[j])
        {
            swap(arr[i],arr[j]);
            
        }
        i++;
        j--;
    }
    return pivotInd;
}


int quickSort(int arr[],int s,int e)
{
    if (s>=e)
    return 0;

    int p = partition(arr,s,e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}

int main()
{
    int arr[]={3,1,4,5,2};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"before sort: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr,0,size-1);
    
    cout<<"sorted: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}