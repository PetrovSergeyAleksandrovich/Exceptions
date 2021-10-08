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
        for(auto ITR = database.begin(); ITR != database.end(); ++ITR)
        {
            if(ITR->first == clothes_type) {type_exists = true; break;}
        }
        if(type_exists)
        {
            auto ITR = database.find(clothes_type);
            ITR->second += quantity;
        }
        if(!type_exists)
        {
            database.insert(std::pair<std::string, int>(clothes_type, quantity));
        }
    };

    void remove(std::string& clothes_type, int& quantity)
    {
        bool accepted_clothes = false;
        bool accepted_quantity = false;

        for(auto ITR = database.begin(); ITR != database.end(); ++ITR)
        {
            if(ITR->first == clothes_type)
            {
                accepted_clothes = true;
                if(ITR->second == 0 )
                {
                    throw std::invalid_argument("Caught exception : no goods in basket to remove ");
                }
                if(quantity > 0 && quantity <= ITR->second)
                {
                    accepted_quantity = true;
                    ITR->second -= quantity;
                }
            }
        }
        if(!accepted_clothes && !accepted_quantity) throw std::invalid_argument("Caught exception at remove: clothes_type & quantity ");
        if(!accepted_clothes) throw std::invalid_argument("Caught exception at remove: clothes_type ");
        if(!accepted_quantity) throw std::invalid_argument("Caught exception at remove: no such quantity  ");
    };

    void show()
    {
        std::cout << "Your Basket:\n";
        for(auto ITR = database.begin(); ITR != database.end(); ++ITR)
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
    
    for(auto ITR = shop.begin(); ITR != shop.end(); ++ITR)
    {
        if(ITR->first == clothes_type)
        {
            accepted_clothes = true;
            if(ITR->second == 0)
            {
                throw std::invalid_argument("Caught exception : no goods at stock ");
            }
            if(quantity > 0 && quantity <= ITR->second)
            {
                accepted_quantity = true;
                ITR->second -= quantity;
            }
        }
    }
    if(!accepted_clothes && !accepted_quantity) throw std::invalid_argument("Caught exception at add: clothes_type & quantity ");
    if(!accepted_clothes) throw std::invalid_argument("Caught exception at add: clothes_type ");
    if(!accepted_quantity) throw std::invalid_argument("Caught exception at add: no such quantity ");
}

void checkOperation(std::string& operation)
{
    if(operation != "add" && operation != "remove") throw std::exception();
    return;
}

int main()
{
    std::map<std::string, int> shop;
    shop.insert(std::pair<std::string, int>("shoes", 10));
    shop.insert(std::pair<std::string, int>("sweater", 5));
    shop.insert(std::pair<std::string, int>("tshirt", 15));
    shop.insert(std::pair<std::string, int>("pants", 10));
    shop.insert(std::pair<std::string, int>("hat", 5));

    Basket basket;
    std::string input_type;
    int input_quantity;
    OperationType operation_type;
    std::string input_operation;
    bool isReady = false;

    while(!isReady)
    {
        std::cout << "Shop LIST: " << std::endl;
        for(std::map<std::string, int>::iterator ITR = shop.begin(); ITR != shop.end(); ++ITR)
        {
            std::cout << ITR->first << " : " << ITR->second << std::endl;
        }
        std::cout  << std::endl;

        std::cout << "Type 'add' or 'remove' to/from basket'\n: ";
        std::cin >> input_operation;

        /// CHECK OPERATION IS CORRECT
        try {
            checkOperation(input_operation);
        }
        catch(...)
        {
            std::cerr << "Wrong Operation" << std::endl;
        }

        /// SECTION TO ADD GOODS TO BASKET. CHECKS SHOP FIRST
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

        /// SECTION TO REMOVE GOODS FROM BASKET. CHECKS BASKET FIRST
        if(input_operation == operation_type.remove)
        {
            std::cout << "Type of clothes shoes/sweater/tshirt/pants/hat: ";
            std::cin >> input_type;
            std::cout << "Quantity: ";
            std::cin >> input_quantity;

            try
            {
                basket.remove(input_type, input_quantity);
                std::map<std::string, int>::iterator ITR = shop.find(input_type);
                ITR->second += input_quantity;
            }
            catch (const std::exception& x)
            {
                std::cerr << x.what() << std::endl <<  std::endl;;
            }
        }
        basket.show();

        /// EXIT SECTION
        while(true)
        {
            std::string answer = "none";
            std::cout << std::endl << "Type 'q' to quit, 'c' to continue:";
            std::cin >> answer;
            answer == "q" ? isReady = true: isReady = false;
            if(answer == "q" || answer == "c") break;
        }
    }
    return 0;
}



