#include<bits/stdc++.h>
using namespace std;
int char_in_string(char *x,char s)
{
	for(int i = 0 ;i < strlen(x) -1;i++)
	{
		if(x[i] == s)
			return i;
	}
	return -1;
}
bool boyer_h_p(char *p,char *t )
{
	int v =  strlen(p);
	 int i = v -1;
	 while(i < strlen(t))
	 {
	 	int k  = v-1;
	 	while(k > -1 && t[i] == p[k])
	 	{
	 		i--;
	 		k--;
		 }
		 if(k < 0)
		 {
		 	return true;
		 	
		 }
		 else{
		 	int x = char_in_string(p, t[i]);
		 	if(x < 0)
		 	{
		 		i = i+v;
		 		
			 }
			 else{
			 	i = i + v - x-1;
			 }
		 }
	 }
	 return false;
	
}
int main()
{
	char *c = "newchar";
	char *p = "ewc";
	cout<<boyer_h_p(p,c);
	
}
