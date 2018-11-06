#include "nvr_main_ui.h"

using namespace std ;
NVR_Search_IPC_ui::NVR_Search_IPC_ui(QDialog *parent)
  : QDialog(parent)
{
  this->setWindowTitle("IPC 管理窗");
 // this->setMaximumSize(640,480);
  this->setMinimumSize(64,48);
  this->resize(720,574);
  setWindowOpacity(0.9);


  this->User = new QLabel(this);
  this->Passd = new QLabel(this);
  this->Usere = new QLineEdit(this);
  this->Passde = new QLineEdit(this);
  this->search = new QPushButton(this);
  this->addIp = new QPushButton(this);
  this->removeall = new QPushButton(this);
  this->removeIp = new QPushButton(this);
  this->OK = new QPushButton(this);
  this->Cancel = new QPushButton(this);
  this->cheekall = new QPushButton;
  this->cheekall1 = new QPushButton;
  this->recheekall = new QPushButton;
  this->recheekall1 = new QPushButton;

  this->IP_Layout1 =new QVBoxLayout;
  this->IP_Layout =new QVBoxLayout;
  this->search_bott_layout =new QHBoxLayout;
  this->search_Top_layout = new QHBoxLayout;
  this->search_Center_layout = new QVBoxLayout;
  this->search_CenterMain_layout = new QHBoxLayout;
  this->search_Cheek_layout = new QHBoxLayout;
  this->search_Cheek_layout1 = new QHBoxLayout;
  this->search_CheekMain_layout = new QHBoxLayout;
  this->search_layout =new QGridLayout(this) ;



  User->setPixmap(QPixmap("./user.png"));
  User->setScaledContents(false);
  User->resize(QSize(8,8));
  Usere->resize(QSize(64,48));

  Passd->setPixmap(QPixmap("./clock.png"));
  Passd->setScaledContents(false);
  Passd->resize(QSize(8,8));
  Passde->resize(QSize(64,48));

  search->setIcon(QIcon("./search.png"));
  search->setFlat(true);
  search->setIconSize(QSize(48,48));
  addIp->setIcon(QIcon("./add.png"));
  addIp->setFlat(true);
  addIp->setIconSize(QSize(48,48));
  removeIp->setIcon(QIcon("./remove.png"));
  removeIp->setFlat(true);
  removeIp->setIconSize(QSize(48,48));
  OK->setIcon(QIcon("./OK.png"));
  OK->setFlat(true);
  OK->setIconSize(QSize(72,72));
  Cancel->setIcon(QIcon("./Cancel.png"));
  Cancel->setFlat(true);
  Cancel->setIconSize(QSize(72,72));
  cheekall->setIcon(QIcon("./cheek.png"));
  cheekall->setFlat(true);
  cheekall->setIconSize(QSize(24,24));
  cheekall1->setIcon(QIcon("./cheek.png"));
  cheekall1->setFlat(true);
  cheekall1->setIconSize(QSize(24,24));
  recheekall->setIcon(QIcon("./uncheek.png"));
  recheekall->setFlat(true);
  recheekall->setIconSize(QSize(24,24));
  recheekall1->setIcon(QIcon("./uncheek.png"));
  recheekall1->setFlat(true);
  recheekall1->setIconSize(QSize(24,24));
  removeall->setIcon(QIcon("./removeall.png"));
  removeall->setFlat(true);
  removeall->setIconSize(QSize(48,48));

  Passde->setInputMask(QString("000000"));
  this->iPview = new QListWidget(this);
  this->iPview1 = new QListWidget(this);

  search_bott_layout->setSpacing(30);
  search_bott_layout->addStretch();
  search_bott_layout->addWidget(OK);
  search_bott_layout->addWidget(Cancel);
  search_bott_layout->addStretch();

  IP_Layout->addWidget(iPview);
  IP_Layout1->addWidget(iPview1);

  //search_Top_layout->addStretch();
  search_Top_layout->addWidget(User);
  search_Top_layout->addWidget(Usere);
  search_Top_layout->addWidget(Passd);
  search_Top_layout->addWidget(Passde);
 // search_Top_layout->addStretch();
  search_Top_layout->setSpacing(30);

  search_Center_layout->addStretch();
  search_Center_layout->addWidget(addIp);
  search_Center_layout->addWidget(removeIp);
  search_Center_layout->addStretch();
  search_Center_layout->addWidget(search);
  search_Center_layout->addWidget(removeall);
  search_Center_layout->setSpacing(10);

  search_CenterMain_layout->addLayout(IP_Layout);
  search_CenterMain_layout->addLayout(search_Center_layout);
  search_CenterMain_layout->addLayout(IP_Layout1);
  search_CenterMain_layout->setSpacing(30);


  search_layout->addLayout(search_Top_layout,0,0,1,17);
  search_layout->addWidget(cheekall,2,3,1,1);
  search_layout->addWidget(recheekall,2,4,1,1);
  search_layout->addWidget(cheekall1,2,6,1,1);
  search_layout->addWidget(recheekall1,2,7,1,1);
  search_layout->addLayout(search_CenterMain_layout,3,0,16,18);
  search_layout->addLayout(search_bott_layout,19,5,1,1);

  connect(this->search,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_in);
  connect(this->removeall,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_removeall);
  connect(this->addIp,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_addip);
  connect(this->OK,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_OK);
  connect(this->Cancel,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_Cancel);
  connect(this->cheekall,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_cheek);
  connect(this->cheekall1,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_cheek1);
  connect(this->recheekall,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_recheek);
  connect(this->recheekall1,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_recheek1);
  connect(this->removeIp,&QPushButton::clicked,this,&NVR_Search_IPC_ui::on_search_removeip);

  QPalette thispain;
  QPixmap searh =QPixmap("./searh.png").scaled(this->size());
 // thispain.setColor(QPalette::Window,"#79f");
  thispain.setBrush(QPalette::Background,QBrush(searh));
  this->setPalette(thispain);
  thispain.setColor(QPalette::Base,"#aff");
  this->iPview->setPalette(thispain);
  this->iPview1->setPalette(thispain);

}
NVR_Search_IPC_ui::~NVR_Search_IPC_ui()
{

}

