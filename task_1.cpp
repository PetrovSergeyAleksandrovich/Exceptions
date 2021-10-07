#include <map>
#include <iostream>
#include <string>
#include <exception>

struct OperationType
{
    std::string add = "add";
    std::string remove = "remove";
};

class Basket
{
private:
    std::map<std::string, int> database;
public:

    Basket()
    {
        std::cout << "basket created" << std::endl;
    }

    void add(std::string& clothes_type, int& quantity)
    {
        bool type_exists = false;
        for(std::map<std::string, int>::iterator ITR = database.begin(); ITR != database.end(); ++ITR)
        {
            if(ITR->first == clothes_type) {type_exists = true; break;}
        }
        if(type_exists)
        {
            std::map<std::string, int>::iterator ITR = database.find(clothes_type);
            ITR->second += quantity;
        }
        if(!type_exists)
        {
            database.insert(std::pair<std::string, int>(clothes_type, quantity));
        }
    };

    void remove(int& clothes_type, int& quantity)
    {
        for(std::map<std::string, int>::iterator ITR = database.begin(); ITR != database.end(); ++ITR)
        {
            ;
        }
    };

    void show()
    {
        std::cout << "Your Basket:\n";
        for(std::map<std::string, int>::iterator ITR = database.begin(); ITR != database.end(); ++ITR)
        {
            std::cout << ITR->first << " " << ITR->second << std::endl;
        }
        std::cout << std::endl;
    }

    ~Basket()
    {
        std::cout << "basket destroyed" << std::endl;
    }
};

void checkShop(std::string& clothes_type, int& quantity, std::map<std::string, int>& shop)
{
    bool accepted_clothes = false;
    bool accepted_quantity = false;
    
    for(std::map<std::string, int>::iterator ITR = shop.begin(); ITR != shop.end(); ++ITR)
    {
        if(ITR->first == clothes_type)
        {
            accepted_clothes = true;
            if(quantity > 0 && quantity <= ITR->second)
            {
                accepted_quantity = true;
                break;
            }
        }
    }
    if(!accepted_clothes && !accepted_quantity) throw std::invalid_argument("Caught exception : clothes_type & quantity ");
    if(!accepted_clothes) throw std::invalid_argument("Caught exception : clothes_type ");
    if(!accepted_quantity) throw std::invalid_argument("Caught exception : quantity ");

    std::map<std::string, int>::iterator ITR = shop.find(clothes_type);
    ITR->second -= quantity;
}

int main()
{
    std::map<std::string, int> shop;
    shop.insert(std::pair<std::string, int>("shoes", 10));
    shop.insert(std::pair<std::string, int>("sweater", 10));
    shop.insert(std::pair<std::string, int>("tshirt", 10));
    shop.insert(std::pair<std::string, int>("pants", 10));
    shop.insert(std::pair<std::string, int>("hat", 10));

    Basket basket;
    std::string input_type;
    int input_quantity;
    OperationType operation_type;
    std::string input_operation;
    bool isReady = false;

    while(!isReady)
    {
        std::cout << "Type 'add' or 'remove': ";
        std::cin >> input_operation;

        if(input_operation == operation_type.add)
        {
            std::cout << "Type of clothes shoes/sweater/tshirt/pants/hat: ";
            std::cin >> input_type;
            std::cout << "Quantity: ";
            std::cin >> input_quantity;

            try
            {
                checkShop(input_type, input_quantity, shop);
                basket.add(input_type, input_quantity);
            }
            catch (const std::exception& x)
            {
                std::cerr << x.what() << std::endl <<  std::endl;
            }
        }

        if(input_operation == operation_type.remove)
        {
            std::cout << "Type of clothes shoes/sweater/tshirt/pants/hat: ";
            std::cin >> input_type;
            std::cout << "Quantity: ";
            std::cin >> input_quantity;

            try
            {
                ;

            }
            catch (const std::exception& x)
            {
                ;
            }
        }
        basket.show();
    }


    return 0;
}



