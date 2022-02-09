#ifndef FINALRULST_H
#define FINALRULST_H

#include <QMainWindow>

class FinalRulst : public QMainWindow
{
    Q_OBJECT
public:
    explicit FinalRulst(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);//重写画画函数进行画画
signals:
    void chooseSceneBack();
};

#endif // FINALRULST_H
