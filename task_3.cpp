#include <iostream>
#include <vector>

template<typename K, typename V>
struct Element
{
    K key;
    V value;
    Element(K k, V v): key(k), value(v)
    {}
};

template<typename K, typename V>
class Register
{
private:
    std::vector<Element<K, V>> pairs;
public:
    Register()
    {
        std::cout << "Register generated" << std::endl;
    }

    void add()
    {
        K key_tmp;
        V value_tmp;
        std::cout << "KEY\n:";
        std::cin >> key_tmp;
        std::cout << "VALUE\n:";
        std::cin >> value_tmp;
        pairs.emplace_back(key_tmp, value_tmp);
    }

    void remove()
    {
        if(pairs.size() == 0) {std::cout << "Register Empty\n"; return;}
        std::cout << "Type KEY to erase element: ";
        K key_tmp;
        std::cin >> key_tmp;
        for(int i = 0; i < pairs.size(); ++i)
        {
            if(pairs.size() == 1) {pairs.clear(); break;}
            if(pairs[i].key == key_tmp) pairs.erase(pairs.begin()+i);
        }
    }

    void find()
    {
        std::cout << "Type KEY to find element: ";
        K key_tmp;
        std::cin >> key_tmp;
        for(int i = 0; i < pairs.size(); ++i)
        {
            if(pairs[i].key == key_tmp) std::cout << "VALUE: " << pairs[i].value << std::endl;
        }
    }

    void print()
    {

        if(pairs.size() == 0) std::cout << "Register Empty\n";
        else
        {
            std::cout << "Register:\n";
            for(int i = 0; i < pairs.size(); ++i)
            {
                std::cout << pairs[i].key << ": " << pairs[i].value << std::endl;
            }
        }
    }
    ~Register()
    {
        std::cout << "Register destroyed" << std::endl;
    }
};

int main()
{
    bool flag = true;
    std::string command;

    ///Change type of data here
    Register<std::string, std::string> data;

    while(flag)
    {
        std::cout << "command:";
        std::cin >> command;
        if(command == "add") data.add();
        if(command == "remove") data.remove();
        if(command == "find") data.find();
        if(command == "print") data.print();
        if(command == "exit") flag = false;
    }
    return 0;
}

