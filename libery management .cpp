#include<iostream>
#include<fstream>

using namespace std;

class temp 
{
	string id,name,author,search;
	fstream file;
	public:
		void addbook();
		void showall();
		void extractbook();
}obj;


int main()
{
	
	char choice;
	cout<<"---------------------\n";
	cout<<"1 Show all Books\n";
	cout<<"2 Extract Book\n";
	cout<<"3 Add books (ADMIN)\n";
	cout<<"4 EXIT\n";
	cout<<"-----------------------\n";
	cout<<"Enter your choice :: ";
	cin>>choice;
	
	switch(choice)
	{

	case '1':
		cin.ignore();
		obj.showall();
	break;
	
	case '2':
		cin.ignore();
		obj.extractbook();
	break;
	
	case '3':
		cin.ignore();
		obj.addbook();
	break;
	case '4':
		return 0;
	break;
	
	default:
		cout:"invalid";
	break;	
	}
	return 0;
}

void temp :: addbook(){
	cout<<"\nenter book id ::";
	getline(cin,id);
	cout<<"\nenter book name ::";
	getline(cin,name);
	cout<<"\nenter book author name ::";
	getline(cin,name);
	
	
	file.open("bookData.txt",ios ::out | ios :: app);
	file<<id<<""<<name<<""<<author<<endl;
	file.close();	
}

void temp :: showall(){
	file.open("bookData.txt",ios::in);
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	
	cout<<"\n\n";
	cout<<"\t\t book id \t\t book name \t\t\t author name "<<endl;
	while(file.eof()){
		cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
		
		
		getline(file,id,'*');
		getline(file,name,'*');
		getline(file,author,'\n');
	}
	
	file.close();
}
void temp ::extractbook(){
	
	showall();
	cout<<"enter book id ::";
	getline(cin,search);
	
	file.open("bookData.txt",ios::in);
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	
	cout<<"\n\n";
	cout<<"\t\t book id \t\t book name \t\t\t author name "<<endl;
	while(!file.eof())
	{
		if(search==id){
			cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
			cout<<"book extract successfully...!";
		}	
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	}
	file.close();
}
