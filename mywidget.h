#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QCamera>
#include <QCameraViewfinder>


class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();

public:
    QPushButton *myButton;/*添加按钮*/
    QHBoxLayout *myhlayout_vedio;/*添加下面的水平居中布局*/
    QHBoxLayout *myhlayout_button;
    QVBoxLayout *myvlayout;/*垂直布局*/

    /*------------------------------*/
    QCamera *mycamera;/*摄像头对象*/
    QCameraViewfinder *myViewfinder;/*用于实时显示摄像头对象*/

    /*------------------------------*/

};

#endif // MYWIDGET_H
