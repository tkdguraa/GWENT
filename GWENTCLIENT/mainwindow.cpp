#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include "card.h"
#include <iostream>
#include <QLCDNumber>
#include <QMessageBox>
#include <stdlib.h>
#include <QDebug>
//1200,800 默认背景大小
//150，200 卡牌默认大小
//重整：随机打出一张铜卡
//T1 金 T2银 T3铜 T4 leader
//job,战场位置1，2，3。 4任意，5指魔法,6对面任意。
//quality 属性 1： 佚亡   5:佚亡，坚守。 0：无。
//ability 特殊效果
//where 0:不在手中  1:手中    2:场上      3:目的中  4:排除游戏外
int count=0;
int check=0;
double gold=0;
int silver=0;
double bronze=0;
int leader=0;
int os=0;
int rs=0;
int tp1=0;
int tp2=0;
int tp3=0;
int draw=0;
int Mysabertotal=0;
int Myarchertotal=0;
int Myridertotal=0;
int Mytotal=0;
int Myhandnum=50;
int OPsabertotal=0;
int OParchertotal=0;
int OPridertotal=0;
int OPtotal=0;
int howmany=0;
int savemos[50]={0};
int irin=0;
int sure=0;
int turn=3; //1
int giveupserver=0;
int giveupclient=0;
int jud=0;
int win=0;
int lose=0;
int tempsave;
int OPcardnum=0;
int ft=0;
int sw[3]={0};
int OPsw[3]={0};
int mk=0;
//信号a:手牌，牌组 b:点击我的第一排 c:点击我的第二排  d:点击我的第三排
//QString name="",int attack=0,int num=0,int T=0,int id=0,int job=0,int quality=0,QString path="",int ability=0
Card a("破晓",0,0,3,0,7,0,"QPushButton{border-image: url(:/new/img/破晓.png);}",0,0);//
Card b("刺骨冰霜",0,0,3,1,5,0,"QPushButton{border-image: url(:/new/img/刺骨冰霜.png);}",0,0);//
Card c("蔽日浓雾",0,0,3,2,5,0,"QPushButton{border-image: url(:/new/img/蔽日浓雾.png);}",0,0);//
Card d("倾盆大雨",0,0,3,3,5,0,"QPushButton{border-image: url(:/new/img/倾盆大雨.png);}",0,0);//
Card e("撕裂",0,0,3,4,4,0,"QPushButton{border-image: url(:/new/img/撕裂.png);}",0);//
Card f("指挥号角",0,0,2,5,4,0,"QPushButton{border-image: url(:/new/img/指挥号角.png);}",0);//
Card g("贝克尔的扭曲之镜",0,0,2,6,4,0,"QPushButton{border-image: url(:/new/img/贝克尔的扭曲之镜.png);}",0,0);//
Card h("杰洛特：伊格尼法印",5,0,1,7,4,1,"QPushButton{border-image: url(:/new/img/杰洛特：伊格尼法印.png);}",0,0);//
Card i("达冈",6,0,4,8,4,5,"QPushButton{border-image: url(:/new/img/达冈.png);}",0,0);//
Card j("小雾妖",4,0,3,9,4,0,"QPushButton{border-image: url(:/new/img/小雾妖.png);}",0,0);//
Card k("盖尔",1,0,1,10,4,0,"QPushButton{border-image: url(:/new/img/盖尔.png);}",0,0);//
Card l("赛尔伊诺鹰身女妖",5,0,3,11,4,0,"QPushButton{border-image: url(:/new/img/赛尔伊诺鹰身女妖.png);}",0,0);//
Card m("林妖",5,0,1,12,4,0,"QPushButton{border-image: url(:/new/img/林妖.png);}",0,0);//
Card n("土元素",6,0,3,13,1,0,"QPushButton{border-image: url(:/new/img/土元素.png);}",0,0);//
Card o("老巫妪:织婆",6,0,2,14,3,0,"QPushButton{border-image: url(:/new/img/老巫妪织婆.png);}",0,0);//
Card p("老巫妪:呢喃婆",6,0,2,15,3,0,"QPushButton{border-image: url(:/new/img/老巫妪呢喃婆.png);}",0,0);//
Card q("老巫妪:煮婆",8,0,2,16,3,0,"QPushButton{border-image: url(:/new/img/老巫妪煮婆.png);}",0,0);//
Card r("大狮鹫",8,0,3,17,4,0,"QPushButton{border-image: url(:/new/img/大狮鹫.png);}",0,0);//
Card s("卡兰希尔",8,0,1,18,4,0,"QPushButton{border-image: url(:/new/img/卡兰希尔.png);}",0,0);//
Card t("畏惧者",12,0,2,19,6,1,"QPushButton{border-image: url(:/new/img/畏惧者.png);}",0,0);//
Card u("暗影长者",5,0,4,20,4,5,"QPushButton{border-image: url(:/new/img/暗影长者.png);}",0,0);//
Card v("蟹蜘蛛",3,0,3,21,2,0,"QPushButton{border-image: url(:/new/img/蟹蜘蛛.png);}",0,0);//
Card w("蜥蜴人战士",6,0,3,22,4,0,"QPushButton{border-image: url(:/new/img/蜥蜴人战士.png);}",0,0);//
Card aa("蟹蜘蛛巨兽",6,0,3,23,3,0,"QPushButton{border-image: url(:/new/img/蟹蜘蛛巨兽.png);}",0,0);//
Card ab("雷霆药水",0,0,3,24,4,0,"QPushButton{border-image: url(:/new/img/雷霆药水.png);}",0,0);//
Card ac("萝卜",4,0,2,25,4,0,"QPushButton{border-image: url(:/new/img/萝卜.png);}",0,0);//
Card ad("狂猎骑士",8,0,3,26,4,0,"QPushButton{border-image: url(:/new/img/狂猎骑士.png);}",0,0);//
Card ae("鹰身女妖蛋",1,0,3,27,4,0,"QPushButton{border-image: url(:/new/img/鹰身女妖蛋.png);}",0,0);
Card af("次级土元素",2,0,3,27,4,0,"QPushButton{border-image: url(:/new/img/次级土元素.png);}",0,0);
Card Deck[40];
Card save1;
Card save2;
Card temp;
Card Hand[11];
Card ShouLing;
Card ingametemp;
Card jiwo;
Card Mysaber[5];
Card Myarcher[5];
Card Myrider[5];
Card OPsaber[5];
Card OParcher[5];
Card OPrider[5];
Card imsi;
//连网
Card Myweather[3];
Card OPweather[3];
Card OPDeck[40];
Card OPtemp;
Card OPShouLing;
Card OPingametemp;
Card OPHand[11];//OPHand 十张，首领不算在内
QString savecardnum="";
//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->stackedWidget);
     setWindowTitle("GWENT client");
    ui->page_2->setStyleSheet("#page_2{border-image: url(:/new/img/Menu.jpg);}");
    ui->page_3->setStyleSheet("#page_3{border-image: url(:/new/img/redraw.jpg);}");
    ui->page_4->setStyleSheet("#page_4{border-image: url(:/new/img/battleground.jpg);}");
    ui->Job->setStyleSheet("QLabel{border-image: url(:/new/img/saber.jpg);}");
    ui->Job_2->setStyleSheet("QLabel{border-image: url(:/new/img/archer.jpg);}");
    ui->Job_3->setStyleSheet("QLabel{border-image: url(:/new/img/rider.jpg);}");
    ui->OPJob->setStyleSheet("QLabel{border-image: url(:/new/img/saber.jpg);}");
    ui->OPJob_2->setStyleSheet("QLabel{border-image: url(:/new/img/archer.jpg);}");
    ui->OPJob_3->setStyleSheet("QLabel{border-image: url(:/new/img/rider.jpg);}");
    ui->explain->setStyleSheet("QLabel{border-image: url(:/new/img/rider.jpg);}");

    ui->bronze->setStyleSheet("QLabel{border-image: url(:/new/img/bronze.JPG);}");
    ui->silver->setStyleSheet("QLabel{border-image: url(:/new/img/silver.JPG);}");
    ui->gold->setStyleSheet("QLabel{border-image: url(:/new/img/gold.JPG);}");
    ui->leader->setStyleSheet("QLabel{border-image: url(:/new/img/leader.JPG);}");
    ui->page_6->setStyleSheet("#page_6{border-image: url(:/new/img/Scorepage.jpg);}");
    ui->page_5->setStyleSheet("background-color:white;");
    ui->makecardpicture->setStyleSheet("background-color:white;");
    ui->selectCard->setStyleSheet(a.path);
    ui->selectCard_2->setStyleSheet(b.path);
    ui->selectCard_3->setStyleSheet(c.path);
    ui->selectCard_4->setStyleSheet(d.path);
    ui->selectCard_5->setStyleSheet(e.path);
    ui->selectCard_6->setStyleSheet(f.path);
    ui->selectCard_7->setStyleSheet(g.path);
    ui->selectCard_8->setStyleSheet(h.path);
    ui->selectCard_9->setStyleSheet(i.path);
    ui->selectCard_10->setStyleSheet(j.path);
    ui->selectCard_11->setStyleSheet(k.path);
    ui->selectCard_12->setStyleSheet(l.path);
    ui->selectCard_13->setStyleSheet(m.path);
    ui->selectCard_14->setStyleSheet(n.path);
    ui->selectCard_15->setStyleSheet(o.path);
    ui->selectCard_16->setStyleSheet(p.path);
    ui->selectCard_17->setStyleSheet(q.path);
    ui->selectCard_18->setStyleSheet(r.path);
    ui->selectCard_19->setStyleSheet(s.path);
    ui->selectCard_20->setStyleSheet(t.path);
    ui->selectCard_21->setStyleSheet(u.path);
    ui->selectCard_22->setStyleSheet(v.path);
    ui->selectCard_23->setStyleSheet(w.path);
    ui->selectCard_24->setStyleSheet(aa.path);
    ui->selectCard_25->setStyleSheet(ab.path);
    ui->selectCard_26->setStyleSheet(ac.path);
    ui->selectCard_27->setStyleSheet(ad.path);
    ui->OPHand->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_2->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_3->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_4->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_5->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_6->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_7->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_8->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_9->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_10->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");
    ui->OPHand_11->setStyleSheet("QPushButton{border-image: url(:/new/img/cardback.jpg);}");



            // a[0]=A;
   //ui->explain->setText(a[0].name);
    ui->stackedWidget->setCurrentWidget(ui->page);
    OPBtn[0]=ui->OPHand;
    OPBtn[1]=ui->OPHand_2;
    OPBtn[2]=ui->OPHand_3;
    OPBtn[3]=ui->OPHand_4;
    OPBtn[4]=ui->OPHand_5;
    OPBtn[5]=ui->OPHand_6;
    OPBtn[6]=ui->OPHand_7;
    OPBtn[7]=ui->OPHand_8;
    OPBtn[8]=ui->OPHand_9;
    OPBtn[9]=ui->OPHand_10;
    OPBtn[10]=ui->OPHand_11;


    OPW[0]=ui->OPweather;
    OPW[1]=ui->OPweather_2;
    OPW[2]=ui->OPweather_3;

    MW[0]=ui->Myweather;
    MW[1]=ui->Myweather_2;
    MW[2]=ui->Myweather_3;

    Btn[0] = ui->decklist;
    Btn[1] = ui->decklist_2;
    Btn[2] = ui->decklist_3;
    Btn[3] = ui->decklist_4;
    Btn[4] = ui->decklist_5;
    Btn[5] = ui->decklist_6;
    Btn[6] = ui->decklist_7;
    Btn[7] = ui->decklist_8;
    Btn[8] = ui->decklist_9;
    Btn[9] = ui->decklist_10;
    Btn[10] = ui->decklist_11;
    Btn[11] = ui->decklist_12;
    Btn[12] = ui->decklist_13;
    Btn[13] = ui->decklist_14;
    Btn[14] = ui->decklist_15;
    Btn[15] = ui->decklist_16;
    Btn[16] = ui->decklist_17;
    Btn[17] = ui->decklist_18;
    Btn[18] = ui->decklist_19;
    Btn[19] = ui->decklist_20;
    Btn[20] = ui->decklist_21;
    Btn[21] = ui->decklist_22;
    Btn[22] = ui->decklist_23;
    Btn[23] = ui->decklist_24;
    Btn[24] = ui->decklist_25;
    Btn[25] = ui->decklist_26;
    Btn[26] = ui->decklist_27;
    Btn[27] = ui->decklist_28;
    Btn[28] = ui->decklist_29;
    Btn[29] = ui->decklist_30;
    Btn[30] = ui->decklist_31;
    Btn[31] = ui->decklist_32;
    Btn[32] = ui->decklist_33;
    Btn[33] = ui->decklist_34;
    Btn[34] = ui->decklist_35;
    Btn[35] = ui->decklist_36;
    Btn[36] = ui->decklist_37;
    Btn[37] = ui->decklist_38;
    Btn[38] = ui->decklist_39;
    Btn[39] = ui->decklist_40;

    redrawBtn[0]=ui->redraw;
    redrawBtn[1]=ui->redraw_2;
    redrawBtn[2]=ui->redraw_3;
    redrawBtn[3]=ui->redraw_4;
    redrawBtn[4]=ui->redraw_5;
    redrawBtn[5]=ui->redraw_6;
    redrawBtn[6]=ui->redraw_7;
    redrawBtn[7]=ui->redraw_8;
    redrawBtn[8]=ui->redraw_9;
    redrawBtn[9]=ui->redraw_10;
    MH[0]=ui->Myhand;
    MH[1]=ui->Myhand_2;
    MH[2]=ui->Myhand_3;
    MH[3]=ui->Myhand_4;
    MH[4]=ui->Myhand_5;
    MH[5]=ui->Myhand_6;
    MH[6]=ui->Myhand_7;
    MH[7]=ui->Myhand_8;
    MH[8]=ui->Myhand_9;
    MH[9]=ui->Myhand_10;
    MH[10]=ui->Myhand_11;




    msgbox.setInformativeText(tr("卡牌数不够（25~40）,不算首领"));
    SangE.setInformativeText("redraw完毕，点击finish");
    NoShouLing.setInformativeText("无首领");
    ML1[0]=ui->MyLine1;
    ML1[1]=ui->MyLine1_2;
    ML1[2]=ui->MyLine1_3;
    ML1[3]=ui->MyLine1_4;
    ML1[4]=ui->MyLine1_5;
    ML2[0]=ui->MyLine2;
    ML2[1]=ui->MyLine2_2;
    ML2[2]=ui->MyLine2_3;
    ML2[3]=ui->MyLine2_4;
    ML2[4]=ui->MyLine2_5;
    ML3[0]=ui->MyLine3;
    ML3[1]=ui->MyLine3_2;
    ML3[2]=ui->MyLine3_3;
    ML3[3]=ui->MyLine3_4;
    ML3[4]=ui->MyLine3_5;

    OPL1[0]=ui->OPLine1;
    OPL1[1]=ui->OPLine1_2;
    OPL1[2]=ui->OPLine1_3;
    OPL1[3]=ui->OPLine1_4;
    OPL1[4]=ui->OPLine1_5;

    OPL2[0]=ui->OPLine2;
    OPL2[1]=ui->OPLine2_2;
    OPL2[2]=ui->OPLine2_3;
    OPL2[3]=ui->OPLine2_4;
    OPL2[4]=ui->OPLine2_5;

    OPL3[0]=ui->OPLine3;
    OPL3[1]=ui->OPLine3_2;
    OPL3[2]=ui->OPLine3_3;
    OPL3[3]=ui->OPLine3_4;
    OPL3[4]=ui->OPLine3_5;


    exppc[0]="QPushButton{border-image: url(:/new/img/1.JPG);}";
    exppc[1]="QPushButton{border-image: url(:/new/img/2.JPG);}";
    exppc[2]="QPushButton{border-image: url(:/new/img/3.JPG);}";
    exppc[3]="QPushButton{border-image: url(:/new/img/4.JPG);}";
    exppc[4]="QPushButton{border-image: url(:/new/img/5.JPG);}";
    exppc[5]="QPushButton{border-image: url(:/new/img/6.JPG);}";
    exppc[6]="QPushButton{border-image: url(:/new/img/7.JPG);}";
    exppc[7]="QPushButton{border-image: url(:/new/img/8.JPG);}";
    exppc[8]="QPushButton{border-image: url(:/new/img/9.JPG);}";
    exppc[9]="QPushButton{border-image: url(:/new/img/10.JPG);}";
    exppc[10]="QPushButton{border-image: url(:/new/img/11.JPG);}";
    exppc[11]="QPushButton{border-image: url(:/new/img/12.JPG);}";
    exppc[12]="QPushButton{border-image: url(:/new/img/13.JPG);}";
    exppc[13]="QPushButton{border-image: url(:/new/img/14.JPG);}";
    exppc[14]="QPushButton{border-image: url(:/new/img/15.JPG);}";
    exppc[15]="QPushButton{border-image: url(:/new/img/16.JPG);}";
    exppc[16]="QPushButton{border-image: url(:/new/img/17.JPG);}";
    exppc[17]="QPushButton{border-image: url(:/new/img/18.JPG);}";
    exppc[18]="QPushButton{border-image: url(:/new/img/19.JPG);}";
    exppc[19]="QPushButton{border-image: url(:/new/img/20.JPG);}";
    exppc[20]="QPushButton{border-image: url(:/new/img/21.JPG);}";
    exppc[21]="QPushButton{border-image: url(:/new/img/22.JPG);}";
    exppc[22]="QPushButton{border-image: url(:/new/img/23.JPG);}";
    exppc[23]="QPushButton{border-image: url(:/new/img/24.JPG);}";
    exppc[24]="QPushButton{border-image: url(:/new/img/25.JPG);}";
    exppc[25]="QPushButton{border-image: url(:/new/img/26.JPG);}";
    exppc[26]="QPushButton{border-image: url(:/new/img/27.JPG);}";
    ui->leaderbutton->setStyleSheet("background-color:grey;");
}

