#include "testform.h"
#include "ui_testform.h"
#include "collection_study.h"

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);
}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::on_collectionBtn_clicked() {
    CollectionStudy study;  //这样就算调用无参构造函数了。。
    study.test();
}
