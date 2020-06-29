
#include "database.h"

database::database(QObject* parent):QObject(parent)
{
    file = new QFile("database.txt");
}

database::~database(){
}

QString database::getFirstName(){
    return first_name;
}

void database::setFirstName(QString value){
    first_name=value;
}

QString database::getLastName(){
    return last_name;
}

void database::setLastName(QString value){
    last_name=value;
}

QString database::getGender(){
    return gender;
}

void database::setGender(QString value){
    gender=value;
}

QString database::getPartya(){
    return Partya;
}

void database::setPartya(QString value){
    Partya=value;
}

QString database::getChamber(){
    return chamber;
}

void database::setChamber(QString value){
    chamber=value;
}

int database::getAge(){
    return age;
}

void database::setAge(int value){
    age=value;
}

void database::addInfo(){
    file->open(QIODevice::Append);
    if(file->exists()){
        QTextStream write(file);
        write << getLastName() << " " << getFirstName() << " " << getGender() << " " << getAge() << " " << getChamber() << " " << getPartya() << "\n";
    } else qDebug() << "file not found";
    file->close();
}

void database::readInfo(int amount){
    file->open(QIODevice::ReadOnly);
    if(file->exists()){
        QTextStream read(file);
        for(int i=0; i<amount+1; i++)
            read >> last_name >> first_name >> gender >> age >> chamber >> Partya;
    } else qDebug() << "file not found";
    file->close();
}

database* database:: addDeputat(database* obj, int amount) {
    if (amount == 0) {
        obj = new database[amount + 1];
    }
    else {
        database* tempObj = new database[amount + 1];
        for (int i = 0; i < amount; i++) {
            tempObj[i] = obj[i];
        }
        delete[] obj;
        obj = tempObj;
    }
    return obj;
}

void database:: operator=(database &obj){
    this->age=obj.age;
    this->first_name=obj.first_name;
    this->last_name=obj.last_name;
    this->gender=obj.gender;
    this->chamber=obj.chamber;
    this->Partya=obj.Partya;
    if(this->file!=nullptr) delete this->file;
    this->file=obj.file;
}

