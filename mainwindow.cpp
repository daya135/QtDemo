#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberform.h"
#include "notepad.h"
#include "testform.h"
#include <qdebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  //创建MainWindow实例并赋值给*ui
{
    ui->setupUi(this);
    mainLayout = new QVBoxLayout();
    ui->frame->setLayout(mainLayout);
    connect(ui->exitBtn, SIGNAL(clicked()), this, SLOT(on_exitBtn_clicked()), Qt::UniqueConnection); //因为connect了两次，加上Qt::UniqueConnection，防止触发两次事件
    connect(ui->notepadBtn, SIGNAL(clicked()), this, SLOT(on_notepadBtn_clicked()), Qt::UniqueConnection);
    connect(ui->firstBtn, SIGNAL(clicked()), this, SLOT(on_firstBtn_clicked()), Qt::UniqueConnection);
    connect(ui->testformBtn, SIGNAL(clicked()), this, SLOT(on_testformBtn_clicked()), Qt::UniqueConnection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitBtn_clicked() {
    this->close();
}

void MainWindow::on_notepadBtn_clicked() {
    qDebug() << "on_nodepadBtn_clicked";  
    if (mainLayout->isEmpty()) {
        qDebug() << "addWidget";
    } else {
        qDebug() << "replaceWidget";
        widget->close();
    }
    qDebug() << "Notepad::static_test " <<Notepad::static_test;
    QWidget *newWidget = new Notepad();
    mainLayout->addWidget(newWidget);
    widget = newWidget;
}

void MainWindow::on_firstBtn_clicked() {
    qDebug() << "on_firstBtn_clicked";
    if (mainLayout->isEmpty()) {
        qDebug() << "addWidget";
    } else {
        qDebug() << "replaceWidget";
        widget->close();
    }

    QWidget *newWidget = new NumberForm();
    mainLayout->addWidget(newWidget);
    widget = newWidget;
}

void MainWindow::on_testformBtn_clicked() {
    if (!(mainLayout->isEmpty())) {
        widget->close();
    }
    QWidget *newWidget = new TestForm();
    mainLayout->addWidget(newWidget);
    widget = newWidget;
}


