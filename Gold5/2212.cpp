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
    for(auto &SensorPosition : SensorPositions) cin >> SensorPosition;
    sort(SensorPositions.begin(), SensorPositions.end());

    vector<int> Ranges;
    for(int i = 1; i < SensorPositions.size(); ++i)
    {
        if(SensorPositions[i] == SensorPositions[i - 1]) continue;
        Ranges.push_back(SensorPositions[i] - SensorPositions[i - 1]);
    }
    sort(Ranges.begin(), Ranges.end());
    int Sum = 0;
    for(int i = 0; i < static_cast<int>(Ranges.size()) - K + 1; ++i) Sum += Ranges[i];
    cout << Sum;

    return 0;
}