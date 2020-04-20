#ifndef NUMBERFORM_H
#define NUMBERFORM_H

#include <QWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class NumberForm;
}

class NumberForm : public QWidget
{
    Q_OBJECT

public:
    explicit NumberForm(QWidget *parent = 0);
    ~NumberForm();

private:
    Ui::NumberForm *ui;
    QTimer *timer;  //定时器
    QTime timeCounter; //计时器
    void init_timer();

private slots:
    void on_SliderColor_changed(int value);
    void on_dial_changed(int value);
    void on_radioDec_clicked();
    void on_radioOct_clicked();
    void on_radioHex_clicked();
    void on_timer_timeout() ; //定时溢出处理槽函数

};

#endif // NUMBERFORM_H
