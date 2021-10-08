#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>

enum Type
{
    NOTHING,
    FISH,
    BOOTS,
    CHECKED
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
        std::cout << "F generated ";

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
            std::cout << "B generated ";
        }
        std::cout << std::endl;
        std::cout << "gamefield generated" << std::endl;
    }

    void setSectionType(int& x, int& y)
    {
        field[x][y].setSectionType(Type::CHECKED);
    }

    int getSectionType(int& x, int& y)
    {
        return field[x][y].getSectionType();
    }

    void showField()
    {
        std::cout << std::endl;
        for(int i = 0; i < 8; ++i)
        {
            for(int j = 0; j < 8; ++j)
            {
                if(field[i][j].getSectionType() == Type::CHECKED)
                {
                    std::cout << "O" << " ";
                }
                else std::cout << "X" << " ";
            }
            std::cout << std::endl;
        }
    }

    ~GameField()
    {
        std::cout << "GAME OVER" << std::endl;
    }
};

void checkInput(int& x, int& y)
{
    if(x >= 0 && x < 8 && y >= 0 && y < 8) return;
    throw std::invalid_argument("wrong numbers");
}

void checkEndGame(bool& status, int& attempts)
{
    if(!status) throw std::exception();
    if(status) std::cout << "You WIN with " << attempts << " attempts" << std::endl;
}

int main()
{

    GameField gamefield;
    bool isGaming = true;
    bool isWin = false;
    int x, y;
    int attempts = 0;

    while(isGaming)
    {
        ///PRINT GAMEFIELD
        gamefield.showField();

        std::cout << "type field x y: ";
        std::cin >> x >> y;

        try
        {
            checkInput(x,y);
            if(gamefield.getSectionType(x,y) == Type::FISH)
            {
                isGaming = false;
                isWin = true;
            }
            if(gamefield.getSectionType(x,y) == Type::BOOTS)
            {
                isGaming = false;
            }
            gamefield.setSectionType(x,y);
        }
        catch(const std::exception& x)
        {
            std::cerr << "error " << x.what() << std::endl;
        }
        ++attempts;
    }

    try {
        checkEndGame(isWin, attempts);
    }
    catch(...)
    {
        std::cerr << "You LOST with " << attempts << " attempts" << std::endl;
    }

    return 0;
}