//leader->hand->deck,0:leader,1~10:hand,howmany-10:deck

void MainWindow::connectHost()
{
    this->readWriteSocket = new QTcpSocket;
    this->readWriteSocket->connectToHost(QHostAddress("127.0.0.1"),8888);
    QObject::connect(this->readWriteSocket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
}



void MainWindow::recvMessage()
{
    QString info;
    QString space=" ";
    info += this->readWriteSocket->readAll();
    char str[100][100]={NULL};
     char *str1= new char[1000];
    QByteArray ba = info.toLatin1();
    str1=ba.data();

      if(info[info.length()-1]=="a")
    {
        for(int iu=0;iu<info.length();iu++)
        {
            str[howmany][irin]=str1[iu];
            irin++;
            if(info[iu]==" ")
            {
                howmany++;
                irin=0;
            }

        }

        for(int iu=0;iu<howmany;iu++)
        {
            int temp = 0;
            temp = atoi(str[iu]);
            savemos[iu]=temp;

        }
        if(savemos[0]==8)
            OPHand[10]=i;
        if(savemos[0]==20)
            OPHand[10]=u;
        for(int iu=1;iu<11;iu++)
        {
        if(savemos[iu]==0)
            OPHand[iu-1]=a;
        if(savemos[iu]==1)
            OPHand[iu-1]=b;
        if(savemos[iu]==2)
           OPHand[iu-1]=c;
        if(savemos[iu]==3)
          OPHand[iu-1]=d;
        if(savemos[iu]==4)
           OPHand[iu-1]=e;
        if(savemos[iu]==5)
           OPHand[iu-1]=f;
        if(savemos[iu]==6)
           OPHand[iu-1]=g;
        if(savemos[iu]==7)
            OPHand[iu-1]=h;
        if(savemos[iu]==8)
           OPHand[iu-1]=i;
        if(savemos[iu]==9)
            OPHand[iu-1]=j;
        if(savemos[iu]==10)
            OPHand[iu-1]=k;
        if(savemos[iu]==11)
          OPHand[iu-1]=l;
        if(savemos[iu]==12)
            OPHand[iu-1]=m;
        if(savemos[iu]==13)
            OPHand[iu-1]=n;
        if(savemos[iu]==14)
            OPHand[iu-1]=o;
        if(savemos[iu]==15)
           OPHand[iu-1]=p;
        if(savemos[iu]==16)
            OPHand[iu-1]=q;
        if(savemos[iu]==17)
            OPHand[iu-1]=r;
        if(savemos[iu]==18)
            OPHand[iu-1]=s;
        if(savemos[iu]==19)
            OPHand[iu-1]=t;
        if(savemos[iu]==20)
            OPHand[iu-1]=u;
        if(savemos[iu]==21)
            OPHand[iu-1]=v;
        if(savemos[iu]==22)
            OPHand[iu-1]=w;
        if(savemos[iu]==23)
            OPHand[iu-1]=aa;
        if(savemos[iu]==24)
            OPHand[iu-1]=ab;
        if(savemos[iu]==25)
            OPHand[iu-1]=ac;
        if(savemos[iu]==26)
            OPHand[iu-1]=ad;
        }
        for(int iu=11;iu<howmany;iu++)
        {
            if(savemos[iu]==0)
                OPDeck[iu-11]=a;
            if(savemos[iu]==1)
                OPDeck[iu-11]=b;
            if(savemos[iu]==2)
               OPDeck[iu-11]=c;
            if(savemos[iu]==3)
              OPDeck[iu-11]=d;
            if(savemos[iu]==4)
               OPDeck[iu-11]=e;
            if(savemos[iu]==5)
               OPDeck[iu-11]=f;
            if(savemos[iu]==6)
               OPDeck[iu-11]=g;
            if(savemos[iu]==7)
                OPDeck[iu-11]=h;
            if(savemos[iu]==8)
               OPDeck[iu-11]=i;
            if(savemos[iu]==9)
                OPDeck[iu-11]=j;
            if(savemos[iu]==10)
                OPDeck[iu-11]=k;
            if(savemos[iu]==11)
              OPDeck[iu-11]=l;
            if(savemos[iu]==12)
                OPDeck[iu-11]=m;
            if(savemos[iu]==13)
                OPDeck[iu-11]=n;
            if(savemos[iu]==14)
                OPDeck[iu-11]=o;
            if(savemos[iu]==15)
               OPDeck[iu-11]=p;
            if(savemos[iu]==16)
                OPDeck[iu-11]=q;
            if(savemos[iu]==17)
                OPDeck[iu-11]=r;
            if(savemos[iu]==18)
                OPDeck[iu-11]=s;
            if(savemos[iu]==19)
                OPDeck[iu-11]=t;
            if(savemos[iu]==20)
                OPDeck[iu-11]=u;
            if(savemos[iu]==21)
                OPDeck[iu-11]=v;
            if(savemos[iu]==22)
                OPDeck[iu-11]=w;
            if(savemos[iu]==23)
                OPDeck[iu-11]=aa;
            if(savemos[iu]==24)
                OPDeck[iu-11]=ab;
            if(savemos[iu]==25)
                OPDeck[iu-11]=ac;
            if(savemos[iu]==26)
                OPDeck[iu-11]=ad;
        }
        for(int iu=0;iu<10;iu++)
            OPDeck[iu].where=1;
        OPcardnum=howmany;
        howmany=0;
        irin=0;
    }
        if(info[info.length()-1]=="b")//savemos[0]=ioi//手牌，savemos[1]=iu第几列
        {
                for(int iu=0;iu<info.length();iu++)
                {
                    str[howmany][irin]=str1[iu];
                    irin++;
                    if(info[iu]==" ")
                    {
                        howmany++;
                        irin=0;
                    }

                }
                    for(int iu=0;iu<howmany;iu++)
                {
                    int temp = 0;
                    temp = atoi(str[iu]);
                    savemos[iu]=temp;
                }
               OPBtn[savemos[0]]->setVisible(false);
            updateline1(savemos[1],savemos[0]);

            howmany=0;
            irin=0;
        }
        if(info[info.length()-1]=="c")//savemos[0]=ioi//手牌，savemos[1]=iu第几列
        {

                for(int iu=0;iu<info.length();iu++)
                {
                    str[howmany][irin]=str1[iu];
                    irin++;
                    if(info[iu]==" ")
                    {
                        howmany++;
                        irin=0;
                    }

                }
                    for(int iu=0;iu<howmany;iu++)
                {
                    int temp = 0;
                    temp = atoi(str[iu]);
                    savemos[iu]=temp;
                }
               OPBtn[savemos[0]]->setVisible(false);
            updateline2(savemos[1],savemos[0]);

            howmany=0;
            irin=0;
        }
        if(info[info.length()-1]=="d")//savemos[0]=ioi//手牌，savemos[1]=iu第几列
        {
                for(int iu=0;iu<info.length();iu++)
                {
                    str[howmany][irin]=str1[iu];
                    irin++;
                    if(info[iu]==" ")
                    {
                        howmany++;
                        irin=0;
                    }

                }
                    for(int iu=0;iu<howmany;iu++)
                {
                    int temp = 0;
                    temp = atoi(str[iu]);
                    savemos[iu]=temp;
                }
               OPBtn[savemos[0]]->setVisible(false);
            updateline3(savemos[1],savemos[0]);

            howmany=0;
            irin=0;
        }

        if(info[info.length()-1]=="e")//比赛开始前判断先后
        {
            if(info[0]=="0")
                jud=0;
            if(info[0]=="1")
                jud=1;
        }
        if(info[info.length()-1]=="f")
        {
            jud++;
        }
        if(info[info.length()-1]=="g")//savemos[0]=ioi//手牌，savemos[1]=iu第几列
        {
                for(int iu=0;iu<info.length();iu++)
                {
                    str[howmany][irin]=str1[iu];
                    irin++;
                    if(info[iu]==" ")
                    {
                        howmany++;
                        irin=0;
                    }

                }
                    for(int iu=0;iu<howmany;iu++)
                {
                    int temp = 0;
                    temp = atoi(str[iu]);
                    savemos[iu]=temp;
                }
               OPBtn[savemos[0]]->setVisible(false);
            updateweather(savemos[1],savemos[0]);

            howmany=0;
            irin=0;
        }
        if(info[info.length()-1]=="h")
        {
            tempsave=1;
          }



}



void MainWindow::paintEvent(QPaintEvent *event)
{
    ui->T1number->display(gold);
    ui->T2number->display(silver);
    ui->T3number->display(bronze);
    ui->T4number->display(leader);
    ui->MyScore1->display(Mysabertotal);
    ui->MyScore2->display(Myarchertotal);
    ui->MyScore3->display(Myridertotal);
    ui->MyTotal->display(Mytotal);
    ui->OPScore1->display(OPsabertotal);
    ui->OPScore2->display(OParchertotal);
    ui->OPScore3->display(OPridertotal);
    ui->OPTotal->display(OPtotal);

    ui->MT->display(sw[0]);
    ui->OPT->display(OPsw[0]);
    ui->MT_2->display(sw[1]);
    ui->OPT_2->display(OPsw[1]);
    ui->MT_3->display(sw[2]);
    ui->OPT_3->display(OPsw[2]);
    ui->Mysetscore->display(win);
    ui->OPsetscore->display(lose);
    giveupserver=tempsave;

    turn=jud%2;

    if(giveupclient==1&&giveupserver==1&&ft==0)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_6);
        sw[mk]=Mytotal;
        OPsw[mk]=OPtotal;
        if(Mytotal>OPtotal)
            win++;
        if(Mytotal<OPtotal)
            lose++;
            mk++;
            if(win==2)
              ui->winorlose->setStyleSheet("QLabel{border-image: url(:/new/img/win.JPG);}");
            if(lose==2)
              ui->winorlose->setStyleSheet("QLabel{border-image: url(:/new/img/lose.JPG);}");
            ft=1;
         Mytotal=OPtotal=0;
        giveupclient==0,giveupserver=0;
    }
    if(giveupserver==1&&turn==0)
    {
        turn=1;
    }
    if(giveupserver!=1&&giveupclient==1)
    {
        turn=0;
    }

    if(turn==1)
    {
        ui->whoseturn->setText("My Turn");
        QFont ft;
        ft.setPointSize(15);
        ui->whoseturn->setFont(ft);
        //设置颜色
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->whoseturn->setPalette(pa);
    }

    if(turn==0)
    {
        ui->whoseturn->setText("Oppenent");
        QFont ft;
        ft.setPointSize(15);
        ui->whoseturn->setFont(ft);
        //设置颜色
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->whoseturn->setPalette(pa);
    }
    if(ingametemp.job==0)
        for(int iu=0;iu<5;iu++)
        {
         if(Mysaber[iu].where!=2)
         {
             ML1[iu]->setStyleSheet("");
         }
         if(Myarcher[iu].where!=2)
         {
             ML2[iu]->setStyleSheet("");
         }
         if(Myrider[iu].where!=2)
         {
              ML3[iu]->setStyleSheet("");
         }
         for(int iu=0;iu<5;iu++)
         {
          if(OPsaber[iu].where!=2)
          {
              OPL1[iu]->setStyleSheet("");
          }
          if(OParcher[iu].where!=2)
          {
              OPL2[iu]->setStyleSheet("");
          }
          if(OPrider[iu].where!=2)
          {
               OPL3[iu]->setStyleSheet("");
          }
        }
         for(int iu=0;iu<3;iu++)
         {
             if(Myweather[iu].where!=2)
             {
                 MW[iu]->setStyleSheet("");
             }
             if(OPweather[iu].where!=2)
             {
                 OPW[iu]->setStyleSheet("");
             }

         }

    QString sp1;
    QString sp2;
    QString sp3;
    QString OPsp1;
    QString OPsp2;
    QString OPsp3;
    QPalette   pal;
    for(int iu=0;iu<5;iu++)
    {
        pal.setColor(QPalette::ButtonText, QColor(255,0,0));
        ML1[iu]->setPalette(pal);
        ML2[iu]->setPalette(pal);
        ML3[iu]->setPalette(pal);
        long a = Mysaber[iu].attack;
        sp1=QString::number(a, 10);

        long b = Myarcher[iu].attack;
        sp2=QString::number(b,10);
        long c = Myrider[iu].attack;
        sp3=QString::number(c,10);
        if(Mysaber[iu].where==2)
            ML1[iu]->setText(sp1);
        if(Myarcher[iu].where==2)
            ML2[iu]->setText(sp2);
        if(Myrider[iu].where==2)
            ML3[iu]->setText(sp3);
        if(Mysaber[iu].where==0)
            ML1[iu]->setText("");
        if(Myarcher[iu].where==0)
            ML2[iu]->setText("");
        if(Myrider[iu].where==0)
            ML3[iu]->setText("");
    }
    for(int iu=0;iu<5;iu++)
    {
        pal.setColor(QPalette::ButtonText, QColor(255,0,0));
        OPL1[iu]->setPalette(pal);
        OPL2[iu]->setPalette(pal);
        OPL3[iu]->setPalette(pal);
        long a = OPsaber[iu].attack;
        OPsp1=QString::number(a, 10);

        long b = OParcher[iu].attack;
        OPsp2=QString::number(b,10);

        long c = OPrider[iu].attack;
        OPsp3=QString::number(c,10);
        if(OPsaber[iu].where==2)
            OPL1[iu]->setText(OPsp1);
        if(OParcher[iu].where==2)
            OPL2[iu]->setText(OPsp2);
        if(OPrider[iu].where==2)
            OPL3[iu]->setText(OPsp3);
        if(OPsaber[iu].where==0)
            OPL1[iu]->setText("");
        if(OParcher[iu].where==0)
            OPL2[iu]->setText("");
        if(OPrider[iu].where==0)
            OPL3[iu]->setText("");
    }
}}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);

}

