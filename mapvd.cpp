#include <bits/stdc++.h>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<int ,int > vd;
	vd[1] = 10;
	vd[2] = 20;
	vd.insert({3,30});
	vd.insert({4,10});
	//truy cap
	for(map<int,int> ::iterator it = vd.begin();it != vd.end();it++)
	{
		cout<<(*it).first << " " << (*it).second<< "\n";
	}
	for(pair<int,int> it : vd)
	{
		cout<<endl;
		cout<< it.first << " " << it.second;
	}
}
