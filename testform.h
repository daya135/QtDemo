#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = 0);
    ~TestForm();

private:
    Ui::TestForm *ui;

private slots:
    void on_collectionBtn_clicked();
};

#endif // TESTFORM_H
