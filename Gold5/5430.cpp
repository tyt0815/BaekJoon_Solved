#include <iostream>
#include <vector>
#include <string.h>
#include <memory>

#define MAX_NUM 100000
#define SWAP(x, y, temp) temp = x; x = y; y = temp;

using namespace std;

class AC
{
public:
    AC(string Ary, uint32_t ArySize):
        mIsReverse(1),
        mStart(0),
        mEnd(ArySize-1),
        mArySize(ArySize)
    {
        uint32_t Start = 1, End = 1;
        char Number[MAX_NUM];
        while(true)
        {
            if(!(Ary[End] >= '0' && Ary[End] <= '9'))
            {
                Number[End - Start] = '\0';
                mAry.push_back(atoi(Number));
                Start = End + 1;
                End = Start;
            }
            if(Ary[End - 1] == ']')
            {
                break;
            }

            Number[End - Start] = Ary[End];
            ++End;
        }
    }

    void Reverse()
    {
        mIsReverse *= -1;
        uint32_t Temp;
        SWAP(mStart, mEnd, Temp);
    }
    bool Delete()
    {
        if(mArySize == 0) return false;
        mStart += mIsReverse;
        --mArySize;
        return true;
    }
    void Print()
    {
        if(mArySize == 0)
        {
            cout << "[]" << '\n';
            return;
        }
        cout << '[' << mAry[mStart];
        for(uint32_t i = mStart + mIsReverse, j = 1; j < mArySize; i += mIsReverse, ++j)
        {
            cout << ',' << mAry[i];
        }
        cout << ']' << '\n';
    }

private:
    vector<uint32_t> mAry;
    short int mIsReverse;
    uint32_t mStart, mEnd, mArySize;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    uint32_t t;

    cin >> t;

    for(uint32_t i = 0; i < t; ++i)
    {
        uint32_t ArySize;
        string Cmd, Ary;
        cin >> Cmd >> ArySize >> Ary;
        AC Lang(Ary, ArySize);
        for(uint32_t j = 0; j < Cmd.length(); ++j)
        {
            if(Cmd[j] == 'R') Lang.Reverse();
            else
            {
                if(!Lang.Delete())
                {
                    cout << "error" << '\n';
                    goto WhenError;  
                } 
            }
        }

        Lang.Print();
        WhenError:;
    }

    return 0;
}

