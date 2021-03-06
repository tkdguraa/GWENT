#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"card.h"
#include<QDebug>
void MainWindow::resizeEvent(QResizeEvent *event)
{

    ui->Login->setGeometry(5*width()/12,height()*0.85,width()/6,height()/15);
    ui->Start->setGeometry(0,height()/3,width()/6,height()/10);
    ui->Deck->setGeometry(0,height()/2,width()/6,height()/10);
    ui->finish->setGeometry(5*width()/12,height()*0.85,width()/6,height()/15);
    ui->redraw->setGeometry(width()/10,height()/6,CSIZEW,CSIZEH);
    ui->redraw_2->setGeometry(width()/10+width()/6,height()/6,CSIZEW,CSIZEH);
    ui->redraw_3->setGeometry(width()/10+width()/3,height()/6,CSIZEW,CSIZEH);
    ui->redraw_4->setGeometry(width()/10+width()/2,height()/6,CSIZEW,CSIZEH);
    ui->redraw_5->setGeometry(width()/10+2*width()/3,height()/6,CSIZEW,CSIZEH);
    ui->redraw_6->setGeometry(width()/10,height()/6+height()*0.3125,CSIZEW,CSIZEH);
    ui->redraw_7->setGeometry(width()/10+width()/6,height()/6+height()*0.3125,CSIZEW,CSIZEH);
    ui->redraw_8->setGeometry(width()/10+width()/3,height()/6+height()*0.3125,CSIZEW,CSIZEH);
    ui->redraw_9->setGeometry(width()/10+width()/2,height()/6+height()*0.3125,CSIZEW,CSIZEH);
    ui->redraw_10->setGeometry(width()/10+2*width()/3,height()/6+height()*0.3125,CSIZEW,CSIZEH);
    ui->Myhand->setGeometry(0,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_2->setGeometry(2*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_3->setGeometry(4*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_4->setGeometry(6*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_5->setGeometry(8*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_6->setGeometry(10*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_7->setGeometry(12*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_8->setGeometry(14*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_9->setGeometry(16*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_10->setGeometry(18*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);
    ui->Myhand_11->setGeometry(20*GCSIZEW,0,2*GCSIZEW,2*GCSIZEH);


    ui->MyLine1->setGeometry(width()/4+2*GCSIZEW,height()/2,GCSIZEW,GCSIZEH);
    ui->MyLine1_2->setGeometry(width()/4+4*GCSIZEW,height()/2,GCSIZEW,GCSIZEH);
    ui->MyLine1_3->setGeometry(width()/4+6*GCSIZEW,height()/2,GCSIZEW,GCSIZEH);
    ui->MyLine1_4->setGeometry(width()/4+8*GCSIZEW,height()/2,GCSIZEW,GCSIZEH);
    ui->MyLine1_5->setGeometry(width()/4+10*GCSIZEW,height()/2,GCSIZEW,GCSIZEH);

    ui->MyLine2->setGeometry(width()/4+2*GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine2_2->setGeometry(width()/4+4*GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine2_3->setGeometry(width()/4+6*GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine2_4->setGeometry(width()/4+8*GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine2_5->setGeometry(width()/4+10*GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);

    ui->MyLine3->setGeometry(width()/4+2*GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine3_2->setGeometry(width()/4+4*GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine3_3->setGeometry(width()/4+6*GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine3_4->setGeometry(width()/4+8*GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyLine3_5->setGeometry(width()/4+10*GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);

    ui->Job->setGeometry(width()/4,height()/2,GCSIZEW,GCSIZEH);
    ui->Myweather->setGeometry(width()/4+GCSIZEW,height()/2,GCSIZEW,GCSIZEW);
    ui->MyScore1->setGeometry(width()/4-GCSIZEW,height()/2,GCSIZEW,GCSIZEH);
    ui->Job_2->setGeometry(width()/4,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->Myweather_2->setGeometry(width()/4+GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEW);
    ui->MyScore2->setGeometry(width()/4-GCSIZEW,height()/2+GCSIZEH,GCSIZEW,GCSIZEH);
    ui->Job_3->setGeometry(width()/4,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->Myweather_3->setGeometry(width()/4+GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEW);
    ui->MyScore3->setGeometry(width()/4-GCSIZEW,height()/2+2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPJob->setGeometry(width()/4,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPweather->setGeometry(width()/4+GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEW);
    ui->OPScore1->setGeometry(width()/4-GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPJob_2->setGeometry(width()/4,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPweather_2->setGeometry(width()/4+GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEW);
    ui->OPScore2->setGeometry(width()/4-GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPJob_3->setGeometry(width()/4,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPweather_3->setGeometry(width()/4+GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEW);
    ui->OPScore3->setGeometry(width()/4-GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);

    ui->OPLine1->setGeometry(width()/4+2*GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine1_2->setGeometry(width()/4+4*GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine1_3->setGeometry(width()/4+6*GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine1_4->setGeometry(width()/4+8*GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine1_5->setGeometry(width()/4+10*GCSIZEW,height()/2-1.2*GCSIZEH,GCSIZEW,GCSIZEH);

    ui->OPLine2->setGeometry(width()/4+2*GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine2_2->setGeometry(width()/4+4*GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine2_3->setGeometry(width()/4+6*GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine2_4->setGeometry(width()/4+8*GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine2_5->setGeometry(width()/4+10*GCSIZEW,height()/2-2.2*GCSIZEH,GCSIZEW,GCSIZEH);

    ui->OPLine3->setGeometry(width()/4+2*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine3_2->setGeometry(width()/4+4*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine3_3->setGeometry(width()/4+6*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine3_4->setGeometry(width()/4+8*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->OPLine3_5->setGeometry(width()/4+10*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW,GCSIZEH);
    ui->MyTotal->setGeometry(width()/9,height()/2,2*GCSIZEW,3*GCSIZEH);
    ui->OPTotal->setGeometry(width()/9,height()/2-3.2*GCSIZEH,2*GCSIZEW,3*GCSIZEH);

    ui->OPHand->setGeometry(width()/4,0,GCSIZEW,GCSIZEH);
    ui->OPHand_2->setGeometry(width()/4+GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_3->setGeometry(width()/4+2*GCSIZEW,0,GCSIZEW,GCSIZEH);//
    ui->OPHand_4->setGeometry(width()/4+3*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_5->setGeometry(width()/4+4*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_6->setGeometry(width()/4+5*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_7->setGeometry(width()/4+6*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_8->setGeometry(width()/4+7*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_9->setGeometry(width()/4+8*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_10->setGeometry(width()/4+9*GCSIZEW,0,GCSIZEW,GCSIZEH);
    ui->OPHand_11->setGeometry(width()/4+10*GCSIZEW,0,GCSIZEW,GCSIZEH);//对手的手牌

    ui->explain->setGeometry(width()/4+12*GCSIZEW,height()/2-3.2*GCSIZEH,GCSIZEW*5.5,GCSIZEH*7);
    ui->selectCard->setGeometry(0,0,CSIZEW,CSIZEH);
    ui->selectCard_2->setGeometry(CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_3->setGeometry(2*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_4->setGeometry(3*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_5->setGeometry(4*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_6->setGeometry(5*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_7->setGeometry(6*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_8->setGeometry(7*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_9->setGeometry(8*CSIZEW,0,CSIZEW,CSIZEH);
    ui->selectCard_10->setGeometry(0,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_11->setGeometry(CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_12->setGeometry(2*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_13->setGeometry(3*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_14->setGeometry(4*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_15->setGeometry(5*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_16->setGeometry(6*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_17->setGeometry(7*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_18->setGeometry(8*CSIZEW,CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_19->setGeometry(0,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_20->setGeometry(CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_21->setGeometry(2*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_22->setGeometry(3*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_23->setGeometry(4*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_24->setGeometry(5*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_25->setGeometry(6*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_26->setGeometry(7*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->selectCard_27->setGeometry(8*CSIZEW,2*CSIZEH,CSIZEW,CSIZEH);
    ui->makecardpicture->setGeometry(width()/2+width()/4,0,width()/4,height()/2);
    ui->giveup->setGeometry(0,height()/2+3*GCSIZEH,width()/12,height()/8);

    ui->whoseturn->setGeometry(0,0,width()/8,height()/6);

    ui->timelimit->setGeometry(width()/12,height()/2+3*GCSIZEH,width()/12,height()/8);
    ui->decklist->setGeometry(0,0,width()/4,height()/20);
    ui->decklist_2->setGeometry(width()/4,0,width()/4,height()/20);
    ui->decklist_3->setGeometry(0,height()/20,width()/4,height()/20);
    ui->decklist_4->setGeometry(width()/4,height()/20,width()/4,height()/20);
    ui->decklist_5->setGeometry(0,2*height()/20,width()/4,height()/20);
    ui->decklist_7->setGeometry(0,3*height()/20,width()/4,height()/20);
    ui->decklist_9->setGeometry(0,4*height()/20,width()/4,height()/20);
    ui->decklist_11->setGeometry(0,5*height()/20,width()/4,height()/20);
    ui->decklist_13->setGeometry(0,6*height()/20,width()/4,height()/20);
    ui->decklist_15->setGeometry(0,7*height()/20,width()/4,height()/20);
    ui->decklist_17->setGeometry(0,8*height()/20,width()/4,height()/20);
    ui->decklist_19->setGeometry(0,9*height()/20,width()/4,height()/20);
    ui->decklist_21->setGeometry(0,10*height()/20,width()/4,height()/20);
    ui->decklist_23->setGeometry(0,11*height()/20,width()/4,height()/20);
    ui->decklist_25->setGeometry(0,12*height()/20,width()/4,height()/20);
    ui->decklist_27->setGeometry(0,13*height()/20,width()/4,height()/20);
    ui->decklist_29->setGeometry(0,14*height()/20,width()/4,height()/20);
    ui->decklist_31->setGeometry(0,15*height()/20,width()/4,height()/20);
    ui->decklist_33->setGeometry(0,16*height()/20,width()/4,height()/20);
    ui->decklist_35->setGeometry(0,17*height()/20,width()/4,height()/20);
    ui->decklist_37->setGeometry(0,18*height()/20,width()/4,height()/20);
    ui->decklist_39->setGeometry(0,19*height()/20,width()/4,height()/20);
    ui->decklist_6->setGeometry(width()/4,2*height()/20,width()/4,height()/20);
    ui->decklist_8->setGeometry(width()/4,3*height()/20,width()/4,height()/20);
    ui->decklist_10->setGeometry(width()/4,4*height()/20,width()/4,height()/20);
    ui->decklist_12->setGeometry(width()/4,5*height()/20,width()/4,height()/20);
    ui->decklist_14->setGeometry(width()/4,6*height()/20,width()/4,height()/20);
    ui->decklist_16->setGeometry(width()/4,7*height()/20,width()/4,height()/20);
    ui->decklist_18->setGeometry(width()/4,8*height()/20,width()/4,height()/20);
    ui->decklist_20->setGeometry(width()/4,9*height()/20,width()/4,height()/20);
    ui->decklist_22->setGeometry(width()/4,10*height()/20,width()/4,height()/20);
    ui->decklist_24->setGeometry(width()/4,11*height()/20,width()/4,height()/20);
    ui->decklist_26->setGeometry(width()/4,12*height()/20,width()/4,height()/20);
    ui->decklist_28->setGeometry(width()/4,13*height()/20,width()/4,height()/20);
    ui->decklist_30->setGeometry(width()/4,14*height()/20,width()/4,height()/20);
    ui->decklist_32->setGeometry(width()/4,15*height()/20,width()/4,height()/20);
    ui->decklist_34->setGeometry(width()/4,16*height()/20,width()/4,height()/20);
    ui->decklist_36->setGeometry(width()/4,17*height()/20,width()/4,height()/20);
    ui->decklist_38->setGeometry(width()/4,18*height()/20,width()/4,height()/20);
    ui->decklist_40->setGeometry(width()/4,19*height()/20,width()/4,height()/20);

    ui->buttonname->setGeometry(width()/2-width()/4-width()/15,3*height()/4,width()/15,height()/20);
    ui->leaderbutton->setGeometry(width()/2-width()/4,3*height()/4,width()/4,height()/20);
    ui->T1number->setGeometry(width()/2,0,width()/4,height()/8);
    ui->T2number->setGeometry(width()/2,height()/8,width()/4,height()/8);
    ui->T3number->setGeometry(width()/2,2*height()/8,width()/4,height()/8);
    ui->T4number->setGeometry(width()/2,3*height()/8,width()/4,height()/8);
    ui->selectscroll->setGeometry(0,0,width()/2,3*height()/4);
    ui->selectarea->setMinimumSize(1.125*width(),3*height()/4);
    ui->decklistscroll->setGeometry(width()/2,height()/2,width()/2,height()/2.2);
    ui->decklistarea->setMinimumSize(width()/4,height());
    ui->MyHandScroll->setGeometry(width()/4,4*height()/5,GCSIZEW*11,GCSIZEH*2);
    ui->MyHandarea->setMinimumSize(GCSIZEW*22,GCSIZEH*2);
    ui->quitmake->setGeometry(0,3*height()/4,width()/10,height()/10);
    ui->reset->setGeometry(0,3*height()/4+height()/10,width()/10,height()/10);
    ui->gold->setGeometry(width()/2,0,height()/8,height()/8);
    ui->silver->setGeometry(width()/2,height()/8,height()/8,height()/8);
    ui->bronze->setGeometry(width()/2,2*height()/8,height()/8,height()/8);
    ui->leader->setGeometry(width()/2,3*height()/8,height()/8,height()/8);
    ui->ME->setGeometry(0,0,width()/8,height()/6);
    ui->OP->setGeometry(width()-width()/20,0,width()/8,height()/6);

    ui->setScore->setGeometry(width()/3-width()/8,height()/4-height()/16-height()/6,width()/8,height()/6);
    ui->Mysetscore->setGeometry(width()/3,height()/4-height()/16-height()/6,width()/8,height()/6);
    ui->set1->setGeometry(width()/3-width()/8,height()/4,width()/8,height()/6);
    ui->MT->setGeometry(width()/3,height()/4,width()/8,height()/6);
    ui->set2->setGeometry(width()/3-width()/8,height()/4+height()/16+height()/6,width()/8,height()/6);
    ui->MT_2->setGeometry(width()/3,height()/4+height()/16+height()/6,width()/8,height()/6);
    ui->set3->setGeometry(width()/3-width()/8,height()/4+height()/3+height()/8,width()/8,height()/6);
    ui->MT_3->setGeometry(width()/3,height()/4+height()/3+height()/8,width()/8,height()/6);

    ui->winorlose->setGeometry(width()/4,0,width()/2,height()/6);
    ui->page6next_2->setGeometry(5*width()/12,height()*0.88,width()/6,height()/15);

    ui->OPsetscore->setGeometry(width()/3+width()/4.5,height()/4-height()/16-height()/6,width()/8,height()/6);
    ui->OPT->setGeometry(width()/3+width()/4.5,height()/4,width()/8,height()/6);
    ui->OPT_2->setGeometry(width()/3+width()/4.5,height()/4+height()/16+height()/6,width()/8,height()/6);
    ui->OPT_3->setGeometry(width()/3+width()/4.5,height()/4+height()/3+height()/8,width()/8,height()/6);
    ui->ME->setText("ME");
    ui->OP->setText("OP");
    ui->set1->setText("SET 1");
    ui->set2->setText("SET 2");
    ui->set3->setText("SET 3");
    ui->setScore->setText("SET");
    QFont ft;
    ft.setPointSize(15);
    ui->ME->setFont(ft);
    ui->OP->setFont(ft);
  ui->setScore->setFont(ft);
  ui->set1->setFont(ft);
  ui->set2->setFont(ft);
  ui->set3->setFont(ft);
    //设置颜色
    QPalette pl;
    pl.setColor(QPalette::WindowText,Qt::white);
    ui->ME->setPalette(pl);
   ui->OP->setPalette(pl);
    ui->set1->setPalette(pl);
    ui->set2->setPalette(pl);
     ui->set3->setPalette(pl);
     ui->setScore->setPalette(pl);
}
