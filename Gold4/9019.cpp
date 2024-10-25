// #include <iostream>
// #include <string>
// #include <queue>

// using namespace std;

// struct QData
// {
//     int n;
//     string Cmd;
// };

// bool Visited[10000];

// string AtoB(int a, int b);
// QData D(QData d);
// QData S(QData d);
// QData L(QData d);
// QData R(QData d);
// bool Check(QData d, int b, queue<QData>& q);

// int main()
// {
//     int t;
//     cin >> t;
//     for(int i = 0; i < t; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         cout << AtoB(a, b) << '\n';
//     }

//     return 0;
// }

// string AtoB(int a, int b)
// {
//     queue<QData> q;
//     QData Temp;
//     Temp.n = a;
//     Temp.Cmd = "";
//     q.push(Temp);
//     for(int i = 0; i < 10000; ++i)
//     {
//         Visited[i] = false;
//     }
//     Visited[a] = true;

//     while(!q.empty())
//     {
//         Temp = q.front();
//         q.pop();
//         QData Out;
//         Out = D(Temp);
//         if(Check(Out, b, q))
//         {
//             return Out.Cmd;
//         }
//         Out = S(Temp);
//         if(Check(Out, b, q))
//         {
//             return Out.Cmd;
//         }
//         Out = L(Temp);
//         if(Check(Out, b, q))
//         {
//             return Out.Cmd;
//         }
//         Out = R(Temp);
//         if(Check(Out, b, q))
//         {
//             return Out.Cmd;
//         }
//     }

//     return "!";
// }

// QData D(QData d)
// {
//     d.n = (d.n * 2) % 10000;
//     d.Cmd += 'D';
//     return d;
// }

// QData S(QData d)
// {
//     d.n -= 1;
//     d.n = d.n < 0 ? 9999 : d.n;
//     d.Cmd += 'S';
//     return d;
// }

// QData L(QData d)
// {
//     d.n = (d.n % 1000) * 10 + (d.n / 1000);
//     d.Cmd += 'L';
//     return d;
// }

// QData R(QData d)
// {
//     d.n = (d.n / 10) + (d.n % 10) * 1000;
//     d.Cmd += 'R';
//     return d;
// }

// bool Check(QData d, int b, queue<QData> &q)
// {
//     if(d.n == b)
//     {
//         return true;
//     }
//     if(!Visited[d.n])
//     {
//         q.push(d);
//         Visited[d.n] = true;
//     }
//     return false;
// }

#include <iostream>
#include <queue>

using namespace std;

class FDSLR
{
public:
    FDSLR(int InA, int InB): A(InA), B(InB){}
    string FindCommands();

private:
    int A;
    int B;
    vector<bool> bVisited;
    queue<pair<int, string>> Q;

    int D(int Number);
    int S(int Number);
    int L(int Number);
    int R(int Number);
    bool ProcessingQ(int Number, string Cmds);
    string AppendCommand(string Cmds, string Cmd);
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int A, B;
        cin >> A >> B;
        FDSLR DSLR(A, B);
        cout << DSLR.FindCommands() << '\n';
    }

    return 0;
}

string FDSLR::FindCommands()
{
    bVisited = vector<bool>(10000, false);
    Q = queue<pair<int, string>>();
    bVisited[A] = true;
    Q.push({A, ""});
    while(true)
    {
        int Number = Q.front().first;
        string Cmds = Q.front().second;
        Q.pop();
        if (ProcessingQ(D(Number), AppendCommand(Cmds, "D"))) break;
        if (ProcessingQ(S(Number), AppendCommand(Cmds, "S"))) break;
        if (ProcessingQ(L(Number), AppendCommand(Cmds, "L"))) break;
        if (ProcessingQ(R(Number), AppendCommand(Cmds, "R"))) break;
    }
    return Q.back().second;
}

int FDSLR::D(int Number)
{
    return Number * 2 % 10000;
}

int FDSLR::S(int Number)
{
    return (Number + 9999) % 10000;
}

int FDSLR::L(int Number)
{
    int Result = (Number % 1000) * 10;
    Result += Number / 1000;
    return Result;
}

int FDSLR::R(int Number)
{
    int Result = Number / 10;
    Result += (Number % 10) * 1000;
    return Result;
}

bool FDSLR::ProcessingQ(int Number, string Cmds)
{
    if(bVisited[Number]) return false;
    bVisited[Number] = true;
    Q.push({Number, Cmds});
    if(Number == B) return true;
    else return false;
}

string FDSLR::AppendCommand(string Cmds, string Cmd)
{
    return Cmds.append(Cmd);
}
