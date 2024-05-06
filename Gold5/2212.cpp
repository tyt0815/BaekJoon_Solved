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
    K = min(K, N);
    vector<vector<int>> v;
    v.push_back(vector<int>(N));
    for(auto &SensorPosition : v[0]) cin >> SensorPosition;
    sort(v[0].begin(), v[0].end());

    for(int i = 1; i < K; ++i)
    {
        int MinSplit = INT32_MAX;
        int TargetSensors = -1, TargetIndex = -1;
        for(int j = 0; j < v.size(); ++j)
        {
            vector<int> &Sensors = v[j];
            int Range = Sensors.back() - Sensors[0];
            for(int k = 1; k < Sensors.size(); ++k)
            {
                int Temp = Sensors[k - 1] - Sensors[0] + Sensors.back() - Sensors[k] - Range;
                if(MinSplit > Temp)
                {
                    MinSplit = Temp;
                    TargetSensors = j;
                    TargetIndex = k;
                }
            }
        }
        vector<int> TempVector(v[TargetSensors].size() - TargetIndex);
        TempVector.assign(v[TargetSensors].begin() + TargetIndex, v[TargetSensors].end());
        v.push_back(TempVector);
        v[TargetSensors].resize(TargetIndex);
    }

    int Sum = 0;
    for(const auto &Sensors : v) Sum += (Sensors.back() - Sensors[0]);
    cout << Sum;

    return 0;
}
