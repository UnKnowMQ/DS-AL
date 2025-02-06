#include<bits/stdc++.h>
using namespace std;
int xau_con(char *s,char *t,int **L)
{
	for(int i = 0;i  <=strlen(s);i++) L[i][0] = 0;
	for(int j = 0;j <= strlen(t);j++)L[0][j] = 0;
	for(int i = 1;i <= strlen(s);i++)
	{
		for(int j = 1;j <=strlen(t) ;j++)
		{
			if(s[i-1] == t[j-1])L[i][j] =L[i-1][j-1] +1;
			else{
				L[i][j] = L[i-1][j] > L[i][j-1] ? L[i-1][j] :L[i][j-1];
				
			}
		}
	}
	return L[strlen(s)][strlen(t)];
		
}
void xau(char *s,char *t,int **L){
	
	int i = strlen(s);
	int j = strlen(t);
	int k = 0;
	char xc[xau_con(s,t,L)+1];
	while(L[i][j] != 0)
	{
		if(s[i-1] == t[j-1])
		{
			xc[k]  = s[i-1];
			k++;i--;j--;
			
		}
		else{
			if(L[i-1][j] > L[i][j-1])
			i--;
			else
			j--;
		}
	}
	xc[k] ='\0';
	strrev(xc); 
	cout<<"\nXau con:";
	for(int i = 0;i < strlen(xc);i++)
	{
		cout<<xc[i];
	}
}
int main()
{
	char *s = "abc";
	char *t = "aebdc";
	int **L = new int *[strlen(s)+1];
	for(int i = 0;i <= strlen(s);i++)
	{
		L[i] =new int[strlen(t)+1];
	}
	
	cout<<"\nSo ky tu " << xau_con(s,t,L);
	xau(s,t,L);
}
