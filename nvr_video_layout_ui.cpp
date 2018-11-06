#include"nvr_main_ui.h"
/********
 * This Layout UI Sources file *
  *******/
NVR_Video_layout_ui::NVR_Video_layout_ui(QDialog *parent)
  :QDialog(parent)
{
  this->setWindowTitle("IPC 布局窗");
 // this->setMaximumSize(640,480);
  this->setMinimumSize(64,48);
  this->resize(770,574);


//  this->MainScecn = new LayoutScene;
 // this->MainView = new ViewLayout;
//  this->ViewItem = new viewItem;
  this->CheekLayout = new QComboBox;
  this->Cheekboutt_layout = new QHBoxLayout;
  this->Physical_channel = new QComboBox;
  this->Main_layout = new QGridLayout;
  this->Graphics_View_layout = new QVBoxLayout;
  this->viewip = new QPushButton;
  this->OK = new QPushButton;
  this->Cancel = new QPushButton;
  this->IPList_layout = new QVBoxLayout;
  this->ipview_t = new QTableView;

  CheekLayout->addItem(QString(tr("单画面")));
  CheekLayout->addItem(QString(tr("四画面")));
  CheekLayout->addItem(QString(tr("九画面")));
  CheekLayout->addItem(QString(tr("十六画面")));

  Physical_channel->addItem(QString(tr("通道一")));
  Physical_channel->addItem(QString(tr("通道二")));
  OK->setIcon(QIcon("./OK.png"));
  OK->setFlat(true);
  OK->setIconSize(QSize(72,72));
  Cancel->setIcon(QIcon("./Cancel.png"));
  Cancel->setFlat(true);
  Cancel->setIconSize(QSize(72,72));
  viewip->setText(QString(tr("刷新")));


  this->MainScecn =new LayoutScene;
  this->ViewItem = new viewItem(Glable_View_X,Glable_View_Y,1);
  this->MainView = new ViewLayout(this);


  MainScecn->addItem(ViewItem);
  ViewItem->setPos(0,0);
  MainView->setScene(MainScecn);
  MainView->setBackgroundBrush(QColor(0,0,0));
  MainView->resize(Glable_View_X, Glable_View_Y);
  MainView->show();

  ipview_t->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ipview_t->setContextMenuPolicy(Qt::CustomContextMenu);
  ipview_t->setSelectionBehavior(QAbstractItemView::SelectRows);
  ipview_t->setSelectionMode(QAbstractItemView::SingleSelection);

  IPList_layout->addWidget(ipview_t);
  Cheekboutt_layout ->addWidget(CheekLayout);
  Cheekboutt_layout->addWidget(Physical_channel);
  Graphics_View_layout->addWidget(MainView);

  Main_layout->addLayout(Cheekboutt_layout,0,0,1,1);
  Main_layout->addWidget(viewip,1,0,1,1);
  Main_layout->addLayout(IPList_layout,2,0,1,1);
  Main_layout->addLayout(Graphics_View_layout,2,1,1,1);
  Main_layout->addWidget(this->OK,3,0,1,1);
  Main_layout->addWidget(this->Cancel,3,1,1,1);
  this->setLayout(Main_layout);
   view_windows<<menu.addAction(QString("画面1"));

  connect(this->viewip,&QPushButton::clicked,this,&NVR_Video_layout_ui::on_ViewIpList_in);
  connect(this->ipview_t,&QTableView::customContextMenuRequested,this,&NVR_Video_layout_ui::on_LayoutScens_in);
  connect(this->CheekLayout,QOverload<int>::of (&QComboBox::currentIndexChanged),this,&NVR_Video_layout_ui::on_LayoutViewScens_in);
  connect(this,&NVR_Video_layout_ui::paniterview,this,&NVR_Video_layout_ui::on_PaintIPView);
  connect(this->OK,&QPushButton::clicked,this,&NVR_Video_layout_ui::on_OK_in);
  connect(this->Cancel,&QPushButton::clicked,this,&NVR_Video_layout_ui::on_Cancel_in);
  connect(this->Physical_channel,QOverload<int>::of (&QComboBox::currentIndexChanged),this,&NVR_Video_layout_ui::on_Physical_in);

}

