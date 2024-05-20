#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef long long ll;


ll tinhmod(ll a1,ll m,ll n)
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
ll modInverse(ll A,ll M)
{
		for(ll i = 1;i < M;i++)
		{
			if((A *i)% M ==1)
			{
				return i;
			}
		}	
		
}

int main()
{
	srand(time(NULL));
	ll p ;
	ll a ;
	ll x;
	
	do{
	 p = rand();
	 a =  rand() % 10;
	 x = rand();
	}
	while(p == 0 || a == 0 || x == 0);
	ll y  = tinhmod(a,x,p);
	//p, a, x
	//p, a, y
	cout<< "khoa bi mat {p,a,x} : p = " << p << "\ta = " << a << "\tx = " << x;
	cout<< "\nkhoa cong khai {p,a,y} : p = " << p << "\ta = " << a << "\ty = " << y;
	ll k;
	do {
		k = rand() ;
	}while( 1 <= k && k <= p-1 );
	//encrypt
	ll k1 = tinhmod(y,k,p);
	string text = "làm sao mà có d?u";
	cout <<  "\nBan ro: " << text;
	ll C1 = tinhmod(a,k,p);
	ll C2[text.length()];
	for(int i =  0 ;i < text.length();i++)
	{
		 C2[i] = ( k1 * int(text[i]))% p;
	}
	for(int i  =0 ;i < text.length();i++)
	{
	
	cout << "\nCipher text : C1 = " << C1 << "\tC2 = " << C2[i];
}
	//decrypt
	ll ke = tinhmod(C1,x,p);
	cout << "\n K = " << ke;
	ll inversek = modInverse(ke,p) ;
	cout << "\nInverse K: " << inversek;
	string ro;
	for(int i = 0 ;i < text.length();i++)
	{
		ro+= char(inversek * C2[i] %p);
	//	cout << "\nBan ro : " << ro = (inversek * char(C2[i]) %p );
	}
	cout<< "\nBan ro : " << ro;
}
