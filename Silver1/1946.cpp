#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SRecruitInfo
{
    int DocumentScore;
    int InterviewScore;
};

int GetMaxRecruitNum(vector<SRecruitInfo>& Scores);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<SRecruitInfo> Scores(n, SRecruitInfo());
        for(int j = 0; j < n; ++j)
        {
            cin >> Scores[j].DocumentScore >> Scores[j].InterviewScore;
        }
        cout << GetMaxRecruitNum(Scores) << '\n';
    }

    return 0;
}

int GetMaxRecruitNum(vector<SRecruitInfo> &Scores)
{
    int n = Scores.size(), Result = 1;
    vector<pair<int, int>> DocumentScores(n, {0, 0});

    sort(Scores.begin(), Scores.end(), [](SRecruitInfo a, SRecruitInfo b) { return a.DocumentScore < b.DocumentScore; });
    int MinInterviewScore = Scores[0].InterviewScore;

    for(int i = 1; i < n; ++i)
    {
        if(Scores[i].InterviewScore <  MinInterviewScore)
        {
            ++Result;
            MinInterviewScore = Scores[i].InterviewScore;
        }
    }

    return Result;
}
