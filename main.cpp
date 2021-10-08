#include <iostream>
#include <map>
#include <ctime>
#include <windows.h>

int main() {
    int x;
    while(true)
    {
        srand(time(nullptr));
        x = rand() % 8;
        std::cout << x;
        Sleep(1000);
    }
    return 0;
}