void NVR_Video_layout_ui::on_ViewIpList_in()
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
     if (!database.open() ){
#ifdef DEBUG
         qDebug()<<"QSLite Qpen  Fault ";
#endif
       }
 }
  QSqlTableModel *mode = new QSqlTableModel(this);
   mode->setTable("IP");
   mode->select();
   this->ipview_t->setModel(mode);
   database.removeDatabase("qt_sql_default_connection");
   database.close();


}
/****
 * Set And View IP View Layout *
****/
void NVR_Video_layout_ui::on_LayoutScens_in(QPoint pos)
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
     if (!database.open() ){
#ifdef DEBUG
         qDebug()<<"QSLite Qpen  Fault ";
#endif
       }
 }

      static QSqlQueryModel supplymodel(this->ipview_t);
      supplymodel.setQuery(QString("select * from IP;"));
      int row = this->ipview_t->currentIndex().row();
      QSqlRecord record = supplymodel.record(row);

      QList<QAction*>::iterator iter;
      selectedAction = menu.exec(QCursor::pos());
      int ischange =1;
      if (this->CheekLayout->currentIndex() == 0 ) ischange=1;
      if (this->CheekLayout->currentIndex() == 1)  ischange=4;
      if (this->CheekLayout->currentIndex() == 2)  ischange=9;
      if (this->CheekLayout->currentIndex() == 3)  ischange=16;

      int isview = 1;
      int uriindex =7 ;
      for(iter =view_windows.begin() ; iter != view_windows.end(); iter ++ )
        {
           if(selectedAction == *iter)
             {

               if (record.value(3).toInt() > 0)
                 {
                   for (int iu=0 ,num =4; iu<record.value(3).toInt();iu++,num++)
                     {
                       this_uri << isuri.addAction((QString("%1").arg(record.value(num).toString())));
                     }
                   QList<QAction*>::iterator uriter;
                   int  nums= 0;
                   selectedActionuri = isuri.exec(QCursor::pos());
                   for(uriter = this_uri.begin() ; uriter != this_uri.end() ; uriter++)
                     {
                       if(selectedActionuri == *uriter)
                         {
                           if(nums == 0)
                             uriindex=7;
                           if(nums == 1)
                             uriindex=8;
                           if(nums == 2)
                             uriindex=9;
                            (*iter)->setEnabled(false);
            emit  this->paniterview(record.value(1).toString(),record.value(uriindex).toString(),record.value(2).toString(),isview,record.value(uriindex - 3).toString(),ischange,iter);

                          break;
                         }
                      nums++;
                     }

                       this_uri.clear();
                       isuri.clear();
                 }
   //  This Plant ViewLayout to NVR System Config ....
#ifdef DEBUG
               qDebug()<<"选中了画面:"<<isview<<record.value(1).toString()<<record.value(2).toString()\
                      <<record.value(3).toInt()<<record.value(uriindex).toString();
#endif
             }

               isview++;
        }
      database.removeDatabase("qt_sql_default_connection");
      database.close();

}

void NVR_Video_layout_ui::on_LayoutViewScens_in(int index)
{

  this->MainScecn->clear();
  int i =1;
  if (index == 0 ) i=1;
  if (index == 1)  i=4;
  if (index == 2)  i=9;
  if (index == 3)  i=16;
   view_windows.clear();
   menu.clear();

   for(int is =0; is<i ; is++ )
     {
       view_windows<<menu.addAction(QString("画面%1").arg(is+1));
     }

  ViewItem =new viewItem(Glable_View_X,Glable_View_Y,i);
  MainScecn->addItem(ViewItem);
  ViewItem->setPos(0,0);
  MainView->setScene(MainScecn);
  MainView->setBackgroundBrush(QColor(0,0,0));
  MainView->show();

}

