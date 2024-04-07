#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> Lectures(N, {0, 0});
    for(int i = 0; i < N; ++i) cin >> Lectures[i].first >> Lectures[i].second;
    sort(Lectures.begin(), Lectures.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; });
    
    priority_queue<int, vector<int>, greater<int>> EndTime;
    EndTime.push(Lectures[0].second);
    for(int i = 1; i < N; ++i)
    {
        if(EndTime.top() <= Lectures[i].first) EndTime.pop();
        EndTime.push(Lectures[i].second);
    }

    cout << EndTime.size();

    return 0;
}