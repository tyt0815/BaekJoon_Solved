#include <iostream>
#include <vector>

using namespace std;

class FTermProject
{
public:
    FTermProject(int N);

    int CountRemains();
private:
    vector<int> Preferences;
    vector<int> States;
    vector<bool> bVisited;
    
    int TraceCycle(int i);
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        FTermProject TermProject(N);
        cout << TermProject.CountRemains() << '\n';
    }

    return 0;   
}

FTermProject::FTermProject(int N):
    Preferences(N + 1),
    States(N + 1, 0),
    bVisited(N + 1, false)
{
    for(int i = 1; i <= N; ++i)
    {
        cin >> Preferences[i];
    }
}

int FTermProject::CountRemains()
{
    for(int i = 1; i < Preferences.size(); ++i)
    {
        if(States[i] == 0)
        {
            TraceCycle(i);
        }
    }

    int Count = 0;
    for(int i = 1; i < States.size(); ++i)
    {
        if(States[i] == -1) ++Count;
    }
    return Count;
}

int FTermProject::TraceCycle(int i)
{
    if(States[i] != 0)
    {
        return -1;
    }
    if(bVisited[i]) 
    {
        return i;
    }
    bVisited[i] = true;

    States[i] = TraceCycle(Preferences[i]);

    bVisited[i] = false;
    if(States[i] == i)
    {
        return -1;
    }
    else
    {
        return States[i];
    }
}