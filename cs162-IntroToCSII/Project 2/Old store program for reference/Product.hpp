#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product
{
private:
    std::string idCode;
    std::string title;
    std::string description;
    double price;
    int quantityAvailable;
public:
    Product(std::string id, std::string t, std::string d, double p, int qa);
    std::string getIdCode();
    std::string getTitle();
    std::string getDescription();
    double getPrice();
    int getQuantityAvailable();
    void decreaseQuantity();
};

#endif
