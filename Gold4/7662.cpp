// #include <iostream>
// #include <queue>
// #include <unordered_map>

// using namespace std;

// class DoublePriorityQueue
// {
// public:
//     DoublePriorityQueue();
//     ~DoublePriorityQueue();

//     void Insert(int64_t Value);
//     void DeleteMax();
//     void DeleteMin();
//     bool Empty();
//     int64_t GetMax();
//     int64_t GetMin();

// private:
//     priority_queue<int64_t, vector<int64_t>, greater<int64_t>>* mMinHeap;
//     priority_queue<int64_t, vector<int64_t>, less<int64_t>>* mMaxHeap;
//     unordered_map<int64_t, int64_t>* mUMap;
//     uint64_t mSize;
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int64_t t;
//     cin >> t;
//     for(int64_t i = 0; i < t; ++i)
//     {
//         DoublePriorityQueue dpq;
//         int64_t k;
//         cin >> k;
//         for(int64_t j = 0; j <k; ++j)
//         {
//             char Cmd;
//             int64_t Value;
//             cin >> Cmd >> Value;
//             if(Cmd == 'I')
//             {
//                 dpq.Insert(Value);
//             }
//             else
//             {
//                 if(Value == 1)
//                 {
//                     dpq.DeleteMax();
//                 }
//                 else
//                 {
//                     dpq.DeleteMin();
//                 }
//             }
//         }
//         if(dpq.Empty())
//         {
//             cout << "EMPTY\n";
//         }
//         else
//         {
//             cout << dpq.GetMax() << ' ' <<dpq.GetMin() << '\n';
//         }
//     }

//     return 0;
// }

// DoublePriorityQueue::DoublePriorityQueue():
//     mMaxHeap(new priority_queue<int64_t, vector<int64_t>, less<int64_t>>()),
//     mMinHeap(new priority_queue<int64_t, vector<int64_t>, greater<int64_t>>()),
//     mUMap(new unordered_map<int64_t, int64_t>()),
//     mSize(0)
// {
// }

// DoublePriorityQueue::~DoublePriorityQueue()
// {
//     delete mMaxHeap;
//     delete mMinHeap;
//     delete mUMap;
// }

// void DoublePriorityQueue::Insert(int64_t Value)
// {
//     if(mUMap->find(Value) == mUMap->end())
//     {
//         (*mUMap)[Value] = 0;
//     }
//     ++mSize;
//     (*mUMap)[Value] += 1;
//     mMaxHeap->push(Value);
//     mMinHeap->push(Value);
// }

// void DoublePriorityQueue::DeleteMax()
// {
//      if(Empty())
//      {
//         return;
//      }

//     while((*mUMap)[mMaxHeap->top()] == 0)
//     {
//         mMaxHeap->pop();
//     }

//     --mSize;
//     (*mUMap)[mMaxHeap->top()] -= 1;
//     mMaxHeap->pop();
// }

// void DoublePriorityQueue::DeleteMin()
// {
//     if(Empty())
//     {
//         return;
//     }
//     while((*mUMap)[mMinHeap->top()] == 0)
//     {
//         mMinHeap->pop();
//     }
//     --mSize;
//     (*mUMap)[mMinHeap->top()] -= 1;
//     mMinHeap->pop();
// }

// bool DoublePriorityQueue::Empty()
// {
//     return mSize == 0;
// }

// int64_t DoublePriorityQueue::GetMax()
// {
//     while((*mUMap)[mMaxHeap->top()] == 0)
//     {
//         mMaxHeap->pop();
//     }
//     return mMaxHeap->top();
// }

// int64_t DoublePriorityQueue::GetMin()
// {
//     while((*mUMap)[mMinHeap->top()] == 0)
//     {
//         mMinHeap->pop();
//     }
//     return mMinHeap->top();
// }

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class FDualPrioriryQueue
{
public:
    void ProcessCommand(char Command, int64_t Arg);
    void Insert(int64_t Value);
    void DeleteMax();
    void DeleteMin();
    bool IsEmpty();
    inline int64_t GetMax();
    inline int64_t GetMin();

private:
    priority_queue<int64_t> MaxHeap;
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> MinHeap;
    unordered_map<int64_t, int64_t> Counter;

    inline void CleanMaxHeap();
    inline void CleanMinHeap();
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int K;
        cin >> K;
        FDualPrioriryQueue DPQ;
        for(int j = 0; j < K; ++j)
        {
            char Cmd;
            int64_t Arg;
            cin >> Cmd >> Arg;
            DPQ.ProcessCommand(Cmd, Arg);
        }
        if(DPQ.IsEmpty()) cout << "EMPTY";
        else cout << DPQ.GetMax() << ' ' << DPQ.GetMin();
        cout << '\n';
    }

    return 0;
}


void FDualPrioriryQueue::ProcessCommand(char Command, int64_t Arg)
{
    if(Command == 'I') Insert(Arg);
    else if(Arg == 1) DeleteMax();
    else DeleteMin(); 
}

void FDualPrioriryQueue::Insert(int64_t Value)
{
    MaxHeap.push(Value);
    MinHeap.push(Value);
    if(Counter.find(Value) == Counter.end()) Counter[Value] = 0;
    ++Counter[Value];
}

void FDualPrioriryQueue::DeleteMax()
{
    CleanMaxHeap();
    if(MaxHeap.empty()) return;
    --Counter[MaxHeap.top()];
    MaxHeap.pop();
}

void FDualPrioriryQueue::DeleteMin()
{
    CleanMinHeap();
    if(MinHeap.empty()) return;
    --Counter[MinHeap.top()];
    MinHeap.pop();
}

bool FDualPrioriryQueue::IsEmpty()
{
    CleanMinHeap();
    return MinHeap.empty();
}

int64_t FDualPrioriryQueue::GetMax()
{
    CleanMaxHeap();
    return MaxHeap.top();
}

int64_t FDualPrioriryQueue::GetMin()
{
    CleanMinHeap();
    return MinHeap.top();
}

void FDualPrioriryQueue::CleanMaxHeap()
{
    while(!MaxHeap.empty() && Counter[MaxHeap.top()] == 0) MaxHeap.pop();
}

void FDualPrioriryQueue::CleanMinHeap()
{
    while(!MinHeap.empty() && Counter[MinHeap.top()] == 0) MinHeap.pop();
}
