#include<iostream>
#include<string.h>
using namespace std;
 
long long int tree[1000003];
 
//update function
void update(int idx,int val,int n)
{
		while(idx<=n)
		{
			tree[idx]=tree[idx]+val;
			idx=idx +(idx & -idx);
		}
}
 
 
//read function
long long int read(int idx)
{
		int sum=0;
		while(idx>0)
		{
	
			sum=sum+tree[idx];
			idx=idx-(idx & -idx);
		}
		return sum;
}
	
	
 
 
// main function
int main()
{
		long long int n,q,B,C,val,x;
		char A;
		memset(tree,0,sizeof(tree));
		cin>>n>>q;
		for(int i=1;i<=n;++i)
		{
			cin>>val;
			update(i,val,n);
		}
	
		while(q--)
		{
			cin>>A>>B>>C;
			if(A=='G')
			{
				update(B+1,C,n);
			}
			if(A=='T')
			{
				update(B+1,-C,n);
			}
			if(A=='S')
			{
				x=(read(C+1)-read(B));
				cout<<x<<"\n";
			}
		}
		return 0;
}	
