#include<bits/stdc++.h>

using namespace std;
int modInverse(int a, int m)

{
	for(int i = 1;i < m;i++)
	{
		if((a*i) % m == 1)
			return i;
	}
}
int main()
{
	string text;
	cout<<"Nhap vao ban ro: ";
	getline(cin,text);
	//encrypt
	string ctext ="";
	int a,b;
	cout<<"\nNhap vao a,b: ";
	cin>>a>>b;
	
	for(int i = 0;i < text.length();i++)
	{
		if(isupper(text[i]))
		{
			ctext += char( (a* (int(text[i]) - 65 )+b ) %26 +65);
		}
		else if(text[i] == ' ')
			ctext += ' ';
		else if(!isalpha(text[i])&&text[i] != ' ')
			ctext+=text[i];
				
		else{
			ctext += char( (a* (int(text[i]) - 97 )+b ) %26 +97);
		}
	}
	cout<<"\n" << ctext;
	//decrypt
	string plain = "";
		for(int i = 0;i < ctext.length();i++)
	{
		if(isupper(ctext[i]))
		{
			int kt = int(( modInverse(a,26) *(ctext[i] - 65 - b)) %26);
			while(kt < 0)
			kt+=26;
			plain += char(kt +65 );
		}
		else if(ctext[i] == ' ')
			plain += ' ';
			else if(!isalpha(ctext[i]) && ctext[i] != ' ')
				plain+=ctext[i];
				
		else{
			int kt = int(( modInverse(a,26) *(ctext[i] - 97 - b)) %26);
			while(kt < 0)
			kt+=26;
			plain += char( kt+97);
		}
	}
	cout<<"\nBan ro:"<<plain;

}