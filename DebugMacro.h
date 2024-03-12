#define PRINT_VECTOR_MAT(VectorMat)\
    std::cout << '\n';\
    for(int VRow = 0; VRow < VectorMat.size(); ++VRow)\
    {\
        for(int VCol = 0; VCol < VectorMat[VRow].size(); ++VCol)\
            std::cout << VectorMat[VRow][VCol] << ' ';\
        std::cout << '\n';\
    }\
    std::cout << '\n';