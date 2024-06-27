#include <iostream>
using namespace std;

int merge(int arr[],int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int* first = new int[len1]; 
    int* second = new int[len2];

    int minIndex=s;
    for (int i=0;i<len1;i++)
    {
        first[i]=arr[minIndex];
        minIndex++;
    }

    minIndex=mid+1;
    for (int i=0;i<len2;i++)
    {
        second[i]=arr[minIndex];
        minIndex++;
    }

    //merge
    int index1=0;
    int index2=0;
    minIndex=s;

    while (index1<len1 && index2<len2)
    {
        if (first[index1] > second[index2])
        {
            arr[minIndex++]=first[index1++];
        }
        else
        {
            arr[minIndex++]=second[index2++];
        }
    }

    while (index1<len1)
    {
        arr[minIndex++]=first[index1++];
    }
    
    while (index2<len2)
    {
        arr[minIndex++]=second[index2++];
    }
}

void mergesort(int arr[],int s, int e)
{
    if (s>=e)
    {
        return;
    }

    int mid=(s+e)/2;

    mergesort(arr,s,mid);
    mergesort(arr, mid+1,e);
    merge(arr,s,e);
}

int main()
{
    int arr[10]={14,21,3,12,15,7,5,19,1,6};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"before sort: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergesort(arr,0,size-1);
    cout<<"Sorted: ";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}