void NVR_Video_layout_ui::on_PaintIPView(QString ip, QString uri , QString Iprmark, int view, QString proname , int totalviews , QList<QAction *>::iterator theiter)
{
  int Yposunit =0;
  int Xposunit = 0;
  double rownum =1;
  rownum = sqrt(totalviews);
  if ( 0.0<=(double)(view/rownum) && (double)(view/rownum)<=1.0 )
    Yposunit = 0;
  if( 1.0<(double)(view/rownum) && (double) ( view/rownum)<=2.0 )
    Yposunit = 1;
  if( 2.0<(double)(view/rownum) && (double)(view/rownum) <=3.0 )
    Yposunit = 2 ;
  if( 3.0<(double)(view/rownum) &&  (double)(view/rownum) <=4.0 )
    Yposunit = 3 ;
  Xposunit = (int) (view%(int)rownum) -1 ;
  if (view%(int)rownum == 0 )
     Xposunit = rownum -1 ;
  if(rownum == 1 )
    Xposunit = 0 ;
 double w = (Glable_View_X/ rownum) ;
 double h =  (Glable_View_Y/rownum) ;
 double px =Xposunit * w;
 double py =Yposunit *h;
 qDebug() << "X:"<<Glable_View_X<<"Y:"<<Glable_View_Y<<"rect w"<<w <<"rect h" <<h <<"ponit"<<Xposunit<<","<<Yposunit <<":::"<<(double)view/rownum;
  IPItem *item = new IPItem(ip,uri,Iprmark,view,proname,totalviews,px+1,py+1,w-2,h-2,theiter);
  item->setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
  IPTextview * ipitem = new IPTextview(w,h,px,py,ip,Iprmark,uri);
  ipitem->setParentItem(item);
 // item->setPos(px,py);
  this->MainScecn->addItem(item);
  this->MainScecn->addItem(ipitem);
  this->MainView->setScene(MainScecn);
  MainView->updateSceneRect(QRect(0,0,Glable_View_X,Glable_View_Y));

  MainView->show();
  update();
}

void NVR_Video_layout_ui::on_Physical_in()
{
 this->CheekLayout->setCurrentIndex(0);
 emit  this->CheekLayout->currentIndexChanged(0);

}

void NVR_Video_layout_ui::on_OK_in()
{
  QSqlDatabase database;
 if (QSqlDatabase::contains("qt_sql_default_connection"))
 {
     database = QSqlDatabase::database("qt_sql_default_connection");
 }
 else
 {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("Layout.db");
     if (database.open() ){

         QSqlQuery query;
         query.exec("create table IP_Layout (id int primary key, "
                    "channel int,IP varchar ,Remark nvarchar , totalViews int , thisview int ,profileName nvarchar,  profile  nvarchar  )");
       }
 }
     QSqlQuery querys;
   querys.exec("insert into IP_Layout values ( 1 ,2 )");

   querys.exec("select max(id) from IP_Layout");
   int max_id = 0 ;
   while(querys.next())
   {
   max_id = querys.value(0).toInt();
#ifdef DEBUG
   qDebug()<<QString("max id:%1").arg(max_id);
#endif
   }

}

void NVR_Video_layout_ui::on_Cancel_in()
{
  this->close();

}

NVR_Video_layout_ui::~NVR_Video_layout_ui()
{


}


viewItem::viewItem()
{

}

viewItem::viewItem( int x, int y, int Num)
{
  this->x =x;
  this->y =y;
  this->Num =Num;
}

void viewItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
      int   x=this->x , y=this->y , Num=this->Num;
      QPen thepen(QColor(255,255,255),1,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin);
      painter->setPen(thepen);
      painter->drawRect(0, 0, x, y);
      int drawLines =0 ;
       if  (Num==4)
        drawLines =1;
     else if (Num==9)
        drawLines =2;
     else if (Num==16)
        drawLines = 3;
      else if (Num == 1)
        drawLines = 0;

   for(int i = 1 ;i<=drawLines;i++)
     {
              painter->drawLine(QPoint(0,y/(drawLines+1)*i),QPoint(x,y/(drawLines+1)*i));
              painter->drawLine(QPoint(x/(drawLines+1)*i,0),QPoint(x/(drawLines+1)*i,y));
      }
}

QRectF viewItem::boundingRect()const
{
  qreal penWidth = 1;
  return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                20 + penWidth, 20 + penWidth);
}

 viewItem::~viewItem()
{

}


