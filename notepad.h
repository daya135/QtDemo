#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>

namespace Ui {
class Notepad;
}

class Notepad : public QWidget
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();
    static int static_test;

private:
    Ui::Notepad *ui;
    void testFunc();

private slots:
    void on_checkBox_clicked(bool checked);
    void on_checkBox_2_clicked(bool checked);
    void on_checkBox_3_clicked(bool checked);
    void setTextFontColor();

};

void myFuc_outClas();   //在类外单独定义函数！！

#endif // NOTEPAD_H
