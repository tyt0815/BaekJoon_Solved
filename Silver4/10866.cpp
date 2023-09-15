#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class MyQueue
{
public:
    MyQueue();
    ~MyQueue();
    void PushFront(int Value );
    void PushBack(int Value );
    int PopFront();
    int PopBack();
    int Size();
    bool Empty();
    bool IsFull();
    int Front();
    int Back();
    void Resize(int Value);

private:
    int* mValues;
    int mFrontIndex;
    int mBackIndex;
    int mMax;
};

int main()
{
    int n;
    string Command;
    MyQueue Q;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> Command;
        if(!Command.compare("push_front"))
        {
            int Value;
            cin >> Value;
            Q.PushFront(Value);
        }
        else if(!Command.compare("push_back"))
        {
            int Value;
            cin >> Value;
            Q.PushBack(Value);
        }
        else if(!Command.compare("pop_front"))
        {
            cout << Q.PopFront() << endl;
        }
        else if(!Command.compare("pop_back"))
        {
            cout << Q.PopBack() << endl;
        }
        else if(!Command.compare("size"))
        {
            cout << Q.Size() << endl;
        }
        else if(!Command.compare("empty"))
        {
            cout << Q.Empty() << endl;
        }
        else if(!Command.compare("front"))
        {
            cout << Q.Front() << endl;
        }
        else if(!Command.compare("back"))
        {
            cout << Q.Back() << endl;
        }
    }
    return 0;
}

MyQueue::MyQueue():
    mValues(new int[4]),
    mFrontIndex(0),
    mBackIndex(0),
    mMax(4)
{

}

MyQueue::~MyQueue()
{
    delete[] mValues;
}

void MyQueue::PushFront(int Value)
{
    if(IsFull())
    {
        Resize(mMax*2);
    }
    mFrontIndex = mFrontIndex == 0 ? mMax - 1 : mFrontIndex - 1;
    mValues[mFrontIndex] = Value;
}

void MyQueue::PushBack(int Value)
{
    if(IsFull())
    {
        Resize(mMax*2);
    }
    mValues[mBackIndex] = Value;
    mBackIndex = (mBackIndex + 1)%mMax;
}

int MyQueue::PopFront()
{
    if(Empty()) { return -1; }
    int ReturnValue = mValues[mFrontIndex];
    mFrontIndex  = (mFrontIndex + 1) % mMax;
    return ReturnValue; 
}

int MyQueue::PopBack()
{
    if(Empty()) { return -1; }
    mBackIndex = mBackIndex == 0 ? mMax - 1 : mBackIndex - 1;
    return mValues[mBackIndex]; 
}

int MyQueue::Size()
{
    if(mFrontIndex <= mBackIndex)
    {
        return mBackIndex - mFrontIndex;
    }
    else
    {
        return (mMax - mFrontIndex) + mBackIndex;
    }
}

bool MyQueue::Empty()
{
    if(mFrontIndex == mBackIndex)
    {
        return true;   
    }
    return false;
}

bool MyQueue::IsFull()
{
    return mFrontIndex == (mBackIndex + 1) % mMax;
}

int MyQueue::Front()
{
    return Empty()?-1:mValues[mFrontIndex];
}

int MyQueue::Back()
{
    return Empty()?-1:(mBackIndex == 0 ? mValues[mMax-1] : mValues[mBackIndex-1]);
}

void MyQueue::Resize(int Value)
{
    int* Temp = mValues;
    mValues = new int[Value];
    if(mFrontIndex < mBackIndex)
    {
        memcpy(mValues, Temp, sizeof(int) * mMax);
        mMax = Value;
    }
    else
    {
        memcpy(mValues, &Temp[mFrontIndex], sizeof(int) * (mMax - mFrontIndex));
        memcpy(&mValues[mMax - mFrontIndex], Temp, sizeof(int) * mBackIndex);
        mFrontIndex = 0;
        mBackIndex = mMax - 1;
        mMax = Value;
    }
    delete[] Temp;
}