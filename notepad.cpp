#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);

    /** 手动关联信号与槽函数 */
    connect(ui->blackRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->blueRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->redRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

}

int Notepad::static_test = 100; //在这里初始化静态成员

void myFuc_outClas(){
    //在这里实现此函数
}

void Notepad::testFunc() {
    Notepad::static_test = 10;  //此处仅仅是赋值，仍需要在对应cpp文件中做初始化操作，否则这里会报错
    Notepad *p = new Notepad(); //正确
    //    Ui::Notepad *p = new Ui::Notepad;   //“使用了未定义类型”
    //    Notepad *p = new Ui::Notepad;   //“使用了未定义类型”
    //    Notepad *p = new Ui::Notepad(); //“使用了未定义类型”
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::setTextFontColor() {
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->blackRadioBtn->isChecked()) {
        plet.setColor(QPalette::Text, Qt::black);
    } else if(ui->blueRadioBtn->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if(ui->redRadioBtn->isChecked()) {
        plet.setColor(QPalette::Text, Qt::red);
    } else {
        plet.setColor(QPalette::Text, Qt::black);
    }
    ui->plainTextEdit->setPalette(plet);
}

//自动关联信号
void Notepad::on_checkBox_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setItalic(false);
    } else {
        font.setItalic(true);
    }

    ui->plainTextEdit->setFont(font);
}

void Notepad::on_checkBox_2_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setUnderline(false);
    } else {
        font.setUnderline(true);
    }

    ui->plainTextEdit->setFont(font);
}

void Notepad::on_checkBox_3_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setBold(false);
    } else {
        font.setBold(true);
    }

    ui->plainTextEdit->setFont(font);
}
