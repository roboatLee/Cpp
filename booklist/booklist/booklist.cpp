#include<iostream>
#include<string>
using namespace std;
struct book
{
	string name;
	string code;
	float price;
	book* next;
	void show() 
	{
		cout << code << " " << name << " " << price << endl;
	}
};
void coutfuncation() 
{
	cout << "Welcome to book list system" << endl;
	cout << "    (1)create a list" << endl;
	cout << "    (2)add a new book" << endl;
	cout << "    (3)delect a book" << endl;
	cout << "    (4)find a book" << endl;
	cout << "    (5)show the list" << endl;
	cout << "please enter which operation you want to do(enter 'q' mean quit): ";
}
class list
{
public:
	book* books;
	string nameoflsit;
	list()
	{
		books = NULL;
	}
	~list()
	{
		cout << "I am done" << endl;
	}
	void addnewbook() 
	{
		cout << "Which part would you want insert(head, body, end): ";
		string a;
		string name;
		string code;
		float price;
		cin >> a;
		cout << "Please enter the book you want,quite by enter 0 0 0 : " << endl;
		while (cin >> code >> name >> price) 
		{
			if (name == "0" && code == "0" && price == 0)
			{
				cout << "成功退出" << endl;
				break;
			}
			else 
			{
				book* newbook = new book;
				newbook->code = code;
				newbook->name = name;
				newbook->price = price;

				if (a == "head")
				{
					newbook->next = books;
					books = newbook;
				}
				else if (a == "body")
				{
					cout << "Please enter the name you want to insert: ";
					string name;
					cin >> name;
					book* p = findbook();
					newbook->next = p;
					cout << "插入成功" << endl;
				}
				else if (a == "end")
				{

				}
			}
		}

	}
	book* findbook() 
	{
		string name;
		cout << "please enter the book name you want to find out: ";
		cin>>name;

		book* p = books;
		while (p!= NULL) 
		{
			if (p->name == name) 
			{
				cout << "Find it! its code is " << p->code << " and the price is "<<p->price << endl;
				return p;
			}
			p = p->next;
		}
		cout << "Sorry, there is no target book you want." << endl;
		return NULL;
	}
	void showlist() 
	{
		book* p = books;
		while (p != NULL) 
		{
			p->show();
			p = p->next;
		}
	}
	void deletebook() 
	{
		string name;
		cout << "please enter the book name you want to find out: ";
		cin >> name;

		book* p = books;
		while (p->next!= NULL)
		{
			if (p->next->name == name)
			{
				cout << "Find it! its code is " << p->next->code << " and the price is " << p->next->price << endl;
				break;
			}
			p = p->next;
		}
		if (p->next == NULL)
		{
			cout << "No such book" << endl;
			return;
		}
		book* q = p->next;
		p->next = p->next->next;
		delete q;
		return;
	}
	void destorylist() 
	{
	
	}
};
int main()
{
	char a;
	int numberoflist = 0;
	int max = 100;
	string name;
	list* listnow = new list[max];
	while (true) 
	{
		coutfuncation();
		int statuspoint = 0;
		cin >> a;
		if (a == 'q') break;
		else
		{
			switch (a)
			{
			case '1':
				cout << "请输入列表的名字： ";
				cin >> name;
				listnow[numberoflist++].nameoflsit = name;
				cout << "已经创建一个新的列表 " << listnow[numberoflist-1].nameoflsit << endl;
				break;
			case '2':
				cout << "现在要进行在书架上更改数据" << endl;
				listnow[statuspoint].addnewbook();
				break;
			case '3':
				cout << "you chooose you will delete a book" << endl;
				listnow[statuspoint].deletebook();
				break;
			case '4':
				cout << "你选择了查找书籍" << endl;
				listnow[statuspoint].findbook();
				break;
			case '5':
				cout << "你选择了展示书籍，书籍内容如下： " << endl;
				listnow[statuspoint].showlist();
			default:
				break;
			}
		}
	}

}