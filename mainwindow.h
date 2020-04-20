#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QWidget>

namespace Ui {
    class MainWindow;
}

/** QWidget类是所有用户界面对象的基类，QMainWindow和QDialog都是QWidget的子类 */
class MainWindow : public QMainWindow
{
    Q_OBJECT    //一个系统定义的宏，定义了一堆东西

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QBoxLayout *mainLayout;
    QWidget *widget;


private slots:
    void on_exitBtn_clicked();
    void on_notepadBtn_clicked();
    void on_firstBtn_clicked(); //与默认的名称冲突,相当于connect了两次
    void on_testformBtn_clicked();
};


#endif // MAINWINDOW_H
