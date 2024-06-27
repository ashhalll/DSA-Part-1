#include <iostream>
using namespace std;

int binarySearch(int arr[],int s,int e,int key)
{
    if(s<e)
    {
    int midInd=(s+e)/2;
    int midVal=arr[midInd];

    if(midVal==key)
    {
        return midInd;
    }
    else if(key<midVal)
    {
        return binarySearch(arr, s, midInd-1, key);
    }
    else
    {
        return binarySearch(arr, midInd+1, e, key);
    }
    }
}

int main()
{
    int arr[]={3,5,9,13,27,34};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
      for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Search Value: ";
    cin>>key;

    int ans=0;
    ans=binarySearch(arr,0,size-1,key);
    if(ans!=0)
    {
        cout<<"Element found at Position: "<<ans<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }
}