
#ifndef DATABASE_H
#define DATABASE_H
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QObject>
class database:public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = NULL);
    ~database();
    QString getFirstName();
    void setFirstName(QString value);
    QString getLastName();
    void setLastName(QString value);
    QString getGender();
    void setGender(QString value);
    QString getPartya();
    void setPartya(QString value);
    int getAge();
    void setAge(int value);
    QString getChamber();
    void setChamber(QString value);
    static database* addDeputat(database* obj, int amount);
    void operator=(database &obj);

private:
    QFile* file;
    QString first_name;
    QString last_name;
    QString gender;
    QString Partya;
    int age;
    QString chamber;
public slots:
    void addInfo();
    void readInfo(int amount);
};

#endif // DATABASE_H