void NVR_Search_IPC_ui::on_search_in()
{
  //input Onvif Search adderss....Linker Onvif Model

 //Clear ListView Date Everyonce
  this->iPview->clear();
  for(int i =0 ; i<5 ; i++)
   {
      NVR_Search_IPC_ui_ipitem *isip =new NVR_Search_IPC_ui_ipitem ;
     this->ipblock = new QListWidgetItem(iPview);
     isip->setip(QString("192.168.1.%1").arg(i));
     std::string tmps = isip->IPLable->text().toStdString();
     strcpy(isip->thisIP.remark,tmps.c_str());
     tmps = isip->IP->text().toStdString();
     strcpy(isip->thisIP.IPCaddr,tmps.c_str());
     isip->thisIP.devnum = i+1;
     isip->thisIP.profilenum = i+1;
    strcpy( isip->thisIP.profile_name[i] ,QString("the uri name%1").arg(i).toStdString().c_str());
    strcpy( isip->thisIP.profile_uri[i] ,QString("the uri is %1").arg(i).toStdString().c_str());
     iPview->addItem(ipblock);
     iPview->setItemWidget(ipblock,isip);
     ipblock->setSizeHint(QSize(0,50));
     QPalette a;
    // a = isip->IP->palette();
     a.setColor(QPalette::Base,"#4c9");
     isip->IPLable->setPalette(a);
     isip->show();
   }

}

void NVR_Search_IPC_ui::on_search_removeall()
{
  this->iPview->clear();
  this->iPview1->clear();

}

void NVR_Search_IPC_ui::on_search_addip()
{
  for(int i=0;i<this->iPview->count();i++)
    {
     QListWidgetItem * tmp = iPview->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview->itemWidget(tmp);
     if(ntmp->itip->isChecked()== true)
   {
     NVR_Search_IPC_ui_ipitem *isip1 =new NVR_Search_IPC_ui_ipitem ;
    QListWidgetItem *ipblock1 = new QListWidgetItem(iPview1);
    isip1->setip( ntmp->IP->text());
    isip1->IPLable->setText(ntmp->IPLable->text());
    isip1->IPLable->setPalette(ntmp->IPLable->palette());
    isip1->thisIP.devnum = ntmp->thisIP.devnum;
    isip1->thisIP.profilenum = ntmp->thisIP.profilenum;
    strcpy(isip1->thisIP.profile_name[i], ntmp->thisIP.profile_name[i]);
    strcpy(isip1->thisIP.profile_uri [i],ntmp->thisIP.profile_uri[i]);
    std::string tmps =ntmp->IPLable->text().toStdString();
    strcpy(isip1->thisIP.remark,tmps.c_str());
    tmps = ntmp->IP->text().toStdString();
    strcpy(isip1->thisIP.IPCaddr,tmps.c_str());
    iPview1->addItem(ipblock1);
    iPview1->setItemWidget(ipblock1,isip1);
    ipblock1->setSizeHint(QSize(0,50));
    isip1->show();
    this->iPview->takeItem(i);
    i=-1;

   }
  }
}

void NVR_Search_IPC_ui::on_search_removeip()
{
  for(int i=0;i<this->iPview1->count();i++)
    {
     QListWidgetItem * tmp1 = iPview1->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview1->itemWidget(tmp1);
     if(ntmp->itip->isChecked()== true)
   {
    NVR_Search_IPC_ui_ipitem *isip1 =new NVR_Search_IPC_ui_ipitem ;
    QListWidgetItem *ipblock1 = new QListWidgetItem(iPview);
    isip1->setip( ntmp->IP->text());
    isip1->IPLable->setText(ntmp->IPLable->text());
    isip1->IPLable->setPalette(ntmp->IPLable->palette());
    isip1->thisIP.devnum = ntmp->thisIP.devnum;
    std::string tmps = isip1->IPLable->text().toStdString();
    strcpy(isip1->thisIP.remark,tmps.c_str());
    tmps = ntmp->IP->text().toStdString();
    strcpy(isip1->thisIP.IPCaddr,tmps.c_str());
    iPview->addItem(ipblock1);
    iPview->setItemWidget(ipblock1,isip1);
    ipblock1->setSizeHint(QSize(0,50));
    isip1->show();
    this->iPview1->takeItem(i);
    i=-1;
   }
    }
}

