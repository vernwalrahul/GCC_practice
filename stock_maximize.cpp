#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--) {
		int n;
		uint64_t total_profit=0;
		cin>>n;
		unsigned int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];

		uint64_t max_so_far=0;
		int i=n-1;
		while(i>=0){
			if(A[i]>max_so_far)
				max_so_far=A[i];
			total_profit+=max_so_far - A[i];
			i--;
		}
		cout<<total_profit<<endl;
	}

	return 0;
}