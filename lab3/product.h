#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
public:
    Product();
    ~Product();
    void setName(QString);
    QString getName();
    void setNumber(int);
    int getNumber();
    void setGuild(int);
    int getGuild();
private:
    QString name;
    int number;
    int guild;
};

#endif // PRODUCT_H