void NVR_Search_IPC_ui::on_search_cheek()
{
  for(int i=0;i<this->iPview->count();i++)
    {
     QListWidgetItem * tmp = iPview->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview->itemWidget(tmp);
     if(ntmp->itip->isChecked()!= true)
   {
     ntmp->itip->setChecked(true);
     i=-1;
   }
    }
}

void NVR_Search_IPC_ui::on_search_cheek1()
{
  for(int i=0;i<this->iPview1->count();i++)
    {
     QListWidgetItem * tmp = iPview1->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview1->itemWidget(tmp);
     if(ntmp->itip->isChecked()!= true)
      {
     ntmp->itip->setChecked(true);
     i=-1;
      }
   }
}

void NVR_Search_IPC_ui::on_search_OK()
{
   QSqlDatabase database;
  if (QSqlDatabase::contains("qt_sql_default_connection"))
  {
      database = QSqlDatabase::database("qt_sql_default_connection");
  }
  else
  {
     database = QSqlDatabase::addDatabase("QSQLITE");

     database.setDatabaseName("IP.db");
     // database.setUserName("admin");
    //  database.setPassword("admin");
      if (database.open() ){

          QSqlQuery query;
          query.exec("create table IP (id int primary key, "
                             "IP varchar ,Remark nvarchar , profilenum int , profileName1 nvarchar , profileName2 nvarchar , profileName3 nvarchar ,profiles1  nvarchar , profiles2 nvarchar , proflies3 nvarchar)");
        }
  }
  QSqlQuery querys;
  querys.exec("delete from IP");

  for (int i =0; i < iPview1->count();i++)
    {
     // qDebug()<<"保存中";
      QListWidgetItem * tmp1 = iPview1->item(i);
      NVR_Search_IPC_ui_ipitem * ntmp;
      ntmp= (NVR_Search_IPC_ui_ipitem *)iPview1->itemWidget(tmp1);
#ifdef DEBUG
     qDebug()<<ntmp->thisIP.devnum<<":"<<ntmp->thisIP.IPCaddr<<"::"<<ntmp->thisIP.remark;
#endif
     querys.exec(QString("insert into IP values(%1, '%2','%3',%4,'%5','%6','%7','%8','%9','%10' )").arg(i+1).arg(ntmp->IP->text()).arg(ntmp->IPLable->text()).arg(ntmp->thisIP.profilenum).arg(ntmp->thisIP.profile_name[0]).arg(ntmp->thisIP.profile_name[1]).arg(ntmp->thisIP.profile_name[2]).arg(ntmp->thisIP.profile_uri[0]).arg(ntmp->thisIP.profile_uri[1]).arg(ntmp->thisIP.profile_uri[2]));

    }

  QMessageBox ::information(this,tr("确认提示!"),QString(tr("【数据保存完毕】")),QMessageBox::Ok);
  querys.exec("select max(id) from IP");
  int max_id = 0 ;
  while(querys.next())
  {
  max_id = querys.value(0).toInt();
  qDebug()<<QString("max id:%1").arg(max_id);
  }

 database.removeDatabase("qt_sql_default_connection");
 database.close();

  this->close();

}

void NVR_Search_IPC_ui::on_search_Cancel()
{
  int i= QMessageBox::question(this,tr("退出提示！"),QString("【是否退出？】"),QMessageBox::Yes,QMessageBox::No);
  if (i==QMessageBox::Yes)
  this->close();
}

void NVR_Search_IPC_ui::on_search_recheek()
{
  for(int i=0;i<this->iPview->count();i++)
    {
     QListWidgetItem * tmp = iPview->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview->itemWidget(tmp);
     if(ntmp->itip->isChecked()== true)
   {
     ntmp->itip->setChecked(false);
     i=-1;
   }
}
}

void NVR_Search_IPC_ui::on_search_recheek1()
{
  for(int i=0;i<this->iPview1->count();i++)
    {
     QListWidgetItem * tmp = iPview1->item(i);
     NVR_Search_IPC_ui_ipitem * ntmp;
     ntmp= (NVR_Search_IPC_ui_ipitem *)iPview1->itemWidget(tmp);
     if(ntmp->itip->isChecked()== true)
   {
     ntmp->itip->setChecked(false);
     i=-1;
   }
}
}

NVR_Search_IPC_ui_ipitem::NVR_Search_IPC_ui_ipitem(QWidget *parent)
  :QWidget(parent)
{
  this->IP = new QLabel ;
  this->IPLable = new QLineEdit;
  this->iplayout = new QHBoxLayout;
  this->itip = new QCheckBox;
 // this->IP->resize(64,32);
  //this->IPLable->resize(64,32);
  iplayout->addWidget(itip);
  iplayout->addWidget(IP);
  iplayout->addWidget(IPLable);
  this->setLayout(iplayout);

}

NVR_Search_IPC_ui_ipitem::~NVR_Search_IPC_ui_ipitem()
{

}
