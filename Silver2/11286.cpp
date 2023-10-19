#include <iostream>
#include <vector>
#include <cmath>
#define SWAP(x,y,temp) temp = x; x = y; y = temp;

using namespace std;

class Heap
{
public:
    Heap():
        mIndex(1)
    {
        mNodes.resize(10);
    }

    void Insert(long long Value)
    {
        if(mNodes.size() <= mIndex)
        {
            Resize(mNodes.size() * 2);
        }
        long long i = mIndex;
        ++mIndex;
        mNodes[i] = Value;
        while(i > 1)
        {
            if(CompareFunc(mNodes[i/2], mNodes[i])){ break; }
            long long Temp = mNodes[i];
            SWAP(mNodes[i], mNodes[i/2], Temp);
            i /= 2;
        }
    }
    long long Remove()
    {
        if(mIndex == 1) return 0;
        long long Removed = mNodes[1], Temp = mNodes[mIndex - 1];
        long long Parent = 1, Child = 2;
        --mIndex;
        while (Child < mIndex)
        {
            if(Child + 1 < mIndex && CompareFunc(mNodes[Child+1], mNodes[Child])) 
            { 
                ++Child;
            }
            if(CompareFunc(Temp, mNodes[Child]))
            {
                break;
            }
            mNodes[Parent] = mNodes[Child];
            Parent = Child;
            Child *= 2;
        }
        mNodes[Parent] = Temp;
        
        return Removed;
    }
    void Resize(long long Size)
    {
        mNodes.resize(Size);
    }
    bool CompareFunc(long long a, long long b)
    {
        uint32_t AbsA, AbsB;
        AbsA = abs(a); AbsB = abs(b);
        if(AbsA == AbsB)
            return a < b;
        return AbsA < AbsB;
    }
    void Print()
    {
        cout << '\t';
        for(long long i = 1; i < mIndex; ++i)
        {
            cout << mNodes[i] << ", ";
        }
        cout << endl;
    }

private:
    vector<long long> mNodes;
    long long mIndex;
    
public:
    inline long long GetSize() const { return mIndex - 1; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    Heap AbsMinHeap;

    cin >> n;

    for(long long i = 0; i < n;  ++i)
    {
        long long Input;
        cin >> Input;
        if(Input == 0)
        {
            // cout << "\t";
            cout << AbsMinHeap.Remove() << "\n";
        }
        else
        {
            AbsMinHeap.Insert(Input);
        }
        // AbsMinHeap.Print();
    }

    return 0;
}