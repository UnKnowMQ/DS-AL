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
	//right must be the number before privot( privot is the last number)
		int left = low, right  = high-1	, prot = a[high];
	while( true)
	{
		// choose 2 number that need to change direction #1st
		while(left <= right && a[left] < prot) 
		{
		
		left++;
	}
		while(right >= left && a[right] > prot) 
		{
		
		right--;
	}
		
		//end of changing directions, ready to change privot to its correct direction 
		if(left >=  right) 
		
		{
		
		break;
	}
		// change direction of 2 number in #1st
		swap(a[left],a[right]);
		// need to change pointer to 2 number after
		left++;
		right--;
		
	}
	// change privot to its correct direction
	swap(a[left],a[high]);
	//Finish 1 turn of recursion and return the dir of the correct 1 number, ready to divide and solve
	return left;
}
void quicksort(vector<int> a,int low,int high)
{
	if(low < high)
	{
	// dividing array 
	int pi = part(a,low,high);
	//solve the 2 divided array 
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

	
}
