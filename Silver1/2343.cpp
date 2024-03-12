// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     uint32_t n, m, TotalSize = 0, MaxSize = 0;
//     vector<uint32_t> CourseSizes;
//     cin >> n >> m;
//     CourseSizes.resize(n);
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> CourseSizes[i];
//         TotalSize += CourseSizes[i];
//         MaxSize = max(MaxSize, CourseSizes[i]);
//     }

//     int Size = max(TotalSize / m, MaxSize);
//     while(true)
//     {
//         vector<uint32_t> v(m, 0);
//         uint32_t i = 0, j = 0;
//         for(;j < n; ++j)
//         {
//             if(v[i] + CourseSizes[j] > Size) ++i;
//             if(i == m) break;
//             v[i] += CourseSizes[j];
//         }
//         if(j == n) break;
//         ++Size;
//     }

//     cout << Size;

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

        uint32_t n, m, MaxSize = 0, TotalSize = 0;;
        cin >> n >> m;
        vector<uint32_t> CourseSizes(n, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> CourseSizes[i];
            TotalSize += CourseSizes[i];
            MaxSize = max(MaxSize, CourseSizes[i]);
        }

        uint32_t LowSize = max(TotalSize / m, MaxSize), HighSize = TotalSize;
        
        while (LowSize <= HighSize)
        {
            uint32_t BluerayNum = 0, BlueraySize = 0;
            uint32_t Mid = (LowSize + HighSize) / 2;
            for(auto CourseSize : CourseSizes)
            {
                if(BlueraySize + CourseSize > Mid)
                {
                    ++BluerayNum;
                    BlueraySize = 0;
                }
                BlueraySize += CourseSize;
            }
            if(BlueraySize > 0) ++BluerayNum;
            if(BluerayNum <= m) HighSize = Mid - 1;
            else LowSize = Mid + 1;
        }
        cout << LowSize;
        return 0;
}