void MainWindow::on_finish_clicked()
{
    QString savecard="";
    QString space=" ";

    giveupclient=giveupserver=0;
    tempsave=3;

    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->Myhand->setStyleSheet(ShouLing.path);
    ui->Myhand_2->setStyleSheet(Hand[0].path);
    ui->Myhand_3->setStyleSheet(Hand[1].path);
    ui->Myhand_4->setStyleSheet(Hand[2].path);
    ui->Myhand_5->setStyleSheet(Hand[3].path);
    ui->Myhand_6->setStyleSheet(Hand[4].path);
    ui->Myhand_7->setStyleSheet(Hand[5].path);
    ui->Myhand_8->setStyleSheet(Hand[6].path);
    ui->Myhand_9->setStyleSheet(Hand[7].path);
    ui->Myhand_10->setStyleSheet(Hand[8].path);
    ui->Myhand_11->setStyleSheet(Hand[9].path);
    for(int iu=0;iu<10;iu++)
    {
       Hand[iu].where=1;
    }
    long tempo = ShouLing.id;
    savecard= QString::number(tempo, 10);
    savecard= savecard +space;

    for(int iu=0;iu<10;iu++)
    {
        long tempo = Hand[iu].id;
        savecard = savecard+QString::number(tempo,10);
        savecard = savecard+space;
    }

    for(int iu=0;iu<count-10;iu++)
    {
        long tempo = Deck[iu].id;
        savecard = savecard+QString::number(tempo, 10);
        savecard = savecard+space;
    }
    savecard=savecard+"a";
    QByteArray *array = new QByteArray;
    array->clear();
    array->append(savecard);
    this->readWriteSocket->write(array->data());
}


