#include <bits/stdc++.h>

using namespace std;
//tim kiem xem x co trong mang khong? 
//sap xep
//lower_bound phan tu dau tien >=x
//upper_bound phan tu dau tien >x
int main()
{
	int a[13];
		for(int i = 0 ;i< 13;i++)
	{
		a[i] = rand() % 10;
	}
	sort(a,a+13);
	for(int i = 0 ;i < 13;i++)
	{
		cout<< a[i] << " ";
	}
	cout<<endl;

	auto it  = lower_bound(a,a + 13,1);
	//giai con tro ra gia tri
	cout<< *it;
	//vi tri cua gia tri
	cout<<endl;
	cout<< (it - a);
}
