#include <iostream>

using namespace std;

int parent(int i)
{
	return (i-1)/2;
}

int left_child(int i)
{
	return 2*i+1;
}

int right_child(int i)
{
	return 2*i+2;
}

void swap(int *h, int i1, int i2)
{
	int temp=h[i1];
	h[i1]=h[i2];
	h[i2]=temp;
}

int get_minimum(int *h, int n)
{
	return h[0];
}

void Minheapify(int *h, int n, int i)    //heap, size, from root index=i assuming subtree to be already heapified.
{
	// cout<<" in min_heapify n = "<<n<<" i = "<<i<<endl;
	int l=left_child(i);
	int r=right_child(i);

	int smallest=i;
	if(l<n && h[l]<h[i])
		smallest=l;
	if(r<n && h[r]<h[smallest])
		smallest=r;

	if(smallest==i)
		return;
	swap(h, smallest, i);
	Minheapify(h, n, smallest);
}

int extract_min(int *h, int n)
{
	int root=h[0];
	h[0]=h[n-1];
	n--;
	Minheapify(h, n, 0);
	return root;
}

void buildheap(int *s, int n)
{
 for(int k=n/2-1;k>=0;k--)
 	Minheapify(s, n, k);
}

void method1(int *A, int *B, int m, int n, int k)
{
	int *s, count=0;
	int no_element=m*n;
	s= new int[m*n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			s[count++]=A[i]+B[j];

	buildheap(s, no_element);	
	while(k>0)
	{
		//Minheapify(s, no_element, 0);
		cout<<extract_min(s, no_element)<<" ";
		no_element--;
		k--;
	}	
	cout<<endl;
}

int main()
{
	int m, n, k, *A, *B;
	cin>>m;
	cout<<"m = "<<m<<endl<<" element are: \n";
	A = new int[m];
	for(int i=0;i<m;i++)
		{ cin>>A[i]; cout<<A[i]<<" "; }
	cout<<endl;
	cin>>n;
	B = new int[n];
	cout<<"n = "<<n<<endl<<" element are: \n";
	for(int i=0;i<n;i++)
		{ cin>>B[i]; cout<<B[i]<<" "; }
	cout<<endl;
	cin>>k;
	cout<<"k = "<<k<<endl;
	method1(A, B, m, n, k);
	return 0;
}