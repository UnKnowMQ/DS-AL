#include<iostream>

using namespace std;
void caitui(int **f,int *w,int *v,int n,int m)
{
	for(int j = 0;j <= m;j++) f[0][j] =0;
	for(int i = 1;i <= n; i++)
	{
		for(int j = 0;j <=m;j++)
		{
			f[i][j] = f[i -1][j];
			if(j > w[i] )
			{
				int temp = f[i-1][j - w[i]] + v[i];
				if(temp  > f[i][j])
				{
					f[i][j] = temp;
				}
			}
		}
	}
}
void truy(int **f,int *w,int n,int m)
{
	cout<<"\nMax value: "<<f[n][m];
	int i = n;int j = m;
	while(i != 0)
	{
		if(f[i][j] != f[i-1][j] )
		{
			cout<<"\nLay goi"<<i;
			j = j - w[i];
		}
		i--;
	}
}
int main()
{
	int v[4] = {0,2,3,4};
	int w[4] = {0,4,5,6};
	int k  = 10;
	int **f = new int*[4];
	for(int i =0;i <=4;i++)
	{
		f[i] = new int[11];
	}
	caitui(f,w,v,3,10);
	truy(f,w,3,10);
	
}
