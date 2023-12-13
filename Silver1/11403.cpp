// #include <iostream>
// #include <thread>
// #include <mutex>
// #define MAX_LOOP 1000000

// std::mutex mutex1;
// int a = 0;

// void task1() {
//     for(int i = 0; i < MAX_LOOP; ++i)
//     {
//         // 뮤텍스1을 잠그기
//         mutex1.lock();
//         ++a;
//         // 뮤텍스 해제
//         mutex1.unlock();

//     }
// }

// void task2() {
//     for(int i = 0; i < MAX_LOOP; ++i)
//     {
//         // 뮤텍스1을 잠그기
//         mutex1.lock();
//         ++a;
//         // 뮤텍스 해제
//         mutex1.unlock();

//     }
// }

// int main() {
//     std::thread t1(task1);
//     std::thread t2(task2);

//     t1.join();
//     t2.join();


//     int k = a;
//     return 0;
// }

#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>

const int NUM_THREADS = 3;
const int NUM_WORK = 10000;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

sem_t countingSemaphore;

void task(int id) {
    for (int i = 0; i < NUM_WORK; ++i) {
        sem_wait(&countingSemaphore);  // counting 세마포어 감소
        ++a;
        sem_post(&countingSemaphore);  // counting 세마포어 증가
    }
    
    // for(int a = 0; a < n; ++a)
    // {
    //     bool NoChage = true;
    //     for(int i = 0; i < n; ++i)
    //     {
    //         for(int j = 0; j < n; ++j)
    //         {
    //             for(int k = 0; k < n; ++k)
    //             {
    //                 if(Mat[i][j] == 1 && Mat[j][k] == 1 && Mat[i][k] != 1)
    //                 {
    //                     Mat[i][k] = 1;
    //                     NoChage = false;
    //                 }
    //             }
    //         }
    //     }
    //     if(NoChage)
    //     {
    //         break;
    //     }
    // }

    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(Mat[i][k] == 1 && Mat[k][j] == 1)
                {
                    Mat[i][j] = 1;
                }
            }
        }
    }
    

int main() {
    sem_init(&countingSemaphore, 0, 1); // counting 세마포어 초기화

    std::thread threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = std::thread(task, i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    sem_destroy(&countingSemaphore);  // counting 세마포어 파괴

    int k = a;

    return 0;
}
