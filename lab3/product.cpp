#include "product.h"

Product::Product()
{

}

Product::~Product()
{

}

void Product::setName(QString str)
{
 name = str;
}

QString Product::getName(){
    return name;
}

void Product::setNumber(int value){
    number = value;

}

int Product::getNumber(){
    return number;
}

void Product::setGuild(int value)
{
    guild = value;
}

int Product::getGuild(){
    return guild;
}
