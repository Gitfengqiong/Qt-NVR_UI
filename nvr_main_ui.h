#ifndef NVR_MAIN_UI_H
#define NVR_MAIN_UI_H

#include <iostream>
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QString>
#include<QGroupBox>
#include<QGridLayout>
#include<QLineEdit>
#include<QTextList>
#include<QListWidget>
#include<QCheckBox>
#include<QDialog>
#include<QPixmap>
#include<QCompleter>
#include<QDateTimeEdit>
#include<QFont>
#include<QPalette>
#include<QListWidgetItem>
#include<QMessageBox>
#include<QComboBox>
#include<QStackedWidget>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QSplitter>
#include "nvr_layout_ui.h"

/*
 * The Debug Line
*/
#define DEBUG 1

class NVR_main_ui : public QWidget
{
  Q_OBJECT

public:
  NVR_main_ui(QWidget *parent = 0);
  ~NVR_main_ui();
private:
  QPushButton *search_IPC_button;
  QPushButton *Video_Set_button;
  QPushButton *SetVideo_to_Layout_button;
  QPushButton *Sys_Set_button;
  QPushButton *OK_button;
  QPushButton *Cancel_button;
  QDateTimeEdit * Systime;
  QLabel *Timeedit;

 private slots:
  void Power_Ipc_ui();
  void Power_Layout_ui();

signals:
  void search_IPC_button_signal(bool button);
};

class NVR_Search_IPC_ui : public QDialog
{
  Q_OBJECT
public:
  NVR_Search_IPC_ui (QDialog *parent = 0 ) ;
  ~NVR_Search_IPC_ui();

private:
  QLabel *User ;
  QLabel *Passd;
  QLineEdit *Usere;
  QLineEdit *Passde;
  QPushButton * OK;
  QPushButton* Cancel;
  QVBoxLayout * IP_Layout, *IP_Layout1;

  QPushButton * search;
  QPushButton *addIp;
  QPushButton *removeIp;
  QPushButton *removeall;
  QLabel *IP_choosename;
  QListWidget *iPview;
  QListWidget *iPview1;
  QListWidgetItem *ipblock1;
  QListWidgetItem *ipblock;
  QHBoxLayout * search_bott_layout;
  QHBoxLayout * search_Top_layout;
  QVBoxLayout * search_Center_layout;
  QHBoxLayout * search_CenterMain_layout;
  QHBoxLayout *search_Cheek_layout;
  QHBoxLayout *search_Cheek_layout1;
  QHBoxLayout *search_CheekMain_layout;
  QGridLayout  *search_layout;
  QPushButton* cheekall, *cheekall1;
  QPushButton* recheekall,*recheekall1;
  QSplitter *cheek_splitter;

private slots:
  void on_search_in();
  void on_search_removeall();
  void on_search_removeip();
  void on_search_addip();
  void on_search_cheek();
  void on_search_cheek1();
  void on_search_OK();
  void on_search_Cancel();
  void on_search_recheek();
  void on_search_recheek1();

};

class NVR_Search_IPC_ui_ipitem : public QWidget
{
  Q_OBJECT
public:
  NVR_Search_IPC_ui_ipitem (QWidget *parent=0) ;
  ~NVR_Search_IPC_ui_ipitem();
  void setip(QString a){this->IP->setText(a) ;};

  QLabel *IP;
  QLineEdit *IPLable;
  QCheckBox *itip;
  QHBoxLayout *iplayout;
  TOURI_S thisIP;

};

class NVR_Video_layout_ui : public QDialog
{
  Q_OBJECT
public:
  NVR_Video_layout_ui (QDialog *parent = 0 );

  ~NVR_Video_layout_ui();

private:

 QComboBox *CheekLayout ;
 QComboBox *Physical_channel;
 QVBoxLayout * Vlayout;
 QStackedWidget *Layoutview;
 LayoutScene  *MainScecn;
 viewItem *ViewItem;
 ViewLayout *MainView;
 QVBoxLayout * Graphics_View_layout;
 QHBoxLayout * Cheekboutt_layout;
 QGridLayout * Main_layout;
 QListWidgetItem *ipblock;
 QVBoxLayout *IPList_layout;
 QPushButton *OK;
 QPushButton *Cancel;
 QPushButton *viewip;
 QTableView *ipview_t;
 QMenu menu;
 QList<QAction*> view_windows;
 QAction *selectedAction;
 QMenu isuri;
 QAction *selectedActionuri;
 QList<QAction*> this_uri;
private slots:
 void on_ViewIpList_in();
 void on_LayoutScens_in(QPoint);
 void on_LayoutViewScens_in(int);
 void on_Cancel_in();
 void on_OK_in();
 void on_Physical_in();
public slots:
 void on_PaintIPView(QString ip, QString uri, QString Iprmark, int view, QString proname, int totalviews,QList<QAction*>::iterator theiter);
signals:
 void paniterview(QString ip, QString uri , QString Iprmark, int view, QString proname ,int totalviews,QList<QAction*>::iterator theiter);

};



#endif // NVR_MAIN_UI_H
