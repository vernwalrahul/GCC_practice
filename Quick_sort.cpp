#include<iostream>

using namespace std;

int partition(int A[], int p, int q)
{
	int x=A[p];
	int i=p;
	for(int j=p+1;j<=q;j++)
	{
		if(A[j]<=x)
		{
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}

	}
	A[p]=A[i];
	A[i]=x;
	return i;
}

void Quick_sort(int A[], int p, int q)
{ int r;
	if(p<q)
	{
		r=partition(A, p, q);
		Quick_sort(A, p, r-1);
		Quick_sort(A, r+1, q);
	}
}

int main()
{	
	int n;
	cout<<"Enter the no of elements: ";
	cin>>n;
	int A[n];
	int p=0, q=n-1;
	for(int i=0;i<=q;i++)
		cin>>A[i];

	Quick_sort(A, p, q);
	cout<<"q="<<q<<endl;
	for(int i=0;i<=q;i++)
		cout<<A[i]<<" ";

	return 0;
}