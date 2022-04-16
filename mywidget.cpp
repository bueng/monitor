#include "mywidget.h"
#include<QDebug>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    /*给每个指针变量new一个对象*/
    myvlayout = new QVBoxLayout();
    myhlayout_vedio = new QHBoxLayout();
    myhlayout_button = new QHBoxLayout();
    myButton = new QPushButton("开始或暂停");/*设置开启摄像头的按钮*/

    mycamera = new QCamera();
    myViewfinder = new QCameraViewfinder();


    /*进行布局*/
    mycamera->setViewfinder(myViewfinder);

    myvlayout->addLayout(myhlayout_vedio);
    myvlayout->addLayout(myhlayout_button);

    myhlayout_button->addWidget(myButton);
    myhlayout_vedio->addWidget(myViewfinder);
    this->setLayout(myvlayout);

    /*调整大小*/
    myButton->resize(100,50);
    myButton->move(250,300);
    resize(600,400);

    /*开启摄像头*/
    //mycamera->start();

    /*点击按钮控制相机*/
    QObject::connect(myButton, &QPushButton::clicked, [=](bool) {
            if(this->mycamera->status()==QCamera::ActiveStatus)//判断摄像头是否开启
                this->mycamera->stop();
            else this->mycamera->start();
            qDebug() << "You clicked me!";
        });
}

myWidget::~myWidget()
{
    qDebug()<<"~myWidget().";
}
