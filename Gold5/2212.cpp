// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, K;
//     cin >> N >> K;
//     vector<int> SensorPositions(N);
//     for(auto &SensorPosition : SensorPositions) cin >> SensorPosition;
//     sort(SensorPositions.begin(), SensorPositions.end());

//     vector<int> Ranges;
//     for(int i = 1; i < SensorPositions.size(); ++i)
//     {
//         if(SensorPositions[i] == SensorPositions[i - 1]) continue;
//         Ranges.push_back(SensorPositions[i] - SensorPositions[i - 1]);
//     }
//     sort(Ranges.begin(), Ranges.end());
//     int Sum = 0;
//     for(int i = 0; i < static_cast<int>(Ranges.size()) - K + 1; ++i) Sum += Ranges[i];
//     cout << Sum;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> SensorPositions(N);
    for(auto& Sensor : SensorPositions) cin >> Sensor;
    sort(SensorPositions.begin(), SensorPositions.end());
    vector<int> Dists;
    for(int i = 0; i < N - 1; ++i)
    {
        if(SensorPositions[i] == SensorPositions[i + 1]) continue;
        Dists.push_back(SensorPositions[i + 1] - SensorPositions[i]);
    }
    sort(Dists.begin(), Dists.end());
    int Sum = 0, TargetIndex = min(N, static_cast<int>(Dists.size()) - K + 1);
    for(int i = 0; i < TargetIndex; ++i) Sum += Dists[i];
    cout << Sum;

    return 0;
}