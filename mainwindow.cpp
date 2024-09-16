#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <qstring.h>
#include <QPixmap>

#include <QWidget>


//ответы на задания
QString zadaniya[31] {"a+2*b/x", //1
                       "a+b/(2*x)", //2
                       "a+(b+2)/x", //3
                       "a+(b/(x+2))", //4
                       "(a+b)/(x+2)", //5
                       "(a+b)/(2*x)*c", //6
                       "(a+b)/(2*x)*(c+5)/y", //7
                       "(a+b)/(2*x)/((c+5)/y)", //8
                       "math.cos(2*x)", //9
                       "math.cos(2*x)*math.cos(2*x)", //10 //differ
                       "abs(math.cos(x*x))", //11
                       "math.cos(math.sqrt(x))", //12
                       "math.cos(math.sqrt(abs(x))", //13
                       "math.sqrt(abs(math.cos(x)))", //14
                       "pow(math.e,2*x)", //15
                       "pow(math.e,math.sqrt(x))", //16
                       "pow(math.e,pow(x,2))", //17
                       "pow(math.e,math.cos(abs(x))", //18
                       "pow(math.e,math.cos(x)+math.sin(x))", //19
                       "2*pow(math.e,math.tan(x))", //20
                       "abs(math.cos((x+1)*(x+1)))", //21 //differ
                       "pow(math.e,pow(math.cos(x),2)", //22 //differ
                       "math.tan(pow(math.e,x))", //23
                       "a/c*b/d-(a*b-c)/(c*d)", //24
                       "((math.sin(x)+math.cos(y))/(math.cos(x)-math.sin(y))*math.tan(x*y)", //25
                       "(x+y)/(x*y)-(x*y-12)/(34+x)", //26
                       "(3+pow(math.e,x)/(1+x*abs(y-math.tan(x))", //27
                       "x-math.sin(x)/(3*x)-math.cos(x)/(5*x)", //28
                       "(math.log(abs(math.cos(x))))/math.log(1+x)", //29
                       "(math.cos(x)/(math.pi-2*x))+16*x*math.cos(x*y)-2", //30
};


QString zadaniya_2[31] {"a+2*b/x", // 1
                       "a+b/(2*x)", //2
                       "a+(b+2)/x", // 3
                       "a+(b/(x+2))", // 4
                       "(a+b)/(x+2)", //5
                       "(a+b)/(2*x)*c", //6
                       "(a+b)/(2*x)*(c+5)/y", //7
                       "(a+b)/(2*x)/((c+5)/y)", //8
                       "math.cos(2*x)", //9
                       "pow(math.cos(2*x),2)", //10
                       "abs(pow(x,2))", //11 //differ
                       "math.cos(math.sqrt(x))", // 12
                       "math.cos(math.sqrt(abs(x))", // 13
                       "math.sqrt(math.cos(abs(x)))", // 14
                       "pow(math.e,2*x)", //15
                       "pow(math.e,math.sqrt(x))", //16
                       "pow(math.e,x*x)", //17 //differ
                       "pow(math.e,math.cos(abs(x))", //18
                       "pow(math.e,math.cos(x)+math.sin(x))", //19
                       "2*pow(math.e,math.tan(x))", //20
                       "abs(pow(math.cos(x+1),2))", //21 //differ
                       "pow(math.e,cos(x)*cos(x))", //22 //differ
                       "math.tan(pow(math.e,x))", //23
                       "a/c*b/d-(a*b-c)/(c*d)",
                       "((math.sin(x)+math.cos(y))/(math.cos(x)-math.sin(y))*math.tan(x*y)",
                       "(x+y)/(x*y)-(x*y-12)/(34+x)",
                       "(3+pow(math.e,x)/(1+x*abs(y-math.tan(x))/",
                       "x-math.sin(x)/(3*x)-math.cos(x)/(5*x)",
                       "(math.log(abs(math.cos(x))))/math.log(1+x)",
                       "(math.cos(x)/(math.pi-2*x))+16*x*math.cos(x*y)-2",
                       };

int counter = 0;
bool next = true;
int ocenka = 0;
bool clickedbefore = false;
int hod = 0;
bool proverilvseok = false;
bool kk = false;
int ocenkakon = 0;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    QMessageBox::information(this,"О приложении","Создал Даниил Стеблянко (<a href='https://github.com/XlebB'>Github</a>).      <br>");
}

