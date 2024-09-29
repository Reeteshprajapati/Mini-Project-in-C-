#include<iostream>
#include<cstdlib>// contains a superset of the traditional C functions, macros, and datatypes
#include<ctime>
#include<string>

using namespace std;


string getpassword(int length)
{
	string password="";
	string characters="asgkiyrewhuwiqhigjdskmckjasdsfhtrjyiupoqwrerysfdgagdgctf3wfuiojcoudgactdfchvoavhuoeh0123456789";
	int charsize = characters.size();
	srand(time(0));
	int randomIndex;
	for(int i=0;i<length;i++)
	{
		randomIndex =rand() %charsize;
		password = password+characters[randomIndex];
	}
	return password;
}
int main()
{
	int length;
	cout<<"enter the lemgth of the password::";
	cin>>length;
	string password =getpassword(length);
	cout<<"Genrated password::"<<password;

	
	return 0;
}