void MainWindow::on_Start_clicked()
{
    if(count<25)
    msgbox.show();
    if(leader==0)
        NoShouLing.show();
    if(count>=11&&leader==1)//要记得修改成25！！
    {
        srand(time(NULL));
        for(int ak=0;ak<100;ak++)
        {
              tp1=rand()%count;
              tp2=rand()%count;
              save1=Deck[tp1];
              Deck[tp1]=Deck[tp2];
              Deck[tp2]=save1;
        }
        for(int ak=0;ak<10;ak++)
        {
            Hand[ak]=Deck[ak];
            redrawBtn[ak]->setStyleSheet(Hand[ak].path);
        }
        for(int ak=0;ak<30;ak++)
        {
            Deck[ak]=Deck[ak+10];
        }

        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }}


void MainWindow::on_Deck_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_5);
}


void MainWindow::on_selectCard_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[0]);
    temp=a;
}

void MainWindow::on_makecardpicture_clicked()
{
    if(count<40&&temp.T==3&&temp.num<3)
    {
        Btn[count]->setText(temp.name);
        Deck[count]=temp;
        temp.num++;
        if(temp.id==3)
        {
            d=temp;
        }
        if(temp.id==0)
        {
            a=temp;
        }
        if(temp.id==1)
        {
            b=temp;
        }
        if(temp.id==2)
        {
            c=temp;
        }
        if(temp.id==4)
        {
            e=temp;
        }

        if(temp.id==9)
        {
            j=temp;
        }
        if(temp.id==11)
        {
            l=temp;
        }
        if(temp.id==13)
        {
            n=temp;
        }
        if(temp.id==17)
        {
            r=temp;
        }
        if(temp.id==21)
        {
            v=temp;
        }
        if(temp.id==22)
        {
            w=temp;
        }
        if(temp.id==23)
        {
            aa=temp;
        }
        if(temp.id==24)
        {
            ab=temp;
        }
        if(temp.id==25)
        {
            ac=temp;
        }
        if(temp.id==26)
        {
            ad=temp;
        }
        count++;
        bronze++;
        ui->T1number->display(gold);
    }
    if(count<=40&&temp.T==2&&temp.num<1&&silver<6)
    {
    Btn[count]->setText(temp.name);
    Deck[count]=temp;
    temp.num++;
        if(temp.id==14)
        {
            o=temp;
        }
        if(temp.id==6)
        {
            g=temp;
        }
        if(temp.id==5)
        {
            f=temp;
        }
        if(temp.id==15)
        {
            p=temp;
        }
        if(temp.id==16)
        {
            q=temp;
        }
        if(temp.id==19)
        {
            t=temp;
        }
    count++;
    silver++;
    }
    if(count<=40&&temp.T==1&&temp.num<1&&gold<4)
    {
    Btn[count]->setText(temp.name);
    Deck[count]=temp;
    temp.num++;
        if(temp.id==7)
        {
            h=temp;
        }
        if(temp.id==10)
        {
            k=temp;
        }
        if(temp.id==12)
        {
            m=temp;
        }
        if(temp.id==18)
        {
            s=temp;
        }
    count++;
    gold++;
    ui->T1number->display(gold);
    }
    if(count<=40&&temp.T==4&&temp.num<1&&leader<1)
    {
    ui->leaderbutton->setText(temp.name);
    ShouLing=temp;
    temp.num++;
        if(temp.id==8)
        {
            i=temp;
        }
        if(temp.id==20)
        {
            u=temp;
        }
    leader++;
    }
}

