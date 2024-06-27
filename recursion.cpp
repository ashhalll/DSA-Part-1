#include <iostream>
using namespace std;

int fib(int n)
{
    if (n==0)
    {
        return 0;
    }
     if (n==1)
    {
        return 1;
    }
        int ans=fib(n-1)+fib(n-2);
        return ans;
    
}

int main()
{
    int n,ans;
    cout<<"Fibonacci Term: ";
    cin>>n;

    ans=fib(n);
    cout<<"Term: "<<ans<<endl;
}