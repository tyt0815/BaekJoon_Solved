#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int64_t GetDistance(int A, int B) { return abs(A - B); }
inline int64_t GetLineLength(pair<int, int> Line) { return GetDistance(Line.first, Line.second); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int64_t, int64_t>> Lines(N);
    for(auto &Line : Lines) cin >> Line.first >> Line.second;
    sort(Lines.begin(), Lines.end(), [](pair<int64_t, int64_t> A, pair<int64_t, int64_t> B){ return A.second < B.second; });

    vector<pair<int64_t, int64_t>> IntegratedLines(N, {0, 0});
    int Index = 0;
    for(auto Line : Lines)
    {
        while(Index > 0)
        {
            if(IntegratedLines[Index - 1].second < Line.first) break;
            
            IntegratedLines[Index--] = {0, 0};
            Line.first = min(Line.first, IntegratedLines[Index].first);
        }
        IntegratedLines[Index++] = Line;
    }

    int Sum = 0;
    for(const auto &Line : IntegratedLines)
    {
        Sum += (Line.second - Line.first);
    }
    cout << Sum;

    return 0;
}