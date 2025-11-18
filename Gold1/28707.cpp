#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct FHeapData
{
    vector<int> Array;
    int Cost;

    bool operator>(const FHeapData& Another) const
    {
        return Cost > Another.Cost;
    }
};

class FManipulator
{
public:
    FManipulator()
    {
        cin >> l >> r >> Cost;
        --l;
        --r;
    }

    int Manipulate(vector<int>& Array) const
    {
        swap(Array[l], Array[r]);
        return Cost;
    }

private:
    int l;
    int r;
    int Cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int& Value : A)
    {
        cin >> Value;
    }

    int M;
    cin >> M;
    vector<FManipulator> Manipulators(M);

    map<vector<int>, int> Table;
    Table[A] = 0;
    priority_queue<FHeapData, vector<FHeapData>, greater<FHeapData>> MinHeap;
    FHeapData HeapData;
    HeapData.Array = A;
    HeapData.Cost = 0;
    MinHeap.push(HeapData);

    while(!MinHeap.empty())
    {
        HeapData = MinHeap.top();
        MinHeap.pop();

        if(HeapData.Cost > Table[HeapData.Array])
        {
            continue;
        }

        for(const FManipulator& Manipulator : Manipulators)
        {
            FHeapData Candidate = HeapData;
            Candidate.Cost += Manipulator.Manipulate(Candidate.Array);
            if(Table.find(Candidate.Array) == Table.end() || Candidate.Cost < Table[Candidate.Array])
            {
                Table[Candidate.Array] = Candidate.Cost;
                MinHeap.push(Candidate);
            }
        }
    }

    sort(A.begin(), A.end());
    cout << (Table.find(A) == Table.end() ? -1 : Table[A]);

    return 0;
}