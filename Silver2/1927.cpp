#include <iostream>
#include <vector>
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

    void Insert(uint32_t Value)
    {
        if(mNodes.size() <= mIndex)
        {
            Resize(mNodes.size() * 2);
        }
        uint32_t i = mIndex;
        ++mIndex;
        mNodes[i] = Value;
        while(i > 1)
        {
            if(CompareFunc(mNodes[i/2], mNodes[i])){ break; }
            uint32_t Temp = mNodes[i];
            SWAP(mNodes[i], mNodes[i/2], Temp);
            i /= 2;
        }
    }
    uint32_t Remove()
    {
        if(mIndex == 1) return 0;
        uint32_t Removed = mNodes[1], Temp = mNodes[mIndex - 1];
        uint32_t Parent = 1, Child = 2;
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
    void Resize(uint32_t Size)
    {
        mNodes.resize(Size);
    }
    bool CompareFunc(uint32_t a, uint32_t b)
    {
        return a < b;
    }
    void Print()
    {
        cout << '\t';
        for(uint32_t i = 1; i < mIndex; ++i)
        {
            cout << mNodes[i] << ", ";
        }
        cout << endl;
    }

private:
    vector<uint32_t> mNodes;
    uint32_t mIndex;
    
public:
    inline uint32_t GetSize() const { return mIndex - 1; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;
    Heap MinHeap;

    cin >> n;

    for(uint32_t i = 0; i < n;  ++i)
    {
        uint32_t Input;
        cin >> Input;
        if(Input == 0)
        {
            cout << MinHeap.Remove() << "\n";
        }
        else
        {
            MinHeap.Insert(Input);
        }
        // MinHeap.Print();
    }

    return 0;
}