ViewLayout::ViewLayout(QDialog *parent )
  :QGraphicsView(parent)
{
  this->setAcceptDrops(true);
  this->viewport()->repaint(0,0,Glable_View_X,Glable_View_Y);
}
/*
void ViewLayout::mousePressEvent(QMouseEvent *event)
{
    // 分别获取鼠标点击处在视图、场景和图形项中的坐标，并输出
    QPoint viewPos = event->pos();
    qDebug() << "viewPos: " << viewPos;
    QPointF scenePos = mapToScene(viewPos);
    qDebug() << "scenePos: " << scenePos;
    QGraphicsItem *item = scene()->itemAt(scenePos, QTransform());
    if (item) {
        QPointF itemPos = item->mapFromScene(scenePos);
        qDebug() << "itemPos: " << itemPos;
    }
}
*/
/*
void ViewLayout::mouseMoveEvent(QMouseEvent *event)
{

}
*/


void ViewLayout::mouseDoubleClickEvent(QMouseEvent  *event)
{
  QPoint viewPos = event->pos();
  qDebug()<<"doubleClickEvent:"<<viewPos;

}


ViewLayout::~ViewLayout()
{

}

LayoutScene::LayoutScene(QGraphicsScene *parent )
  :QGraphicsScene(parent)
{
  this->setSceneRect(0,0,Glable_View_X,Glable_View_Y);
}

void LayoutScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->accept();
}

void LayoutScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{

}

LayoutScene::~LayoutScene()
{

}

IPItem::IPItem()
{

}

IPItem:: IPItem(QString ip, QString uri , QString Iprmark, int view, QString proname, int totalviews, double px, double py, double w, double h, QList<QAction*>::iterator theiter  )
{
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFlag(QGraphicsItem::ItemIsMovable);
  setAcceptHoverEvents(true);

  this->IP = ip;
  this->URI = uri;
  this->IPRmark = Iprmark ;
  this->thisview = view;
  this->profilename = proname;
  this->totalview = totalviews;
  this->PX = px;
  this->PY = py;
  this->Rect_W = w;
  this->Rect_H = h;
  this->thisiter = theiter;
  this->setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
  this->setPos(px,py);
}

QRectF IPItem::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-10 - adjust, -10 - adjust,
                  Rect_W+1 + adjust, Rect_H+1 + adjust);
}

void IPItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setBrush(brushColor);
    painter->drawRect(0,0,Rect_W,Rect_H);

}

// 鼠标按下事件处理函数，设置被点击的图形项获得焦点，并改变光标外观
void IPItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
}

// 悬停事件处理函数，设置光标外观和提示
void IPItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip(QString("IP:%1").arg(this->IP));

}
// 右键菜单事件处理函数，为图形项添加一个右键菜单
void IPItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *moveAction = menu.addAction("move back");
    QAction *deletethis = menu.addAction("delete This IP");
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction) {
        setPos(0, 0);
    }
    if(selectedAction == deletethis)
      {
        this->setFlag(QGraphicsItem::ItemIsSelectable);
        this->setSelected(true);
        delete this;
        (*thisiter)->setEnabled(true);
      }
}


IPTextview::IPTextview(double rect_w , double rect_h, double x, double y, QString ip, QString mark, QString Uri)
{
  this->w = rect_w /2;
  this->h = rect_h/3;
  this->px = x+2 ;
  this ->py = y +1;
  this->IP = ip;
  this->uri = Uri;
  this->Mark = mark;
  this->setFont(QFont("华文正楷",15));
  this->setPlainText(IP);
 // this->setPos(1,1);
  this->setDefaultTextColor(QColor(255,255,255));
}

QRectF IPTextview::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-10 - adjust, -10 - adjust,
                  w+2 + adjust, h+2 + adjust);
}

void IPTextview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

 // this->setPlainText(IP);

  painter->setBrush(QColor(152,255,255));
  painter->drawText(QPoint(10,10),IP);
  painter->drawText(QPoint(10,25),Mark);
  painter->drawText(QPoint(10,40),uri);
}
