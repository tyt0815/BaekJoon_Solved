#include <iostream>
#include <queue>

using namespace std;

struct PrintData
{
    int Importance;
    int InitIndex;
};

void FindMaxImportance(int* NumDocDevideByImportance, int &CurrMaxImportance);

int main()
{
    int NumCase;
    int NumDocDevideByImportance[10];
    cin >> NumCase;


    // 브루트포스
    for(int i = 0 ; i < NumCase; ++i)
    {
        for(int i = 0; i < 10; ++i) { NumDocDevideByImportance[i] = 0; }
        int NumDoc, Target;
        queue<PrintData> q;
        cin >> NumDoc >> Target;
        for(int j = 0; j < NumDoc; ++j)
        {
            PrintData Input;
            cin >> Input.Importance;
            Input.InitIndex = j;
            q.push(Input);
            NumDocDevideByImportance[Input.Importance] += 1;
        }

        int CurrMaxImportance = 9;
        int Cnt = 0;
        while(true)
        {
            FindMaxImportance(NumDocDevideByImportance, CurrMaxImportance);
            while(q.front().Importance != CurrMaxImportance)
            {
                PrintData Temp = q.front();
                q.pop();
                q.push(Temp);
            }
            ++Cnt;
            if(q.front().InitIndex == Target) { break; }
            --NumDocDevideByImportance[q.front().Importance];
            q.pop();
        }
        cout << Cnt << "\n";
    }

    return 0;
}

void FindMaxImportance(int* NumDocDevideByImportance, int &CurrMaxImportance)
{
    while(NumDocDevideByImportance[CurrMaxImportance] <= 0)
    {
        --CurrMaxImportance;
    }
}