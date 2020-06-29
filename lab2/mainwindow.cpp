
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deputat=new database();
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), [=](){this->show_data();});
    QFile file("database.txt");
    file.open(QIODevice::ReadOnly);
    if(file.exists()){
        while(!file.atEnd()){
            deputat=database::addDeputat(deputat, amount);
            QString str;
            str=file.readLine();
            QStringList list = str.split(" ");
            deputat[amount].setLastName(list[0]);
            deputat[amount].setFirstName(list[1]);
            deputat[amount].setGender(list[2]);
            deputat[amount].setAge(list[3].toInt());
            deputat[amount].setChamber(list[4]);
            deputat[amount].setPartya(list[4]);
            ui->comboBox->addItem(deputat[amount].getLastName());
            amount++;
        }
    } else qDebug() << "file not found";
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addInfo_clicked()
{
    deputat=database::addDeputat(deputat, amount);
    QString str = ui->last_name->text();
    deputat[amount].setLastName(str);
    ui->last_name->clear();
    str = ui->first_name->text();
    deputat[amount].setFirstName(str);
    ui->first_name->clear();
    str = ui->gender->text();
    deputat[amount].setGender(str);
    ui->gender->clear();
    str = ui->age->text();
    deputat[amount].setAge(str.toInt());
    ui->age->clear();
    str = ui->chamber->text();
    deputat[amount].setChamber(str);
    ui->chamber->clear();
    str = ui->Partya->text();
    deputat[amount].setPartya(str);
    ui->Partya->clear();
    ui->comboBox->addItem(deputat[amount].getLastName());
    deputat[amount].addInfo();
    amount++;
}

void MainWindow::on_exit_clicked()
{
    exit(0);
}


void MainWindow::on_comboBox_activated(int index)
{
    chosen=index;
}

void MainWindow::show_data(){
    deputat[chosen].readInfo(chosen);
    ui->textBrowser->setOverwriteMode(true);
    ui->textBrowser->setText(deputat[chosen].getLastName()+"\n"+deputat[chosen].getFirstName()+"\n"+deputat[chosen].getGender()+"\n"+QString::number(deputat[chosen].getAge())+"\n"
                             +deputat[chosen].getChamber()+"\n"+deputat[chosen].getPartya());
}

void MainWindow::on_Edit_clicked()
{
    ui->last_name->setText(deputat[chosen].getLastName());
    ui->first_name->setText(deputat[chosen].getFirstName());
    ui->gender->setText(deputat[chosen].getGender());
    ui->age->setText(QString::number(deputat[chosen].getAge()));
    ui->chamber->setText(deputat[chosen].getChamber());
    ui->Partya->setText(deputat[chosen].getPartya());
}

void MainWindow::on_Save_clicked()
{
    ui->textBrowser->clear();
    QString str = ui->last_name->text();
    deputat[chosen].setLastName(str);
    ui->last_name->clear();
    str = ui->first_name->text();
    deputat[chosen].setFirstName(str);
    ui->first_name->clear();
    str = ui->gender->text();
    deputat[chosen].setGender(str);
    ui->gender->clear();
    str = ui->age->text();
    deputat[chosen].setAge(str.toInt());
    ui->age->clear();
    str = ui->chamber->text();
    deputat[chosen].setChamber(str);
    ui->chamber->clear();
    str = ui->Partya->text();
    deputat[chosen].setPartya(str);
    ui->Partya->clear();
    QFile file("database.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream write(&file);
    if(file.exists()){
        for(int i=0; i<amount; i++)
            write << deputat[i].getLastName() << " " <<  deputat[i].getFirstName() << " " << deputat[i].getGender() << " " <<
                     deputat[i].getAge() << " " << deputat[i].getChamber() << " " << deputat[i].getPartya() << " " << "\n";
    }
    file.close();
    ui->comboBox->setItemText(chosen, deputat[chosen].getLastName());
}

void MainWindow::on_Delete_clicked()
{
    ui->comboBox->removeItem(chosen);
    for(int i=chosen; i<amount-1; i++){
        deputat[i]=deputat[i+1];
    }
    deputat[amount-1].~database();
    amount--;
    QFile file("database.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream write(&file);
    if(file.exists()){
        for(int i=0; i<amount; i++)
            write << deputat[i].getLastName() << " " <<  deputat[i].getFirstName() << " " << deputat[i].getGender() << " " <<
                     deputat[i].getAge() << " " << deputat[i].getChamber() << " " << deputat[i].getPartya() << " " << "\n";
    }
    file.close();
}

void MainWindow::on_Search_clicked()
{
    QString str;
    str = ui->last_name->text();
    if(str==""){
        str=ui->Partya->text();
        if(str==""){
            int num;
            num = (ui->chamber->text()).toInt();
            for(int i=0; i<amount; i++){
                if(num==deputat[i].getChamber()) str+=deputat[i].getLastName()+"\n";
            }
            if(str=="") ui->textBrowser->setText("No deputats in chamber " +QString::number(num));
            else ui->textBrowser->setText("List of deputats in chamber "+QString::number(num)+":\n"+str);
        }else{
            QString diag = str;
            str="";
            for(int i=0; i<amount; i++){
                if(diag==deputat[i].getPartya()) str+=deputat[i].getLastName()+"\n";
            }
            if(str=="") ui->textBrowser->setText("No deputats with Partya " +diag);
            else ui->textBrowser->setText("List of deputats with Partya "+diag+":\n"+str);
        }
    }else{
        bool found = false;
        int searched;
        for(int i=0; i<amount; i++){
            if(str==deputat[i].getLastName()){ searched=i; found = true; break;}
        }
        if(found) ui->textBrowser->setText(deputat[searched].getLastName()+"\n"+deputat[searched].getFirstName()+"\n"+deputat[searched].getGender()+"\n"+QString::number(deputat[searched].getAge())+"\n"
                                           +deputat[searched].getChamber()+"\n"+deputat[searched].getPartya());
        else ui->textBrowser->setText("Data of deputat " + str + " is not found");
    }
}

void MainWindow::on_Sort_clicked()
{
    bool impos=false;
    QString str="";
    for(int i=0; i<amount; i++){
        for(int j=0; j<amount; j++){
            if(i==j) continue;
            if(deputat[i].getGender()==deputat[j].getGender()){
                if(deputat[i].getPartya()==deputat[j].getPartya()){
                    deputat[j].setChamber(deputat[i].getChamber());
                    impos = false;
                }
                else impos=true;
            }
        }
        if(impos) str+=deputat[i].getLastName()+" " + deputat[i].getFirstName() + " " +deputat[i].getGender() + " "+ QString::number(deputat[i].getAge()) + " " + deputat[i].getPartya() + "\n";
    }
    QFile file("database.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream write(&file);
    if(file.exists()){
        for(int i=0; i<amount; i++)
            write << deputat[i].getLastName() << " " <<  deputat[i].getFirstName() << " " << deputat[i].getGender() << " " <<
                     deputat[i].getAge() << " " << deputat[i].getChamber() << " " << deputat[i].getPartya() << " " << "\n";
    }
    file.close();
    if(str=="") ui->textBrowser->setText("All deputats are provided with chambers");
    else ui->textBrowser->setText("List of deputats who cannot be provided with chambers:\n"+str);
}

