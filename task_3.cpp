#include <iostream>
#include <vector>
#include <exception>

template<typename T1, typename T2>
class Register
{
private:
    std::vector<T1> keys;
    std::vector<T2> values;
public:
    Register()
    {
        std::cout << "class generated" << std::endl;
    }

    void add()
    {
        T1 key_tmp;
        T2 value_tmp;
        std::cout << "KEY\n:";
        try
        {
            if(!(std::cin >> key_tmp)) throw std::invalid_argument("wrong key type");
            keys.push_back(key_tmp);
        }
        catch(const std::exception& x)
        {
          std::cerr  << x.what() << std::endl;
        }

//        std::cout << "VALUE\n:";
//        try
//        {
//            if(!(std::cin >> value_tmp)) throw std::exception();
//            values.push_back(value_tmp);
//        }
//        catch(...)
//        {
//            std::cerr << "wrong value type" << std::endl;
//        }

    }

    ~Register()
    {
        std::cout << "class destroyed" << std::endl;
    }
};


int main()
{
    bool flag = true;
    std::string command;

    Register<int, int> data;

    while(flag)
    {
        data.add();
    }

    

    return 0;
}

