#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>

enum Type
{
    NOTHING,
    FISH,
    BOOTS
};

class Section
{
private:
    int section_type = Type::NOTHING;
public:

    void setSectionType(int _type)
    {
        section_type = _type;
    }

    int getSectionType()
    {
        return section_type;
    }
};

class GameField
{
private:
    Section field[8][8];
public:
    GameField()
    {

        bool fish_set = false;
        bool boots_set = false;
        int x, y;

        srand(time(nullptr));
        x = rand() % 8;
        Sleep(1000);
        y = rand() % 8;
        Sleep(1000);
        field[x][y].setSectionType(Type::FISH);

        int count = 0;
        while(count < 3)
        {
            srand(time(nullptr));
            x = rand() % 8;
            Sleep(1000);
            y = rand() % 8;
            Sleep(1000);
            if(field[x][y].getSectionType() == Type::NOTHING)
            {
                field[x][y].setSectionType(Type::BOOTS);
                ++count;
            }
        }

        std::cout << "gamefield generated" << std::endl;
    }

    void showField()
    {
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                std::cout << field[i][j].getSectionType() << " ";
            }
            std::cout << std::endl;
        }
    }

    ~GameField()
    {
        std::cout << "GAME OVER" << std::endl;
    }
};

int main()
{

    GameField gamefield;
    gamefield.showField();

    return 0;
}

