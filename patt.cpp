#include <iostream>
using namespace std;

int main(){
    int n=5; //rows
    int i=1,j;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n-i+1;++j)
        {
            cout<<"  "; //spaces
        }

        for (j=i;j<=i*2-1;++j)
        {
            cout<<j<<" "; //prints from left till middle
        }

        for (j=i*2-2;j>=i;j--)
        {
            cout<<j<<" "; //prints from middle to right
        }
        cout<<endl;
    }
}