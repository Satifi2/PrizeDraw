#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QWidget>
#include<QPainter>
#include<mypushbutton.h>
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:
    //写一个信号让主场景返回
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
