#include<iostream>
#include<ctime>
#include<math.h>
#include<string>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
ll temp;
while(true)
{
	temp = a % b;
	if(temp == 0)
		return b;
	a = b;
	b  = temp;
}


}
ll modInverse(ll A, ll M)
{
for (ll X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}
ll mod(ll a1,ll m, ll n)
{
		ll a[32];
	int i = 0;
	while( m > 0)
	{
		a[i] = m % 2;
		m = m/2;
		i++;
	}
	ll f = 1;
	for(int k = i-1;k >= 0;k--)
	{
		f = (f*f) % n;
		if(a[k] == 1) 
		{
		f = (f*a1) % n;
		}
	}
	return f;
}
bool isPrime(ll n)
{
	for(int i = 2 ; i < sqrt(n);i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	srand(time(NULL));
	ll p,q;
	do{
		p = rand() %100;
		q = rand() %100;
	}while(  q != p && isPrime(q) != 1 || isPrime(p) != 1 &&q != p  );

	cout<<"q = "<<q<<"\tp = "<<p;
	ll n = q * p;
	ll k = (q - 1)*(p - 1);
	cout<<"\nPhi = " <<k;
	ll e = 2 ;
	while(e > 1 && e < k-1 )
	{
		if(gcd(e,k) == 1)
			break;
		else
			e++;
	}
	ll d = modInverse(e,k);
	cout<<"\nKhoa bi mat :(n,e) = "<<n <<" "<< e;
	cout<<"\nKhoa cong khai :(n,d) = "<<n <<" "<< d;
	ll M = rand() %100;
	string text= "hello world";
	int br[text.length()] ;
	for(int i =0 ;i < text.length();i++)
	{
		br[i] = (int)text[i]; 
	}
	cout<<"\nBan ro:" << text;
	int bm[text.length()];
		for(int i =0 ;i < text.length();i++)
	{
		bm[i] = mod(br[i],e,n);
	}
	cout<<"\nBan mat:";
		for(int i =0 ;i < text.length();i++)
	{
		cout<<(char)bm[i];
	}
	
	//decrypt
	cout<<"\nBan ro:" ;
			for(int i =0 ;i < text.length();i++)
	{
		cout<<(char)mod(bm[i],d,n);
	}


	return 0;
	
}
