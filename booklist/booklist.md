这个md文件是用来展示自己的差错能力和自我检查，后面会把md文件分为知识篇和过程篇，为了方便大家明白为什么要这么做。

第一部：

元素部分

```C++
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
```

元素结构部分

(这个不方便大家观看，之后我会把代码直接分开)

```c++

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
```

然后我的主函数是这样的

```C++
int main()
{
    list book;
    book.insert("HOW TO LOVE", 23333, 15.25);
    book.insert("HOW TO LOVE", 23333, 15.25);
    book.deletee();
    book.showw();
}
```

这个代码会有一个问题，他终端打印是这样的

Please enter the book you want to delect: **HOW TO LOVE**（输入）
I am done
HOW TO LOVE 23333 15.25
HOW TO LOVE 23333 15.25
I am done

因为delect这个函数并没有写完，但是这个代码有一个致命的缺点就是，每删除一本书的时候，他都会输入“I am done”这是一个严重的问题。

我思考的原因是：

1.我的book结构体和list类功能并没有达到符合预期。

解决方案：

我先去书本上去找他们为什么没有这个问题，他们是怎么写的代码。

原因有两个，但我感觉主要原因是1个

我的book结构体中没有指针域！然后就去修改我的代码