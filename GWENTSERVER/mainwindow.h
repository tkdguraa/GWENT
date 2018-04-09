#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QMessageBox>
#include "card.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    void makeit(int mn);
    void letredraw(int iu,int ioi);
    void usecard(int ioi);//游戏里显示说明
    void selectline1(int iu);
    void selectline2(int iu);
    void selectline3(int iu);
    void OPselectline1(int iu);
    void OPselectline2(int iu);
    void OPselectline3(int iu);
    void deletecard(int iu);
    void updateline1(int iu,int ioi);
    void updateline2(int iu,int ioi);
    void updateline3(int iu,int ioi);
    void changeturn();
    void OPweatherline(int iu);
    void Myweatherline(int iu);
    void updateweather(int iu,int ioi);
public:
    void initServer();
    QPushButton *Btn[40];
    QPushButton *redrawBtn[10];
    QString exp[40];
    QString exppc[40];
    QMessageBox msgbox;
    QMessageBox SangE;
    QMessageBox NoShouLing;
    QPushButton *ML1[10];
    QPushButton *ML2[10];
    QPushButton *ML3[10];
    QPushButton *MH[15];
    QPushButton *OPL1[10];
    QPushButton *OPL2[10];
    QPushButton *OPL3[10];
    QPushButton *OPBtn[15];
    QPushButton *MW[5];
    QPushButton *OPW[5];
public slots:
    void acceptConnection();
    void recvMessage();
private slots:

    //void reset( int rs );
    void on_Login_clicked();
    void on_leaderbutton_clicked();

    void on_finish_clicked();

    void on_Start_clicked();

    void on_Deck_clicked();

    void on_selectCard_clicked();

    void on_makecardpicture_clicked();

    void on_selectCard_2_clicked();

    void on_selectCard_3_clicked();
    void on_selectCard_4_clicked();
    void on_selectCard_5_clicked();
    void on_selectCard_6_clicked();
    void on_selectCard_7_clicked();
    void on_selectCard_8_clicked();
    void on_selectCard_9_clicked();
    void on_selectCard_10_clicked();
    void on_selectCard_11_clicked();
    void on_selectCard_12_clicked();
    void on_selectCard_13_clicked();
    void on_selectCard_14_clicked();
    void on_selectCard_15_clicked();
    void on_selectCard_16_clicked();
    void on_selectCard_17_clicked();
    void on_selectCard_18_clicked();
    void on_selectCard_19_clicked();
    void on_selectCard_20_clicked();
    void on_selectCard_21_clicked();
    void on_selectCard_22_clicked();
    void on_selectCard_23_clicked();
    void on_selectCard_24_clicked();
    void on_selectCard_25_clicked();
    void on_selectCard_26_clicked();
    void on_selectCard_27_clicked();
    void on_quitmake_clicked();

    void on_reset_clicked();

    void on_decklist_clicked();
    void on_decklist_2_clicked();
    void on_decklist_3_clicked();
    void on_decklist_4_clicked();
    void on_decklist_5_clicked();
    void on_decklist_6_clicked();
    void on_decklist_7_clicked();
    void on_decklist_8_clicked();
    void on_decklist_9_clicked();
    void on_decklist_10_clicked();
    void on_decklist_11_clicked();
    void on_decklist_12_clicked();
    void on_decklist_13_clicked();
    void on_decklist_14_clicked();
    void on_decklist_15_clicked();
    void on_decklist_16_clicked();
    void on_decklist_17_clicked();
    void on_decklist_18_clicked();
    void on_decklist_19_clicked();
    void on_decklist_20_clicked();
    void on_decklist_21_clicked();
    void on_decklist_22_clicked();
    void on_decklist_23_clicked();
    void on_decklist_24_clicked();
    void on_decklist_25_clicked();
    void on_decklist_26_clicked();
    void on_decklist_27_clicked();
    void on_decklist_28_clicked();
    void on_decklist_29_clicked();
    void on_decklist_30_clicked();
    void on_decklist_31_clicked();
    void on_decklist_32_clicked();
    void on_decklist_33_clicked();
    void on_decklist_34_clicked();
    void on_decklist_35_clicked();
    void on_decklist_36_clicked();
    void on_decklist_37_clicked();
    void on_decklist_38_clicked();
    void on_decklist_39_clicked();
    void on_decklist_40_clicked();
    void on_redraw_clicked();
    void on_redraw_2_clicked();
    void on_redraw_3_clicked();
    void on_redraw_4_clicked();
    void on_redraw_5_clicked();
    void on_redraw_6_clicked();
    void on_redraw_7_clicked();
    void on_redraw_8_clicked();
    void on_redraw_9_clicked();
    void on_redraw_10_clicked();


    void on_Myhand_clicked();
    void on_Myhand_2_clicked();
    void on_Myhand_3_clicked();
    void on_Myhand_4_clicked();
    void on_Myhand_5_clicked();
    void on_Myhand_6_clicked();
    void on_Myhand_7_clicked();
    void on_Myhand_8_clicked();
    void on_Myhand_9_clicked();
    void on_Myhand_10_clicked();
    void on_Myhand_11_clicked();






    void on_MyLine1_clicked();
    void on_MyLine1_2_clicked();
    void on_MyLine1_3_clicked();
    void on_MyLine1_4_clicked();
    void on_MyLine1_5_clicked();

    void on_MyLine2_clicked();
    void on_MyLine2_2_clicked();
    void on_MyLine2_3_clicked();
    void on_MyLine2_4_clicked();
    void on_MyLine2_5_clicked();

    void on_MyLine3_clicked();
    void on_MyLine3_2_clicked();
    void on_MyLine3_3_clicked();
    void on_MyLine3_4_clicked();
    void on_MyLine3_5_clicked();


    void on_OPLine1_clicked();
    void on_OPLine1_2_clicked();
    void on_OPLine1_3_clicked();
    void on_OPLine1_4_clicked();
    void on_OPLine1_5_clicked();

    void on_OPLine2_clicked();
    void on_OPLine2_2_clicked();
    void on_OPLine2_3_clicked();
    void on_OPLine2_4_clicked();
    void on_OPLine2_5_clicked();

    void on_OPLine3_clicked();
    void on_OPLine3_2_clicked();
    void on_OPLine3_3_clicked();
    void on_OPLine3_4_clicked();
    void on_OPLine3_5_clicked();


    void on_OPweather_clicked();
    void on_OPweather_2_clicked();
    void on_OPweather_3_clicked();

    void on_Myweather_clicked();
    void on_Myweather_2_clicked();
    void on_Myweather_3_clicked();

    void on_giveup_clicked();
    void on_page6next_2_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer  *listenSocket;
    QTcpSocket  *readWriteSocket;
};

#endif // MAINWINDOW_H
