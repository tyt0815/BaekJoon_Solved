#include <iostream>
#include <vector>
#include <cmath>
#define COGWHEELNUM 4
#define COGNUM 8

using namespace std;

class FCogWheels
{
public:
    FCogWheels(size_t NumCog);

public:
    inline int GetScore() { return CogInfo[Cog12] == '0' ? 0 : 1; }
    inline int GetLeftCogIndex() { return (Cog12 + CogInfo.size() - (CogInfo.size() / 4)) % CogInfo.size(); }
    inline int GetRightCogIndex() { return (Cog12 + (CogInfo.size() / 4)) % CogInfo.size(); };
    inline uint8_t GetLeftCogInfo() { return CogInfo[GetLeftCogIndex()]; }
    inline uint8_t GetRightCogInfo() { return CogInfo[GetRightCogIndex()]; }
    void SetCogInfoBySTDIN();
    inline void SetLeftCogWheel(FCogWheels* CogWheel) { LeftCogWheel = CogWheel; }
    inline void SetRightCogWheel(FCogWheels* CogWheel) { RightCogWheel = CogWheel; }
    void RotateCogWheel(int Direction, FCogWheels* Instigator);

private:
    vector<uint8_t> CogInfo;
    uint8_t Cog12;
    FCogWheels* LeftCogWheel;
    FCogWheels* RightCogWheel;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<FCogWheels> CogWheels(COGWHEELNUM, FCogWheels(COGNUM));
    for(int i = 0; i < COGWHEELNUM; ++i)
    {
        CogWheels[i].SetCogInfoBySTDIN();
        if(i > 0) CogWheels[i].SetLeftCogWheel(&CogWheels[i - 1]);
        if(i < COGWHEELNUM - 1) CogWheels[i].SetRightCogWheel(&CogWheels[i + 1]);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i)
    {
        int CogWheelIndex, RotationDirection;
        cin >> CogWheelIndex >> RotationDirection;
        CogWheels[CogWheelIndex - 1].RotateCogWheel(RotationDirection, nullptr);
    }

    int Score = 0;
    for(int i = 0; i < COGWHEELNUM; ++i) Score += (CogWheels[i].GetScore() * pow<int>(2, i));
    cout << Score;

    return 0;
}

FCogWheels::FCogWheels(size_t NumCog):
    Cog12(0),
    LeftCogWheel(nullptr),
    RightCogWheel(nullptr)
{
    CogInfo.resize(NumCog);
}

void FCogWheels::SetCogInfoBySTDIN()
{
    Cog12 = 0;
    for(int i = 0; i < CogInfo.size(); ++i) cin >> CogInfo[i];
}

void FCogWheels::RotateCogWheel(int Direction, FCogWheels* Instigator)
{
    if(LeftCogWheel && LeftCogWheel != Instigator && GetLeftCogInfo() != LeftCogWheel->GetRightCogInfo()) LeftCogWheel->RotateCogWheel(Direction == 1 ? -1 : 1, this);
    if(RightCogWheel && RightCogWheel != Instigator && GetRightCogInfo() != RightCogWheel->GetLeftCogInfo()) RightCogWheel->RotateCogWheel(Direction == 1 ? -1 : 1, this);
    // CCW
    if(Direction == -1) Cog12 = (Cog12 + 1) % CogInfo.size();
    // CW
    else if(Direction == 1) Cog12 = (Cog12 + CogInfo.size() - 1) % CogInfo.size();
}