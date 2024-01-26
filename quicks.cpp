#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
int c = a;
a = b;
 b = c;
}
int part(vector<int> a,int low, int high)
{
		int left = low, right  = high-1	, prot = a[high];
	while( true)
	{
		while(left <= right && a[left] < prot) 
		{
		
		left++;
	}
		while(right >= left && a[right] > prot) 
		{
		
		right--;
	}
		if(left >=  right) 
		
		{
		
		break;
	}
		swap(a[left],a[right]);
		left++;
		right--;
		
	}
	swap(a[left],a[high]);
	return left;
}
void quicksort(vector<int> a,int low,int high)
{
	if(low < high)
	{
	
	int pi = part(a,low,high);
	quicksort(a,low , pi - 1);
	quicksort(a, pi +  1,high);
}
}
int main()
{
	vector<int> tryan(10);
	
	for(int i = 0 ;i < tryan.size() - 1;i++)
	{
		tryan[i] = rand() % 10 ;
	}
		for(int i = 0 ;i < tryan.size() - 1;i++)
	{
		cout<< tryan[i] << " ";
	}
	quicksort(tryan,0,tryan.size() - 1);
	cout << endl; 
	for(int i = 0 ;i < tryan.size() - 1;i++)
	{
		cout<< tryan[i] << " ";
	}
	int c = 4;
	int d = 5;
	swap(c,d);
	cout<< " \n" << c << " " << d;
	
}
