#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QPainter>
#include"chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void paintEvent(QPaintEvent *event);//重写画画函数进行画画
    //该成员函数属于widget,是虚函数

    ChooseLevelScene *chooseScence=NULL;
private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
