#include<iostream>
#include<vector>
#include<stdint.h>
using namespace std;

int find_steps(int n)
{
    int step= (n/5+(n%5)/2+(n%5)%2);
    cout<<"for n="<<n<<" steps="<<step<<" 5*"<<n/5<<" +2*"<<((n%5)/2)<<" +1*"<<(n%5)%2<<endl;
    return step;
}

int find_op(int A[], int reference, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=find_steps(A[i]-reference);
    return sum;
}

int main()
{
    uint64_t p;
    cin>>p;
    cout<<"\n p="<<p<<endl;

    return 0;
}