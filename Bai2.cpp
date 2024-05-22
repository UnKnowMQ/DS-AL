#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll modInverse(ll a,ll m)
{
	for(int i = 1;i < m ;i++)
	{
		if((a*i) % m == 1)
			return i;
	}
}
ll mod(ll a,ll b, ll c)
{
	int a1[32];
	int i = 0;
	while(b > 0)
	{
		a1[i] = b% 2;
		i++;
		b/=2;
		
	}
	ll f=1;
	for(int j =i-1;j >=0;j-- )
	{
		f=(f*f) %c;
		if(a1[j] ==1)
		f=(f*a) %c;
	}
	return f;
}
bool isPrime(ll m )
{
	for(int i = 2; i <sqrt(m);i++)
	{
		if(m % i == 0)
			return false;
	}
	return true;
}
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	srand(time(NULL));
	ll q, p;
	do{
		q = rand() ;
		p = rand() ;
	}while(q == 0|| p == 0|| q == p||isPrime(q) == false|| isPrime(p) == false);
	ll n = q*p;
	ll phi  = (p -1)*(q - 1);
	ll e = 2;
	while(e < phi-1)
	{
		if(gcd(e,phi) == 1)
			break;
		e++;
	}
	ll d = modInverse(e,phi);
	cout<<"(n,e): "<< n <<" "<<e;
	cout<<"\n(n,d): "<<n << " "<<d;
	//encrypt
	string text;
	cout<<"\nNhap ban ro:";
	getline(cin,text);
	ll br[text.length()];
	ll bm[text.length()];
	cout<<"\nBan ma:";
	
	for(int i = 0;i< text.length();i++)
	{
		br[i] = int(text[i]);
	}
		for(int i = 0;i< text.length();i++)
	{
		bm[i] = mod(br[i],e,n);
		cout<<bm[i]<<" ";
	}
	//decrypt
	cout<<"\nPlain text: ";
	for(int i = 0;i< text.length();i++)
		cout<<char(mod(bm[i],d,n));
	
}