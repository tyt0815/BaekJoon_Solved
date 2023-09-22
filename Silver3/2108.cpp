#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int NumInput;
    int *Inputs;
    cin >> NumInput;
    Inputs = new int[NumInput];
    
    int Avg = 0, Mid = 0, MostFreq = 0, Range = 0;
    map<int, int> Frequency;
    bool IsSecond = false;

    for(int i = 0; i < NumInput; ++i)
    {
        cin >> Inputs[i];
        Avg += Inputs[i];
        if(Frequency.count(Inputs[i]) == 0)
        {
            Frequency[Inputs[i]] = 0;
        }
        ++Frequency[Inputs[i]];
    }
    Avg = floor(Avg/(float)NumInput + 0.5);
    sort(Inputs, Inputs + NumInput);
    Mid = Inputs[NumInput/2];

    int NumMostFreq = 0;
    int Temp = 0, NumTempFreq = 0;
    int i = 0;
    while(true)
    {
        if(i >= NumInput) { break; }
        Temp = Inputs[i];
        NumTempFreq = Frequency[Temp];
        if(NumMostFreq < NumTempFreq)
        {
            MostFreq = Temp;
            NumMostFreq = NumTempFreq;
            IsSecond = false;
        }
        else if(NumMostFreq == NumTempFreq && !IsSecond)
        {
            IsSecond = true;
            NumMostFreq = NumTempFreq;
            MostFreq = Temp;
        }
        i += NumTempFreq;
    }

    Range = Inputs[NumInput-1] - Inputs[0];

    cout << Avg << "\n" 
        << Mid << "\n"
        << MostFreq << "\n"
        << Range;

    delete[] Inputs;
    return 0;
}