#include "chooselevelscene.h"
#include<QMenuBar>
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QMovie>
#include<finalrulst.h>
#include<QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(889,550);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("正在抽奖");
//    //设置界面
//    QMenuBar *bar=menuBar();
//    setMenuBar(bar);
//    QMenu *startMenu=bar->addMenu("开始");
//    QAction *quitAction=startMenu->addAction("退出");
//    //实现退出
//    connect(quitAction,&QAction::triggered,[=](){
//        this->close();
//    });
//    MypushButton *backBtn=new MypushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
//    backBtn->setParent(this);
//    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
//    connect(backBtn,&QPushButton::clicked,[=](){
//        //qDebug()<<"点击了button";
//        //主场景监听返回按钮
//        QTimer::singleShot(300,this,[=](){
//            emit this->chooseSceneBack();
//        });
//    });

    //设置动画
    QLabel *mainAnimation=new QLabel(this);
    mainAnimation->setStyleSheet("QLabel {background-color: transparent;}");
    mainAnimation->resize(this->width(),this->height());
    mainAnimation->show();//Label默认显示
    QMovie *mainmovie=new QMovie(":/res/doubleBall2.gif");
    mainAnimation->setMovie(mainmovie);
    mainmovie->start();

    //倒计时显示
    QLabel *TimeCount    = new QLabel(this);
    TimeCount->setStyleSheet("QLabel {background-color: transparent;}");
    TimeCount->setText(" ");
    TimeCount->resize(this->width()*0.5,this->height()*0.5);
    TimeCount->move(this->width()*0.7,this->height()*0.3);
    TimeCount->show();
    QFont ft;
    ft.setPointSize(150);
    TimeCount->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    TimeCount->setPalette(pa);
    //设置倒计时
    QTimer *mytimer=new QTimer(this);
    mytimer->start(1000);
    connect(mytimer,&QTimer::timeout,[=](){
        static int nowtime=3;
        if(nowtime==0){
            FinalRulst *resultScene=new FinalRulst;
            connect(resultScene,&FinalRulst::chooseSceneBack,this,&ChooseLevelScene::chooseSceneBack);
            //进入到结果场景
            QTimer::singleShot(500,this,[=](){
                resultScene->show();
                this->hide();//隐藏场景
                //监听返回信号
            });//延时进入
        }
        if(nowtime>=0) {
            QSound *sound=new QSound(":/res/dingdong.wav",this);
            sound->play();
        }
        TimeCount->setText(QString::number(nowtime--));
    });


}
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
//    pix.load(":/res/OtherSceneBg.png");
//    painter.drawPixmap(0,0,this->width(),this->height()*0.9,pix);

};
