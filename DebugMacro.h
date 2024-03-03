#define PRINT_VECTOR_MAT(VMat)\
    std::cout << '\n';\
    for(int VRow = 0; VRow < VMat.size(); ++VRow)\
    {\
        for(int VCol = 0; VCol < VMat[VRow].size(); ++VCol)\
            std::cout << VMat[VRow][VCol] << ' ';\
        std::cout << '\n';\
    }\
    std::cout << '\n';