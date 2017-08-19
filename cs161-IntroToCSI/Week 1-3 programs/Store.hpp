#ifndef STORE_HPP
#define STORE_HPP

#include <string>
#include "Customer.hpp"

class Store
{
private:
    std::vector<Product*> inventory;
    std::vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(std::string);
    Customer* getMemberFromID(std::string);
    void productSearch(std::string str);
    void addProductToMemberCart(std::string pID, std::string mID);
    void checkOutMember(std::string mID);
};

#endif