void MainWindow::on_action_2_triggered()
{
   QMessageBox::information(this,"Оценивание","Всего 30 заданий, за каждый правильный ответ начисляется 1 балл. <br><br> "
                                                 "Набрано от 27 баллов - оценка 5.<br>"
                                                 "Набрано от 23 до 26 баллов - оценка 4.<br>"
                                                 "Набрано от 17 до 22 баллов - оценка 3.<br>"
                                                 "Набрано меньше 16 баллов - оценка 2.<br><br>"
                                                 "<b>Ответ вводить без пробелов между символами, использовать наименьшее количество скобок.<br>"
                                                 "Если раз ответить неправильно, но после ответить верно, балл не засчитает."
                                                 "<b><br>");
}

void MainWindow::on_action_3_triggered()
{
    QMessageBox::information(this,"Справочные материалы","Для сложных функций использовать возможности модуля math:<br><br> "
                             "math.cos(выражение) - Косинус.<br>"
                             "math.sin(выражение) - Синус.<br>"
                             "math.e(выражение) - Экспонента.<br>"
                             "math.pi(выражение) - Число Pi.<br>"
                             "math.sqrt(выражение) - Корень числа.<br>"
                             "pow(выражение,степень/выражение) - Cтепень числа.<br>"
                             "math.sqrt(выражение) - Корень числа.<br>"
                             "math.log(выражение) - Логарифм числа.<br>");
}


void MainWindow::on_pushButton_3_clicked()  // получить задание
{
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    if(hod==0){
        hod = 1;
    }
    if(hod==31){
        //Критерии оценивания и вывод оценки
        if(ocenka>=27){
            ocenkakon = 5;
        }
        if((ocenka>=23)&&(ocenka<=26)){
            ocenkakon = 4;
        }
        if((ocenka>=17)&&(ocenka<=22)){
            ocenkakon = 3;
        }
        if(ocenka<=16){
            ocenkakon = 2;
        }
    QMessageBox inff;
    inff.setWindowTitle("Результат");
    inff.setInformativeText("Оценка = " + QString::number(ocenkakon));
    inff.setFixedSize(400,300);
    inff.exec();
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    hod = 0;
    }

    ui->lineEdit_2->setText("");
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

    if(next==true){
    //мне было слишком в падлу писать адекватную индексацию фотографий соре
    QString str1 = ":/img/";
    QString str2 = ".png";
    QString str3 = QString::number(counter+1);
    str1.append(str3).append(str2);

    QPixmap pix(str1);
    int w = ui -> image ->width();
    int h = ui -> image ->height();
    ui ->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->label_3->setText(QString::number(counter+1));

    counter = counter +1;
    next = false;
    }
}


void MainWindow::on_pushButton_clicked(){  // проверить
    QString answer=ui->lineEdit_2->text();

    if(counter==0){
        return;
    }

    if(answer==""){ //если ничего не написал
        ui->label_6->setText("Введите ответ");
        clickedbefore = false;
        ui->pushButton->setEnabled(true);
    }

    if((answer!=zadaniya[counter-1])&&(answer!="")){ //если ответ невырный
        ui->label_6->setText("Не верно");
        clickedbefore = true;
    }


    if((answer==zadaniya[counter-1]) || (answer==zadaniya_2[counter-1])){  //если правильный ответ
        next = true; //cледующий ход
        ui->label_6->setText("Верно");

        if(clickedbefore==false){
            ocenka=ocenka+1;
        }

        ui->label_8->setText(QString::number(ocenka) + " из 30");
        clickedbefore = false;
        ui->lineEdit_2->setText("");
        hod=hod+1;
        ui->pushButton->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
    }


    if(hod==31){

        //Критерии оценивания
        if(ocenka>=27){
            ocenkakon = 5;
        }
        if((ocenka>=23)&&(ocenka<=26)){
            ocenkakon = 4;
        }
        if((ocenka>=17)&&(ocenka<=22)){
            ocenkakon = 3;
        }
        if(ocenka<=16){
            ocenkakon = 2;
        }
        //создание окна
        QMessageBox inff;
        inff.setWindowTitle("Результат");
        inff.setInformativeText("Оценка = " + QString::number(ocenkakon));
        inff.setFixedSize(400,300);
        inff.exec();
        ui->pushButton->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        hod = 0;

        }
        }


void MainWindow::on_pushButton_4_clicked() //пропуск задания
{
    if(hod==0){
        return;
    }
    next = true;
    ui->label_6->setText("Пропущено");
    ui->label_8->setText(QString::number(ocenka) + " из 30");
    clickedbefore = false;
    ui->lineEdit_2->setText("");
    hod=hod+1;
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
}

