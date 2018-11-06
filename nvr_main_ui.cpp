#include "nvr_main_ui.h"

NVR_main_ui::NVR_main_ui(QWidget *parent)
  : QWidget(parent)
{
  this->resize(QSize(720,574));
  QGridLayout *MainLaouty = new QGridLayout(this);
  // setWindowOpacity(0.9); //Set Windows alpha
  // Widgets init
  search_IPC_button =new QPushButton(this);
  SetVideo_to_Layout_button = new QPushButton(this);
  Video_Set_button = new QPushButton(this);
  Sys_Set_button = new QPushButton(this);
  OK_button = new QPushButton(this);
  Cancel_button = new QPushButton(this);
  search_IPC_button->setObjectName(tr("IPC"));
  SetVideo_to_Layout_button->setObjectName(tr("V_Layout"));
  //SetVideo_to_Layout_button->setText(tr("视频参数设置"));
  OK_button->setObjectName(tr("main_OK"));
 // OK_button->setText(tr("OK"));
  Cancel_button->setObjectName(tr("main_Cancel"));
 // Cancel_button->setText(tr("Cancel"));

   search_IPC_button->setIcon(QIcon("./IPC1.png"));
   search_IPC_button->setIconSize(QSize(96,96));
   search_IPC_button->setFlat(true);//关闭按钮框
   SetVideo_to_Layout_button->setIcon(QIcon("./Layout.png"));
   SetVideo_to_Layout_button->setFlat(true);
   SetVideo_to_Layout_button->setIconSize(QSize(96,96));
   Video_Set_button->setIcon(QIcon("./VideoSet.png"));
   Video_Set_button->setFlat(true);
   Video_Set_button->setIconSize(QSize(96,96));
   Sys_Set_button->setIcon(QIcon("./SysSet.png"));
   Sys_Set_button->setFlat(true);
   Sys_Set_button->setIconSize(QSize(96,96));
   OK_button->setIcon(QIcon("./OK.png"));
   OK_button->setFlat(true);
   OK_button->setIconSize(QSize(96,96));
   Cancel_button->setIcon(QIcon("./Cancel.png"));
   Cancel_button->setFlat(true);
   Cancel_button->setIconSize(QSize(96,96));

  connect(this->search_IPC_button,&QPushButton::clicked,this,&NVR_main_ui::Power_Ipc_ui);
  connect(this->SetVideo_to_Layout_button,&QPushButton::clicked,this,&NVR_main_ui::Power_Layout_ui);

  Systime = new  QDateTimeEdit(this);
  Systime->setDateTime(QDateTime::currentDateTime());
  Systime->setDisplayFormat(tr("yyyy年MM月dd日ddd hh时mm分ss秒"));
  Systime->setSizeIncrement(26,46);
  Timeedit = new QLabel(this);
  Timeedit->setText(tr("日期时间设置："));
  Timeedit->setFont(QFont(tr("微软雅黑"),12));

  MainLaouty->setObjectName(tr("Main_layout"));
  MainLaouty->addWidget(search_IPC_button,0,0,1,1);
  MainLaouty->addWidget(SetVideo_to_Layout_button,0,1,1,1);
  MainLaouty->addWidget(Video_Set_button,1,0,1,1);
  MainLaouty->addWidget(Sys_Set_button,1,1,1,1);
  MainLaouty->addWidget(OK_button,3,0,1,1);
  MainLaouty->addWidget(Cancel_button,3,1,1,1);
  MainLaouty->addWidget(Systime,2,1,1,1);
  MainLaouty->addWidget(Timeedit,2,0,1,1);

  // Widgets Color Set
  QPalette mainpale ;
  //mainpale = search_IPC_button->palette();
 //mainpale.setColor(QPalette::Button,Qt::black);
 // mainpale.setColor(QPalette::ButtonText,"#fff");

  search_IPC_button->setPalette(mainpale);

}

NVR_main_ui::~NVR_main_ui()
{

}

void NVR_main_ui::Power_Ipc_ui()
{
   NVR_Search_IPC_ui *sui =new NVR_Search_IPC_ui();
   sui->setWhatsThis(tr("搜索IPC...."));
   sui->setModal(true);
   sui->show();


}

void NVR_main_ui::Power_Layout_ui()
{
   NVR_Video_layout_ui *sui =new NVR_Video_layout_ui;
   sui->setWhatsThis(tr(" Layout The IPC...."));
   sui->setModal(true);
   sui->show();


}