void MainWindow::on_selectCard_2_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[1]);
    temp=b;
}
void MainWindow::on_selectCard_3_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[2]);
    temp=c;
}
void MainWindow::on_selectCard_4_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[3]);
    temp=d;
}
void MainWindow::on_selectCard_5_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[4]);
    temp=e;
}
void MainWindow::on_selectCard_6_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[5]);
    temp=f;
}
void MainWindow::on_selectCard_7_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[6]);
    temp=g;
}
void MainWindow::on_selectCard_8_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[7]);
    temp=h;
}
void MainWindow::on_selectCard_9_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[8]);
    temp=i;
}
void MainWindow::on_selectCard_10_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[9]);
    temp=j;
}
void MainWindow::on_selectCard_11_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[10]);
    temp=k;
}
void MainWindow::on_selectCard_12_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[11]);
    temp=l;
}
void MainWindow::on_selectCard_13_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[12]);
    temp=m;
}
void MainWindow::on_selectCard_14_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[13]);
    temp=n;
}
void MainWindow::on_selectCard_15_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[14]);
    temp=o;
}
void MainWindow::on_selectCard_16_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[15]);
    temp=p;
}
void MainWindow::on_selectCard_17_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[16]);
    temp=q;
}
void MainWindow::on_selectCard_18_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[17]);
    temp=r;
}
void MainWindow::on_selectCard_19_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[18]);
    temp=s;
}
void MainWindow::on_selectCard_20_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[19]);
    temp=t;
}
void MainWindow::on_selectCard_21_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[20]);
    temp=u;
}
void MainWindow::on_selectCard_22_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[21]);
    temp=v;
}
void MainWindow::on_selectCard_23_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[22]);
    temp=w;
}
void MainWindow::on_selectCard_24_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[23]);
    temp=aa;
}
void MainWindow::on_selectCard_25_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[24]);
    temp=ab;
}
void MainWindow::on_selectCard_26_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[25]);
    temp=ac;
}
void MainWindow::on_selectCard_27_clicked()
{
    ui->makecardpicture->setStyleSheet(exppc[26]);
    temp=ad;
}


