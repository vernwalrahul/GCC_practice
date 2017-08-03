#include<iostream>

using namespace std;
int N;
void traverse(int **A, int L[], int M, int N, int rec_no)
{
	int i, j;
	int r=M-2*rec_no, c=N-2*rec_no;
	for( i=0;i<c;i++)
		L[i]=A[rec_no][rec_no+i];

	for( i=c, j=1;j<r;i++,j++)
		L[i]=A[rec_no+j][N-1-rec_no];

	for( i=r+c-1,j=c-1;j>0;i++,j--)
		L[i]=A[M-1-rec_no][rec_no+j-1];

	for(i=r+2*c-2, j=r-1;j>1;i++, j--)
		L[i]=A[rec_no+j-1][rec_no];

	// for(int i=0;i<2*(r+c)-4;i++)
	// 	cout<<L[i]<<" ";
	// cout<<endl;
}

void shift_linearly(int L [], int to_shift, int length, int **A, int rec_no, int M, int N)
{
	int i, j;
	int r=M-2*rec_no, c=N-2*rec_no;
	//cout<<"r="<<r<<" c="<<c<<" length="<<length<<endl;
	for( i=0;i<c;i++)
		A[rec_no][rec_no+i]=L[(i+to_shift)%length];

	for( i=c, j=1;j<r;i++,j++)
		A[rec_no+j][N-1-rec_no]=L[(i+to_shift)%length];

	for( i=r+c-1,j=c-1;j>0;i++,j--)
		A[M-1-rec_no][rec_no+j-1]=L[(i+to_shift)%length];

	for(i=r+2*c-2, j=r-1;j>1;i++, j--)
		A[rec_no+j-1][rec_no]=L[(i+to_shift)%length];

}

int main()
{
	int M, R;
	cin>>M>>N>>R;

	int **A;

	A=new int*[M];

	for(int i=0;i<M;i++)
	{
		A[i]=new int[N];
			for(int j=0;j<N;j++)
					 { cin>>A[i][j];  }
		
	}
	//cout<<endl;
	if(M<N)
	{
		
		for(int rec_no=0;rec_no<M/2;rec_no++)
		{ 
		 int L[2*(M+N)-4*(rec_no+1)];
	     traverse(A,L,M,N,rec_no);
	     int length=2*(M-2*rec_no+N-2*rec_no)-4;
	     int to_shift=R%(length);
	     shift_linearly(L, to_shift, length, A, rec_no, M, N);

		}

		for(int i=0;i<M;i++)
		{
			
			for(int j=0;j<N;j++)
				 cout<<A[i][j]<<" "; 
			cout<<endl;
		}
	
	}
	else
	{
		for(int rec_no=0;rec_no<N/2;rec_no++)
		{ 
		 int L[2*(M+N)-4*(rec_no+1)];
	     traverse(A,L,M,N,rec_no);
	     int length=2*(M-2*rec_no+N-2*rec_no)-4;
	     int to_shift=R%(length);
	     shift_linearly(L, to_shift, length, A, rec_no, M, N);

		}

		for(int i=0;i<M;i++)
		{
			
			for(int j=0;j<N;j++)
				 cout<<A[i][j]<<" "; 
			cout<<endl;
		}
	}



	return 0;
}