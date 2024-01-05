#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int l,r;
	cin>>l>>r;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ma=0;
	for(int i=0;i<n;i++)
	{
		if(ma<a[i])
		{
			ma=a[i];
		}
	}
	int k=0;
	while(ma)
	{
		k+=1;
		ma=ma>>1;
	}
	int s[n][k];

	for(int i=0;i<n;i++)
	{
		int p=k-1;
	     while(a[i])	
	     {
	     	s[i][p]=(a[i]&1);
	     	a[i]=a[i]>>1;
	     	p-=1;
	     
	     }
		 while(p>=0)
		 {
		     s[i][p]=0;
		     p-=1;
		 }
	}
	

   for(int i=k-1;i>=0;i--)
   {
       int p=0;
       for(int j=0;j<n;j++)
       {
         p+=s[j][i];
          s[j][i]=p;
         
       }
   }
   for(int i=0;i<n;i++)
	{
	    for(int j=0;j<k;j++)
	    {
	        cout<<s[i][j]<<" ";
	    }
	    cout<<endl;
	}
	int res[k];
	if(l==0)
	{
		for(int i=0;i<k;i++)
		{
			if(s[r][i]== r+1)
			{
				res[i]=1;
			}
			else
			{
				res[i]=0;
			}
		}
	}
	else
	{
		for(int i=0;i<k;i++)
		{
			if(s[r][i]-s[l-1][i]== r-l+1)
			{
				res[i]=1;
			}
			else
			{
				res[i]=0;
			}
		}
	}
	for(int i=0;i<k;i++)
	{
	    cout<<res[i];
	}
	
	return 0;	
	
}
