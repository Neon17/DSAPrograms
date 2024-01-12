#include <iostream>
using namespace std;

char *postfixString(char a[],int size);

class Stack
{
    int tos;
    char *stk;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        stk = new char[size];
        tos = -1;
    }
    bool push(char data)
    {
        if (isFull())
        {
            cout << "Stack is full.." << endl;
            return false;
        }
        if (!preCheck(data))
        {
            cout << "Lower Precedance to be kept at top" << endl;
            return false;
        }
        tos++;
        stk[tos] = data;
        return true;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.." << endl;
            return '\0';
        }
        char data = stk[tos];
        stk[tos] = '\0';
        tos--;
        return data;
    }
    bool isFull()
    {
        if (tos >= (size - 1))
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (tos <= -1)
            return true;
        return false;
    }
    void show()
    {
        if (tos == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Elements present in stack" << endl;
        for (int i = tos; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }
    bool preCheck(char data)
    {
        // it is precedance Check on operator
        // check until ( reached or bottom of stack reached
        if ((data == '(')||(isEmpty()))
            return true;
        char a[] = {'$', '/', '*', '+', '-'};
        int sa = 5;
        int i, j, id;
        id = -1;
        for (j = 0; j < sa; j++)
        {
            if (data == a[j])
            {
                id = j;
                break;
            }
        }
        for (i = tos; i >= 0; i++)
        {
            if (stk[i] == '(')
                return true;
            int io; // io means index of others
            for (j = 0; j < sa; j++)
            {
                if (stk[i] == a[j])
                {
                    io = i;
                    break;
                }
            }
            if (id >= io)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    char *a;
    a = postfixString((char*)"a+b-c*d/e",9);
    cout << "Postfix String = " << a<<endl;
    return 0;
}

char *postfixString(char a[],int size)
{
    cout << size << endl;
    Stack s(size);

    char *ps;
    ps = new char(size+1);
    //size+1 because its better to keep last character empty
    for (int i = 0; i < (size); i++)
    {
        ps[i] = '\0';
    }
    int ips = 0;
    // ips means index reached at ps after filling

    int i;
    for (i = 0; i < size; i++)
    {

        if (a[i] == ')')
        {
            int j;
            char t;
            for (j = 0; j < size; j++)
            {
                while (!((t = s.pop()) == '('))
                {
                    ps[ips] = a[i];
                    ips++;
                }
            }
        }

        if ((a[i] == '(') || (a[i] == '/') || (a[i] == '*') || (a[i] == '+') || (a[i] == '-') || (a[i] == '$'))
        {
            //$ means exponent
            while (!(s.push(a[i])))
            {
                ps[ips] = s.pop();
                ips++;
            }
        }
        else
        {
            ps[ips] = a[i];
            ips++;
        }
    }
    char t;
    s.show();
    while (!s.isEmpty()){
        t = s.pop();
        cout<<t<<endl;
        ps[ips] = t;
        ips++;
    }
    ps[ips]='\0';
    ips++;
    return ps;
}
