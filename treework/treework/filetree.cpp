#include<iostream>
#include<strinig>
using namespace std;
struct file
{
	string name;
	file* childrenfile;
	file* brotherfile;

};
class filetree
{
private:
	file* l;
public: 
	filetree() 
	{
		cout << "please enter the filetree name: ";
		cin >> l->name;
		l->brotherfile = NULL;
		l->childrenfile = NULL;
	}
	file* found() 
	{
	
	}
	void addchild() 
	{

		file* p = new file;
		string name;
		cout << "enter the name you want: ";
		cin >> name;
		if()

	}
	void addbother() 
	{
	
	}
	void showtree(int depth) 
	{
	
	}

};
int main() 
{
	char a;
	while (cin >> a) 
	{
		switch (a)
		{
		case 'q':
			cout << "Have a good day, sir" << endl;
			break;
			case '1'
				cout << "you will create a new filetree" << endl;

		default:
			break;
		}
	}
}