void MainWindow::on_quitmake_clicked()
{
    if(count<25)
    msgbox.show();
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_reset_clicked()
{
   for(int ak=0;ak<40;ak++)
    Btn[ak]->setText("");
    count=0;
   gold=0;
   silver=0;
   bronze=0;
   leader=0;
    a.num=0;
    b.num=0;
    c.num=0;
    d.num=0;
    e.num=0;
    f.num=0;
    g.num=0;
    h.num=0;
    i.num=0;
    j.num=0;
    k.num=0;
    l.num=0;
    m.num=0;
    n.num=0;
    o.num=0;
    p.num=0;
    q.num=0;
    r.num=0;
    s.num=0;
    t.num=0;
    u.num=0;
    v.num=0;
    w.num=0;
    aa.num=0;
    ab.num=0;
    ac.num=0;
    ad.num=0;
}

void MainWindow::on_decklist_clicked()
{
   deletecard(0);
}

void MainWindow::on_decklist_2_clicked()
{
  deletecard(1);
}
void MainWindow::on_decklist_3_clicked()
{
     deletecard(2);
}


void MainWindow::on_decklist_4_clicked()
{
     deletecard(3);
}
void MainWindow::on_decklist_5_clicked()
{
   deletecard(4);
}

void MainWindow::on_decklist_6_clicked()
{
   deletecard(5);
}

void MainWindow::on_decklist_7_clicked()
{
 deletecard(6);

}

void MainWindow::on_decklist_8_clicked()
{
  deletecard(7);

}

void MainWindow::on_decklist_9_clicked()
{
    deletecard(8);
}

void MainWindow::on_decklist_10_clicked()
{
 deletecard(9);
}

void MainWindow::on_decklist_11_clicked()
{
    deletecard(10);

}

void MainWindow::on_decklist_12_clicked()
{
     deletecard(11);
}

void MainWindow::on_decklist_13_clicked()
{
     deletecard(12);

}

void MainWindow::on_decklist_14_clicked()
{
    deletecard(13);
}

void MainWindow::on_decklist_15_clicked()
{
    deletecard(14);
}

void MainWindow::on_decklist_16_clicked()
{
   deletecard(15);
}

void MainWindow::on_decklist_17_clicked()
{
       deletecard(16);
}

void MainWindow::on_decklist_18_clicked()
{
   deletecard(17);
}

void MainWindow::on_decklist_19_clicked()
{
    deletecard(18);}

void MainWindow::on_decklist_20_clicked()
{
     deletecard(19);}

void MainWindow::on_decklist_21_clicked()
{
     deletecard(20);}

void MainWindow::on_decklist_22_clicked()
{deletecard(21);}

void MainWindow::on_decklist_23_clicked()
{
  deletecard(22);}

void MainWindow::on_decklist_24_clicked()
{
    deletecard(23);}

void MainWindow::on_decklist_25_clicked()
{
  deletecard(24);}

void MainWindow::on_decklist_26_clicked()
{
   deletecard(25);}

void MainWindow::on_decklist_27_clicked()
{
 deletecard(26);}

void MainWindow::on_decklist_28_clicked()
{
    deletecard(27);}

void MainWindow::on_decklist_29_clicked()
{
deletecard(28);}

void MainWindow::on_decklist_30_clicked()
{deletecard(29);}

void MainWindow::on_decklist_31_clicked()
{
  deletecard(30);}

void MainWindow::on_decklist_32_clicked()
{
    deletecard(31);}

void MainWindow::on_decklist_33_clicked()
{
     deletecard(32);}

void MainWindow::on_decklist_34_clicked()
{
  deletecard(33);}
void MainWindow::on_decklist_35_clicked()
{
    deletecard(34);}

void MainWindow::on_decklist_36_clicked()
{
  deletecard(35);}

void MainWindow::on_decklist_37_clicked()
{
  deletecard(36);}


void MainWindow::on_decklist_38_clicked()
{
    deletecard(37);}

void MainWindow::on_decklist_39_clicked()
{
     deletecard(38);}

void MainWindow::on_decklist_40_clicked()
{
  deletecard(39);}
void MainWindow::makeit(int mn)
{
    if(Deck[mn].id==0)
        a.num--;
    if(Deck[mn].id==1)
        b.num--;
    if(Deck[mn].id==2)
        c.num--;
    if(Deck[mn].id==3)
        d.num--;
    if(Deck[mn].id==4)
        e.num--;
    if(Deck[mn].id==5)
        f.num--;
    if(Deck[mn].id==6)
        g.num--;
    if(Deck[mn].id==7)
        h.num--;
    if(Deck[mn].id==8)
        i.num--;
    if(Deck[mn].id==9)
        j.num--;
    if(Deck[mn].id==10)
        k.num--;
    if(Deck[mn].id==11)
       l.num--;
    if(Deck[mn].id==12)
        m.num--;
    if(Deck[mn].id==13)
        n.num--;
    if(Deck[mn].id==14)
        o.num--;
    if(Deck[mn].id==15)
       p.num--;
    if(Deck[mn].id==16)
        q.num--;
    if(Deck[mn].id==17)
        r.num--;
    if(Deck[mn].id==18)
        s.num--;
    if(Deck[mn].id==19)
        t.num--;
    if(Deck[mn].id==20)
        u.num--;
    if(Deck[mn].id==21)
        v.num--;
    if(Deck[mn].id==22)
        w.num--;
    if(Deck[mn].id==23)
        aa.num--;
    if(Deck[mn].id==24)
        ab.num--;
    if(Deck[mn].id==25)
        ac.num--;
    if(Deck[mn].id==26)
        ad.num--;
    if(Deck[mn].T==1)
        gold--;
    if(Deck[mn].T==2)
        silver--;
    if(Deck[mn].T==3)
        bronze--;
    if(Deck[mn].T==4)
        leader--;
     ui->makecardpicture->setStyleSheet("");
}


void MainWindow::on_redraw_clicked()
{
    letredraw(0,count-10);
}
void MainWindow::on_redraw_2_clicked()
{

    letredraw(1,count-10);
}
void MainWindow::on_redraw_3_clicked()
{
 letredraw(2,count-10);
}
void MainWindow::on_redraw_4_clicked()
{
 letredraw(3,count-10);
}
void MainWindow::on_redraw_5_clicked()
{
   letredraw(4,count-10);

}
void MainWindow::on_redraw_6_clicked()
{
    letredraw(5,count-10);
}
void MainWindow::on_redraw_7_clicked()
{

   letredraw(6,count-10);
}
void MainWindow::on_redraw_8_clicked()
{

    letredraw(7,count-10);
}
void MainWindow::on_redraw_9_clicked()
{
    letredraw(8,count-10);

}
void MainWindow::on_redraw_10_clicked()
{
    letredraw(9,count-10);

}
void MainWindow::letredraw(int iu,int ioi)
{
    if(check<3)
    {
    srand(time(NULL));
    tp1=rand()%(ioi);
    save2=Hand[iu];
    Hand[iu]=Deck[tp1];
    Deck[tp1]=save2;
    redrawBtn[iu]->setStyleSheet(Hand[iu].path);
    check++;
    }
    if(check==3)
        SangE.show();
}



void MainWindow::on_Myhand_clicked()
{
    ui->explain->setStyleSheet(exppc[ShouLing.id]);
    ingametemp=ShouLing;
    for(int iu=0;iu<5;iu++)
    {
    if(Mysaber[iu].where!=2)
    {
   ML1[iu]->setStyleSheet("background-color:blue;");
    }
    if(Myarcher[iu].where!=2)
    {
ML2[iu]->setStyleSheet("background-color:blue;");
    }
    if(Myrider[iu].where!=2)
    {
ML3[iu]->setStyleSheet("background-color:blue;");
    }
    }
   //ingametemp=OPShouLing;
    Myhandnum=0;
    long tempo = 10;
    savecardnum=QString::number(tempo,10);
    savecardnum=savecardnum+" ";
}
void MainWindow::on_Myhand_2_clicked()
{
    usecard(0);
}
void MainWindow::on_Myhand_3_clicked()
{
    usecard(1);
}
void MainWindow::on_Myhand_4_clicked()
{
   usecard(2);
}
void MainWindow::on_Myhand_5_clicked()
{
    usecard(3);
}
void MainWindow::on_Myhand_6_clicked()
{
   usecard(4);
}
void MainWindow::on_Myhand_7_clicked()
{
   usecard(5);
}
void MainWindow::on_Myhand_8_clicked()
{
   usecard(6);
}
void MainWindow::on_Myhand_9_clicked()
{
   usecard(7);
}
void MainWindow::on_Myhand_10_clicked()
{
   usecard(8);
}
void MainWindow::on_Myhand_11_clicked()
{
   usecard(9);
}

void MainWindow::usecard(int ioi)
{
    ui->explain->setStyleSheet(exppc[Hand[ioi].id]);//
    ingametemp=Hand[ioi];//
    if(ingametemp.job==1)
    {
        for(int iu=0;iu<5;iu++)
        {
         if(Mysaber[iu].where!=2)
         {
          ML1[iu]->setStyleSheet("background-color:blue;");
         }
         if(Myarcher[iu].where!=2)
         {
            ML2[iu]->setStyleSheet("");
         }
         if(Myrider[iu].where!=2)
         {
            ML3[iu]->setStyleSheet("");
         }
        }
    }
    if(ingametemp.job==2)
     {
        for(int iu=0;iu<5;iu++)
        {
             if(Myarcher[iu].where!=2)
             {
                ML2[iu]->setStyleSheet("background-color:blue;");
             }
             if(Mysaber[iu].where!=2)
            {
                ML1[iu]->setStyleSheet("");
            }
             if(Myrider[iu].where!=2)
            {
                ML3[iu]->setStyleSheet("");
            }
        }
    }
    if(ingametemp.job==3)
    {
        for(int iu=0;iu<5;iu++)
        {
            if(Myrider[iu].where!=2)
            {
                ML3[iu]->setStyleSheet("background-color:blue;");
            }
            if(Mysaber[iu].where!=2)
           {
               ML1[iu]->setStyleSheet("");
           }
            if(Myarcher[iu].where!=2)
            {
               ML2[iu]->setStyleSheet("");
            }
        }
    }
    if(ingametemp.job==4)
    {
        for(int iu=0;iu<5;iu++)
        {
            if(Mysaber[iu].where!=2)
            {
           ML1[iu]->setStyleSheet("background-color:blue;");
            }
            if(Myarcher[iu].where!=2)
            {
       ML2[iu]->setStyleSheet("background-color:blue;");
            }
            if(Myrider[iu].where!=2)
            {
        ML3[iu]->setStyleSheet("background-color:blue;");
            }
        }
    }
    if(ingametemp.job==5)
    {
        if(OPweather[0].where!=2)
        ui->OPweather->setStyleSheet("background-color:blue;");
        if(OPweather[1].where!=2)
        ui->OPweather_2->setStyleSheet("background-color:blue;");
        if(OPweather[2].where!=2)
        ui->OPweather_3->setStyleSheet("background-color:blue;");
       for(int iu=0;iu<5;iu++)
       {
        if(Mysaber[iu].where!=2)
        {
            ML1[iu]->setStyleSheet("");
        }
        if(Myarcher[iu].where!=2)
        {
            ML2[iu]->setStyleSheet("");
        }
        if(Myrider[iu].where!=2)
        {
             ML3[iu]->setStyleSheet("");
        }
       }
    }


     if(ingametemp.job!=5)
     {
         if(OPweather[0].where!=2)
         ui->OPweather->setStyleSheet("");
         if(OPweather[1].where!=2)
         ui->OPweather_2->setStyleSheet("");
         if(OPweather[2].where!=2)
         ui->OPweather_3->setStyleSheet("");
     }
    Myhandnum=ioi+1;
    savecardnum="";
    long tempo = ioi;
    savecardnum=QString::number(tempo,10);
    savecardnum=savecardnum+" ";
}

void MainWindow::on_MyLine1_clicked()
{
   selectline1(0);
}

void MainWindow::on_MyLine1_2_clicked()
{
    selectline1(1);
}
void MainWindow::on_MyLine1_3_clicked()
{
    selectline1(2);
}

void MainWindow::on_MyLine1_4_clicked()
{
    selectline1(3);
}

void MainWindow::on_MyLine1_5_clicked()
{
   selectline1(4);
}

void MainWindow::on_MyLine2_clicked()
{
   selectline2(0);
}

void MainWindow::on_MyLine2_2_clicked()
{
    selectline2(1);
}
void MainWindow::on_MyLine2_3_clicked()
{
    selectline2(2);
}

void MainWindow::on_MyLine2_4_clicked()
{
    selectline2(3);
}

void MainWindow::on_MyLine2_5_clicked()
{
   selectline2(4);
}
void MainWindow::on_MyLine3_clicked()
{
   selectline3(0);
}

void MainWindow::on_MyLine3_2_clicked()
{
    selectline3(1);
}
void MainWindow::on_MyLine3_3_clicked()
{
    selectline3(2);
}

void MainWindow::on_MyLine3_4_clicked()
{
    selectline3(3);
}

void MainWindow::on_MyLine3_5_clicked()
{
   selectline3(4);
}
void MainWindow::selectline1(int iu)
{
    if(Mysaber[iu].where!=2&&turn==1)
    {
    if((ingametemp.job==1||ingametemp.job==4))
    {
        ML1[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);

         Hand[Myhandnum-1].where=0;
        Mysaber[iu]=ingametemp;
        Mysaber[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
        Mysabertotal=0;

        for(int iu=0;iu<5;iu++)
        {
            Mysabertotal = Mysabertotal+Mysaber[iu].attack;

        }
        Mytotal=Mysabertotal+Myarchertotal+Myridertotal;
        long tempo = iu;
        savecardnum = savecardnum+QString::number(tempo);
        savecardnum = savecardnum+" ";
        savecardnum = savecardnum+"b";
        QByteArray *array = new QByteArray;
        array->clear();
        array->append(savecardnum);
        this->readWriteSocket->write(array->data());
        savecardnum="";

    }
    }
  else if(Mysaber[iu].where==2)
    {
        ui->explain->setStyleSheet(exppc[Mysaber[iu].id]);
    }
}
void MainWindow::selectline2(int iu)
{
   if(Myarcher[iu].where!=2&&turn==1)
   {
    if(ingametemp.job==2||ingametemp.job==4)
    {
        ML2[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);
         Hand[Myhandnum-1].where=0;
        Myarcher[iu]=ingametemp;
         Myarcher[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
         Myarchertotal=0;
        for(int iu=0;iu<5;iu++)
        {

            Myarchertotal = Myarchertotal+Myarcher[iu].attack;

        }
        Mytotal=Mysabertotal+Myarchertotal+Myridertotal;
        long tempo = iu;
        savecardnum = savecardnum+QString::number(tempo);
        savecardnum = savecardnum+" ";
        savecardnum = savecardnum+"c";

        QByteArray *array = new QByteArray;
        array->clear();
        array->append(savecardnum);
        this->readWriteSocket->write(array->data());
        savecardnum="";

    }}
  else if(Myarcher[iu].where==2)
   {
       ui->explain->setStyleSheet(exppc[Myarcher[iu].id]);
   }
}
void MainWindow::selectline3(int iu)
{
    if(Myrider[iu].where!=2&&turn==1)
    {
    if(ingametemp.job==3||ingametemp.job==4)
    {
        ML3[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);
         Hand[Myhandnum-1].where=0;
        Myrider[iu]=ingametemp;
        Myrider[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
        Myridertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            Myridertotal =  Myridertotal+Myrider[iu].attack;
        }
        Mytotal=Mysabertotal+Myarchertotal+Myridertotal;
        long tempo = iu;
        savecardnum = savecardnum+QString::number(tempo);
        savecardnum = savecardnum+" ";
        savecardnum = savecardnum+"d";
        QByteArray *array = new QByteArray;
        array->clear();
        array->append(savecardnum);
        this->readWriteSocket->write(array->data());
        savecardnum="";

    }
    }
 else  if(Myrider[iu].where==2)
    {
        ui->explain->setStyleSheet(exppc[Myrider[iu].id]);
    }
}

void MainWindow::on_OPLine1_clicked()
{
    OPselectline1(0);
}
void MainWindow::on_OPLine1_2_clicked()
{
    OPselectline1(1);
}
void MainWindow::on_OPLine1_3_clicked()
{
    OPselectline1(2);
}

void MainWindow::on_OPLine1_4_clicked()
{
    OPselectline1(3);
}

void MainWindow::on_OPLine1_5_clicked()
{
    OPselectline1(4);
}

void MainWindow::on_OPLine2_clicked()
{
    OPselectline2(0);
}
void MainWindow::on_OPLine2_2_clicked()
{
    OPselectline2(1);
}
void MainWindow::on_OPLine2_3_clicked()
{
    OPselectline2(2);
}

void MainWindow::on_OPLine2_4_clicked()
{
    OPselectline2(3);
}

void MainWindow::on_OPLine2_5_clicked()
{
    OPselectline2(4);
}

void MainWindow::on_OPLine3_clicked()
{
    OPselectline3(0);
}
void MainWindow::on_OPLine3_2_clicked()
{
    OPselectline3(1);
}
void MainWindow::on_OPLine3_3_clicked()
{
    OPselectline3(2);
}

void MainWindow::on_OPLine3_4_clicked()
{
    OPselectline3(3);
}

void MainWindow::on_OPLine3_5_clicked()
{
    OPselectline3(4);
}
void MainWindow::OPselectline1(int iu)
{
    if(OPsaber[iu].where!=2)
    {
    if(ingametemp.job==6)
    {
        OPL1[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);
        OPsaber[iu]=ingametemp;
        OPsaber[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);//出牌后，解释图片消失
        OPsabertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OPsabertotal =  OPsabertotal+OPsaber[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
    }}
  else  if(OPsaber[iu].where==2)
    {
        ui->explain->setStyleSheet(exppc[OPsaber[iu].id]);
    }
}

void MainWindow::OPselectline2(int iu)
{
    if(OParcher[iu].where!=2)
    {
    if(ingametemp.job==6)
    {
        OPL2[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);
        OParcher[iu]=ingametemp;
        OParcher[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
        OParchertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OParchertotal =  OParchertotal+OParcher[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
    }}
 else   if(OParcher[iu].where==2)
    {
        ui->explain->setStyleSheet(exppc[OParcher[iu].id]);
    }
}
void MainWindow::OPselectline3(int iu)
{
  if(OPrider[iu].where!=2){
    if(ingametemp.job==6)
    {
        OPL3[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);
        OPrider[iu]=ingametemp;
        OPrider[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
        OPridertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OPridertotal =  OPridertotal+OPrider[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
    }}
 else if(OPrider[iu].where==2)
  {
      ui->explain->setStyleSheet(exppc[OPrider[iu].id]);
  }
}

void MainWindow::deletecard(int iu)
{
    if(count>iu){
        makeit(iu);
   for(int ak=iu;ak<count-1;ak++)
   {
       Btn[ak]->setText(Deck[ak+1].name);
       Deck[ak]=Deck[ak+1];
   }
       Btn[count-1]->setText("");
       count--;

    }
}

void MainWindow::on_leaderbutton_clicked()
{
    if(ShouLing.id==8)
        i.num--;
    if(ShouLing.id==20)
        u.num--;
    ShouLing=jiwo;
    ui->leaderbutton->setText("");
    if(leader>0)
    leader--;
    ui->makecardpicture->setStyleSheet("");
}
void MainWindow::updateline1(int iu,int ioi)
{

        OPL1[iu]->setStyleSheet(OPHand[ioi].path);
        OPsaber[iu]=OPHand[ioi];
        OPsaber[iu].where=2;
        OPsabertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OPsabertotal =  OPsabertotal+OPsaber[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
        changeturn();
}
void MainWindow::updateline2(int iu,int ioi)
{

        OPL2[iu]->setStyleSheet(OPHand[ioi].path);
        OParcher[iu]=OPHand[ioi];
        OParcher[iu].where=2;
        OParchertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OParchertotal =  OParchertotal+OParcher[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
        changeturn();
}
void MainWindow::updateline3(int iu,int ioi)
{

        OPL3[iu]->setStyleSheet(OPHand[ioi].path);
        OPrider[iu]=OPHand[ioi];
        OPrider[iu].where=2;
        OPridertotal=0;
        for(int iu=0;iu<5;iu++)
        {
            OPridertotal =  OPridertotal+OPrider[iu].attack;
        }
        OPtotal=OPsabertotal+OParchertotal+OPridertotal;
        changeturn();
}
void MainWindow::changeturn()
{
    QString changeit="";
    QByteArray *array = new QByteArray;
    changeit=changeit+"f";
    array->clear();
    array->append(changeit);
    this->readWriteSocket->write(array->data());
    jud++;

}

void MainWindow::on_OPweather_clicked()
{
   OPweatherline(0);
}
void MainWindow::on_OPweather_2_clicked()
{
    OPweatherline(1);
}
void MainWindow::on_OPweather_3_clicked()
{
    OPweatherline(2);
}
void MainWindow::OPweatherline(int iu)
{
    if(OPweather[iu].where!=2&&turn==1)
    {
    if(ingametemp.job==5)
    {
       OPW[iu]->setStyleSheet(ingametemp.path);
        MH[Myhandnum]->setVisible(false);

       OPweather[iu]=ingametemp;
        OPweather[iu].where=2;
        ingametemp=jiwo;
        ui->explain->setStyleSheet(ingametemp.path);
        long tempo = iu;
        savecardnum = savecardnum+QString::number(tempo);
        savecardnum = savecardnum+" ";
        savecardnum = savecardnum+"g";
        QByteArray *array = new QByteArray;
        array->clear();
        array->append(savecardnum);
        this->readWriteSocket->write(array->data());
        savecardnum="";
    }

    }
    if(OPweather[iu].where==2)
    {
        ui->explain->setStyleSheet(exppc[OPweather[iu].id]);
    }

}
void MainWindow::on_Myweather_clicked()
{

}
void MainWindow::on_Myweather_2_clicked()
{

}
void MainWindow::on_Myweather_3_clicked()
{

}
void MainWindow::updateweather(int iu,int ioi)
{
    MW[iu]->setStyleSheet(OPHand[ioi].path);
    Myweather[iu]=OPHand[ioi];
    Myweather[iu].where=2;
    changeturn();
}
void MainWindow::on_giveup_clicked()
 {
    if(giveupclient==0&&turn==1)
    {
    QString plz="";
    plz=plz+"h";
    QByteArray *array = new QByteArray;
    array->clear();
    array->append(plz);
     this->readWriteSocket->write(array->data());
    plz="";
    giveupclient=1;
    }

}



void MainWindow::on_page6next_2_clicked()
{
    count=count-2;
    for(int iu=0;iu<5;iu++)
    {
        Mysaber[iu]=jiwo;
        Myarcher[iu]=jiwo;
        Myrider[iu]=jiwo;
        OPsaber[iu]=jiwo;
        OParcher[iu]=jiwo;
        OPrider[iu]=jiwo;
    }
    for(int iu=0;iu<3;iu++)
    {
        OPweather[iu]=jiwo;
        Myweather[iu]=jiwo;
    }
    Mytotal=OPtotal=Myridertotal=Mysabertotal=Myarchertotal=0;
    OPsabertotal=OParchertotal=OPridertotal=0;
    int rvv=0;
    int OPrvv=0;
    for(int iu=0;iu<10;iu++)
    {
         MH[iu+1]->setVisible(true);
        if(Hand[iu].where==0)
        {
            Hand[iu]=Deck[rvv];
            rvv++;
            if(rvv==2)
                break;
        }
            if(OPHand[iu].where==0)
            {
                OPHand[iu]=OPDeck[OPrvv];
                OPBtn[iu]->setVisible(true);
                OPrvv++;
                if(OPrvv==2)
                    break;
            }
    }
    for(int iu=0;iu<OPcardnum-12;iu++)
    {
        OPDeck[iu]=OPDeck[iu+2];
    }
    for(int iu=0;iu<bronze+silver+gold-12;iu++)
    {
         Deck[iu]=Deck[iu+2];
    }
            for(int ak=0;ak<10;ak++)
      {
           redrawBtn[ak]->setStyleSheet(Hand[ak].path);
       }
            tempsave=3;
        giveupclient=giveupserver=0;
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

