#include <iostream>
#include <algorithm>

using namespace std;

int InorderIndices[100'001];
int Inorder[100'000];
int Postorder[100'000];

void PrintToPreorder(int InStart, int InEnd, int PostStart, int PostEnd)
{
    int PostIndex = PostEnd - 1;

    cout << Postorder[PostIndex] << ' ';
    
    int InIndex = InorderIndices[Postorder[PostIndex]];

    if(InIndex >= InEnd)
    {
        return;
    }

    int LeftNum = InIndex - InStart;
    int RightNum = InEnd - (InIndex + 1);
    // Left
    if(LeftNum > 0)
    {
        PrintToPreorder(InStart, InIndex, PostStart, PostEnd - 1 - RightNum);
    }

    // Right
    if(RightNum > 0)
    {
        PrintToPreorder(InIndex + 1, InEnd, PostEnd - RightNum, PostIndex);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> Inorder[i];
        InorderIndices[Inorder[i]] = i;
    }
    for(int i = 0; i < N; ++i)
    {
        cin >> Postorder[i];
    }

    PrintToPreorder(0, N, 0, N);

    return 0;
}