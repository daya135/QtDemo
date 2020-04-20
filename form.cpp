#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    /** 手动关联信号与槽函数 */
    connect(ui->blackRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->blueRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(ui->redRadioBtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

Form::~Form()
{
    delete ui;
}

void Form::setTextFontColor() {
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
void Form::on_checkBox_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setItalic(false);
    } else {
        font.setItalic(true);
    }

    ui->plainTextEdit->setFont(font);
}

void Form::on_checkBox_2_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setUnderline(false);
    } else {
        font.setUnderline(true);
    }

    ui->plainTextEdit->setFont(font);
}

void Form::on_checkBox_3_clicked(bool checked)
{

    QFont font = ui->plainTextEdit->font();
    if (false == checked) {
        font.setBold(false);
    } else {
        font.setBold(true);
    }

    ui->plainTextEdit->setFont(font);
}
