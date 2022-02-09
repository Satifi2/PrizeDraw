#include "mainscene.h"
#include "ui_mainscene.h"
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include <QMediaPlayer>
#include<QSound>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //播放音乐
//    QMediaPlayer* player = new QMediaPlayer;
//    player->setMedia(QUrl(":/res/bkmusic.mp3"));//指定源为qrc文件
//    player->setVolume(100);
//    player->play();
    QSound *backgroundsound=new QSound(":/res/BackgroundSound.wav",this);
    backgroundsound->play();

    setFixedSize(889,550);//配置主场景
    setWindowIcon(QIcon(":/res/Coin0001.png"));//设置固定大小
    setWindowTitle("年会抽奖");//设置主场景名称
    connect(ui->actionleave,&QAction::triggered,this,[this](){
       this->close();
    });//退出按钮
    MypushButton*startBtn=new MypushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.55);
    connect(startBtn,&QPushButton::clicked,this,[=](){
        chooseScence=new ChooseLevelScene;
        connect(chooseScence,&ChooseLevelScene::chooseSceneBack,this,[=](){
           chooseScence->hide();
            this->show();
           startBtn->hide();
           MypushButton*endBtn=new MypushButton(":/res/MenuSceneEndButton.png");
           endBtn->setParent(this);
           endBtn->move(this->width()*0.5-endBtn->width()*0.5,this->height()*0.55);
           endBtn->show();
        });//返回设置
        //qDebug()<<"点击成功";
        startBtn->zoomdown();
        //startBtn->zoomup();
        //进入到选择场景
        QTimer::singleShot(500,this,[=](){
            chooseScence->show();
            this->hide();//隐藏主场景
            //监听返回信号
        });//延时进入
    });
}
void MainScene::paintEvent(QPaintEvent *){
    QPixmap BackGroundPic;
    BackGroundPic.load(":/res/MainPic.png");
    BackGroundPic=BackGroundPic.scaled(BackGroundPic.width()*0.9,BackGroundPic.height()*0.9);
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),BackGroundPic);



};
MainScene::~MainScene()
{
    delete ui;
}

