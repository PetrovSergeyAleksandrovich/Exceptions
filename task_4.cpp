#include <iostream>

template<typename T>
T average(T* array)
{
    T result = array[0];
    for(int i = 1; i < 10; ++i)
    {
        result += array[i];
    }
    return result / 10;
}

int main()
{
    int arr_1[10] = {1,2,3,4,5,6,7,8,9,10};
    float arr_2[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    double arr_3[10] = {1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99, 10.101};

    std::cout << "INT average: " << average(arr_1) << std::endl;
    std::cout << "FLOAT average: " << average(arr_2) << std::endl;
    std::cout << "DOUBLE average: " << average(arr_3) << std::endl;

    return 0;
}
