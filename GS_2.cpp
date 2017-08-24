#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct A
{
	int value;
	int allowed_no;
};

bool check(A l, A r)
{
	return l.value<r.value;
}

long long int find_max_stock(long int n, vector<A> &stock, long long int k)
{
	long  long int max_stock=0;
	for(long int i=0;i<n;i++)
	{
		long long int capacity=k*1.0/stock[i].value;
		// cout<<"allowed="<<stock[i].allowed_no<<" capacity="<<capacity<<endl;
		if(capacity>stock[i].allowed_no)
		{
			max_stock+=stock[i].allowed_no;
			// cout<<"max_stock now="<<max_stock<<"k="<<k<<endl;
			k-=stock[i].allowed_no*stock[i].value;

		}
		else
		{
			max_stock+=capacity;
			k-=capacity*stock[i].value;
		}
		if(k<=0)
			break;
	}
	return max_stock;
}

int main()
{
   long int n;
	cin>>n;
	vector<A> stock(n); long long int max_stock=0, k;
	for( long int i=0;i<n;i++)
	{
		cin>>stock[i].value; stock[i].allowed_no=i+1;
	}
	cin>>k;
	sort(stock.begin(), stock.end(), check);
	max_stock = find_max_stock(n, stock, k);
	cout<<max_stock<<endl;
	return 0;
}