#include<iostream>
#include<string>
using namespace std;
struct book
{
    string name;
    int code;
    float price;
    void print()
    {
        cout << name << " " << code << " " << price << endl;
    }
};

class list
{
private:
    book listbook;
    list* next;
public:
    list()
    {
        next = NULL;
    }

    ~list()
    {
        cout << "I am done" << endl;
    }
    void insert(string name, int code, float price)
    {
        list* newbook = new list;
        newbook->listbook.name = name;
        newbook->listbook.code = code;
        newbook->listbook.price = price;
        newbook->next = next;
        next = newbook;
    }
    void showw()
    {
        list* p = new list;
        p = next;
        while (p != NULL)
        {
            p->listbook.print();
            p = p->next;
        }
    }
    void findd()
    {
        cout << "please enter the book you want to search: ";
        string name;
        cin >> name;
        list* p = new list;
        p = next;
        while (true)
        {

            if (p == NULL)
            {
                cout << "There is no book you want" << endl;
                return;
            }
            else if (p->listbook.name != name) p = p->next;
            else { p->listbook.print(); return; }
        }

    }
    void findd(string name)
    {
        list* p = new list;
        p = next;
        while (true)
        {

            if (p == NULL)
            {
                cout << "There is no book you want" << endl;
                return;
            }
            else if (p->listbook.name != name) p = p->next;
            else { p->listbook.print(); return; }
        }
        delete p;
    }
    void deletee()
    {
        cout << "Please enter the book you want to delect: ";
        string book;
        cin >> book;
        list* p = new list;
        delete p;
    }
};

int main()
{
    list book;
    book.insert("HOW TO LOVE", 23333, 15.25);
    book.insert("HOW TO LOVE", 23333, 15.25);
    book.deletee();
    book.showw();

}