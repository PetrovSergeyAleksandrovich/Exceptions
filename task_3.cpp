#include <iostream>
#include <vector>
#include <exception>

template<typename T1, typename T2>
class Data
{
private:
    std::vector<T1> keys;
    std::vector<T2> values;
public:
    Data()
    {
        std::cout << "class generated" << std::endl;
    }

    void add(T1 a, T2 b)
    {
        keys.push_back(a);
        values.push_back(b);
    }

    void remove(T1 a)
    {
        keys.push_back(a);
        ///values.push_back(b);
    }

    void print(T1 a)
    {
        if(keys.size() == 0) throw std::invalid_argument("empty list");
        for(int i = 0; i < keys.size(); ++i)
        {
            std::cout << keys[i] << " : " << values[i] << std::endl;
        }
    }

    void find(T1 a)
    {
        if(keys.size() == 0) throw std::invalid_argument("empty list");
        for(int i = 0; i < keys.size(); ++i)
        {
            std::cout << keys[i] << " : " << values[i] << std::endl;
        }
    }

    ~Data()
    {
        std::cout << "class destroyed" << std::endl;
    }
};

int main()
{
    Data<int, int> data1;
    Data<int, float> data2;
    Data<int, std::string> data3;

    

    return 0;
}

