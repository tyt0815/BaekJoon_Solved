#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct QData
{
    int n;
    string Cmd;
};

bool Visited[10000];

string AtoB(int a, int b);
QData D(QData d);
QData S(QData d);
QData L(QData d);
QData R(QData d);
bool Check(QData d, int b, queue<QData>& q);

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << AtoB(a, b) << '\n';
    }

    return 0;
}

string AtoB(int a, int b)
{
    queue<QData> q;
    QData Temp;
    Temp.n = a;
    Temp.Cmd = "";
    q.push(Temp);
    for(int i = 0; i < 10000; ++i)
    {
        Visited[i] = false;
    }
    Visited[a] = true;

    while(!q.empty())
    {
        Temp = q.front();
        q.pop();
        QData Out;
        Out = D(Temp);
        if(Check(Out, b, q))
        {
            return Out.Cmd;
        }
        Out = S(Temp);
        if(Check(Out, b, q))
        {
            return Out.Cmd;
        }
        Out = L(Temp);
        if(Check(Out, b, q))
        {
            return Out.Cmd;
        }
        Out = R(Temp);
        if(Check(Out, b, q))
        {
            return Out.Cmd;
        }
    }

    return "!";
}

QData D(QData d)
{
    d.n = (d.n * 2) % 10000;
    d.Cmd += 'D';
    return d;
}

QData S(QData d)
{
    d.n -= 1;
    d.n = d.n < 0 ? 9999 : d.n;
    d.Cmd += 'S';
    return d;
}

QData L(QData d)
{
    d.n = (d.n % 1000) * 10 + (d.n / 1000);
    d.Cmd += 'L';
    return d;
}

QData R(QData d)
{
    d.n = (d.n / 10) + (d.n % 10) * 1000;
    d.Cmd += 'R';
    return d;
}

bool Check(QData d, int b, queue<QData> &q)
{
    if(d.n == b)
    {
        return true;
    }
    if(!Visited[d.n])
    {
        q.push(d);
        Visited[d.n] = true;
    }
    return false;
}
