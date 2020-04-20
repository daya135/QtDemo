#include "collection_study.h"
#include <QDebug>

QList<QString> qList;   //相当于Java LinkedList
QVector<QString> qVector;   //相当于Java ArrayList
QStack<QString> qStack;
QQueue<QString> qQueue;
QMap<QString, QString> map;    //有序字典
QHash<QString, QString> hashMap;  //hash字典，更快的查询
QMultiMap<QString, QString> multiMap;  //多值字典
QMultiHash<QString, QString> multiHashMap;    //多值hash字典

void testList() {
    qDebug() << "******************** testList *******************";

    qDebug() << "qList" << qList[0] << qList.at(1) << qList.at(2);  //下标和at(idx)访问列表

//    QList<int> *listA; //错误，这样不会创建对象，会出现运行时异常；
    QList<int> *listA = new QList<int>();   //可以新建对象赋值给指针；
    listA->append(1);   //指针通过“->”引用成员；
    QList<int> listA2 = *listA; //取指针内容赋值给对象；
    listA2.append(2);   //对象可以直接用“.”引用成员；
    QList<int> listB;   //直接声明对象，即可调用无参构造初始化；
    QList<int> *listB2 = &listB;    //取对象地址赋值给指针；
    listB.append(3);
    listB2->append(4);
    qDebug() << "list" << (listA->at(0)) << listA2.at(1) << (listB.at(0)) << listB2->at(1);

}

void testVector() {
    qDebug() << "******************** testVector *******************";
    qVector.append("four");
    qDebug() << qVector[3]; //通过下标访问vector

    qDebug() << "Java QVectorIterator";
    QVectorIterator<QString> i (qVector);
    while(i.hasNext()) {
        qDebug() << i.next();
    }
//    i.toFront(); //移动指针到头部，类似：toBack
//    i.next().remove(); //迭代器可以删除元素，这点与java不一样

    qDebug() << "STL const_iterator";
    QVector<QString>::const_iterator ci;
    for(ci = qVector.constBegin(); ci != qVector.constEnd(); ++ci) {
        qDebug() << *ci;
    }

}

void testQueue() {
    qDebug() << "******************** testQueue *******************";
    while(!qQueue.isEmpty()) {
        qDebug() << qQueue.dequeue();
    }
}

void testStack() {
    qDebug() << "******************** testStack *******************";
    while(!qStack.isEmpty()) {
        qDebug() << qStack.pop();
    }
}

void testMap() {
    map.insert("two", "2");
    map.insert("one", "1");
    map.insert("three", "3");

}

void CollectionStudy::init() {
    qList << "one" << "two" << "three"; //神奇的初始化方式
    qVector << "one" << "two" << "three";
    qQueue << "one" << "two" << "three";
    qStack << "one" << "two" << "three";
}

void CollectionStudy::test() {
    init();
    testList();
    testVector();
    testQueue();
    testStack();
    testMap();
}




