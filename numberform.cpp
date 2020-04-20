#include "numberform.h"
#include "ui_numberform.h"
#include <qdebug>
#include <QString>

NumberForm::NumberForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberForm)
{
    ui->setupUi(this);
    init_timer();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
    connect(ui->redSlider, SIGNAL(valueChanged(int)), this, SLOT(on_SliderColor_changed(int)));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), this, SLOT(on_SliderColor_changed(int)));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), this, SLOT(on_SliderColor_changed(int)));
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(on_dial_changed(int)));
    connect(ui->radioBtn_Dec, SIGNAL(clicked(bool)), this, SLOT(on_radioDec_clicked()));
    connect(ui->radioBtn_Oct, SIGNAL(clicked(bool)), this, SLOT(on_radioOct_clicked()));
    connect(ui->radioBtn_Hex, SIGNAL(clicked(bool)), this, SLOT(on_radioHex_clicked()));
}

NumberForm::~NumberForm()
{
    delete ui;
}

void NumberForm::init_timer(){
    timer = new QTimer(this);
    timer->setInterval(1000); //定时间隔，毫秒

    timeCounter.start();
    timer->start();
}

void NumberForm::on_SliderColor_changed(int value) {
    Q_UNUSED(value); //忽略未使用变量的编译器警告
    QColor color;
    int R = ui->redSlider->value();
    int G = ui->greenSlider->value();
    int B = ui->blueSlider->value();
    int alpha = ui->alphaSlider->value();
    color.setRgb(R, G, B, alpha);
    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(palette);
}

void NumberForm::on_timer_timeout() {
    int value = ui->horizonProgressBar->value();
    value ++;
    if (value > ui->horizonProgressBar->maximum()) value = 0;
    ui->horizonProgressBar->setValue(value);
    value = ui->verticalProgressBar->value();
    value ++;
    if (value > ui->verticalProgressBar->maximum()) value = 0;
    ui->verticalProgressBar->setValue(value);

    QTime curTime = QTime::currentTime();
    ui->lcdNumber_hour->display(curTime.hour());
    ui->lcdNumber_min->display(curTime.minute());
    ui->lcdNumber_second->display(curTime.second());

    int tmMsec = timeCounter.elapsed(); //毫秒数
    int sec = tmMsec%60000;
    int min = sec%60;

    QString str = QString::asprintf("%dM %dS", min, sec);
    ui->elapstimelabel->setText(str);

}

void NumberForm::on_dial_changed(int value) {
    ui->lcdNumber->display(value);
    int maxDialValue = ui->dial->maximum();
    float percent = value / (float)maxDialValue; //必须转型一个，否则结果为0
    ui->verticalSlider->setValue((int)(ui->verticalSlider->maximum() * percent));
    ui->verticalScrollBar->setValue((int)(ui->verticalScrollBar->maximum() * percent));
}

void NumberForm::on_radioDec_clicked() {
    ui->lcdNumber->setDigitCount(3);    //设置位数 ui->LCDDisplay->setDecMode();
    ui->lcdNumber->setDecMode();
}

void NumberForm::on_radioOct_clicked() {
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}

void NumberForm::on_radioHex_clicked() {
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}
