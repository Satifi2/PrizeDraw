#include "finalrulst.h"
#include<QLabel>
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<mainscene.h>
FinalRulst::FinalRulst(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(889,550);//配置场景
    setWindowIcon(QIcon(":/res/Coin0001.png"));//设置固定大小
    setWindowTitle("抽奖结果");//设置主场景名称
    //设置中奖人
    QLabel *winner    = new QLabel(this);
    winner->setStyleSheet("QLabel {background-color: transparent;}");
    winner->resize(this->width(),this->height());
    winner->move(this->width()*0.25,0);
    winner->show();
    QFont ft;
    ft.setPointSize(100);
    winner->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    winner->setPalette(pa);


    //随机抽取
    QList<QString>namelist={"杜鑫","陈佳卉","朱子轩","朱海文","王健行","郭昱杰","王艺锟","朱子阳","吴东樵","张艺铭","张玉硕","袁倞睿","刘心源","杜怡兴","李想","张凯文","陈冠修","唐瑚","黄俊鹏","朱霞洋","刘松卓","刘雅文","宋先锋","白亚茹","崔子雯","吴嘉豪","庞天傲","李星谊","杜旖芃","刘荟文"};
    QTimer *nametimer=new QTimer;
    nametimer->start(50);
    connect(nametimer,&QTimer::timeout,[=](){
        static int randtimes=0;
        randtimes++;
        if(randtimes<=50){
            winner->setText(namelist[qrand()%30]);
        }
    });

    //返回退出
    MypushButton *backBtn=new MypushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    connect(backBtn,&QPushButton::clicked,[=](){
        //qDebug()<<"点击了button";
        //主场景监听返回按钮
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit this->chooseSceneBack();
        });
    });
}
void FinalRulst::paintEvent(QPaintEvent *){
    QPixmap ResultPic;
    ResultPic.load(":/res/final.png");
    ResultPic=ResultPic.scaled(ResultPic.width()*0.9,ResultPic.height()*0.9);
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),ResultPic);


};//重写画画函数进行画画
