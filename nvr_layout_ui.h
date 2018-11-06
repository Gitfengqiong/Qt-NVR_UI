#ifndef NVR_LAYOUT_UI_H
#define NVR_LAYOUT_UI_H
//#include "nvr_main_ui.h"
#include <QObject>
#include <QRect>
#include <QMouseEvent>
#include<QPainter>
#include <QGraphicsItem>
#include<QPen>
#include<QComboBox>
#include<QStackedWidget>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QSplitter>
#include<QDebug>
#include<QRect>
#include<QList>
#include<QMenu>
#include<QAction>
#include<QGraphicsSceneContextMenuEvent>
//#include<QGraphicsScenePrivate>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include<QTime>
#include<QSqlRecord>
#include<QtCore/qmath.h>

/*
QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
QString select_max_sql = "select max(id) from IP";
QString insert_sql = "insert into student values (?, ?, ?)";
QString update_sql = "update student set name = :name where id = :id";
QString select_sql = "select id, name from student";
QString select_all_sql = "select * from student";
QString delete_sql = "delete from student where id = ?";
QString clear_sql = "delete from student";
*/
/*
 *
//查询最大id
int max_id = 0;
sql_query.prepare(select_max_sql);
if(!sql_query.exec())
{
qDebug()<<sql_query.lastError();
}
else
{
while(sql_query.next())
{
max_id = sql_query.value(0).toInt();
qDebug()<<QString("max id:%1").arg(max_id);
}
}

 * */
typedef struct PROFILESTREAMURI
{   char  IPCaddr[30] ;
     int   devnum =0 ;
     int   profilenum =0 ;
     char  profile_name[5][20] ={"NULL","NULL","NULL","NULL","NULL"};
     char  profile_uri[5][254] = {"NULL","NULL","NULL","NULL","NULL"};
       char  remark[256]={'\0'};
} TOURI_S;

#define Glable_View_X  360
#define Glable_View_Y  287

 class layout_event :public QMouseEvent
 {


 };


 class viewItem:public QGraphicsItem
 {

public:
   viewItem( );
   viewItem(int x, int y , int Num);
   ~viewItem();


   int  x= 400;
   int  y =300 ;
   int Num = 16;
   QRectF  boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
              QWidget *widget);

 };


 class IPItem :public QGraphicsItem
 {
 public:
   IPItem();
   IPItem(QString ip, QString uri , QString Iprmark, int view, QString proname ,int totalviews ,double px,double py,double w,double h,  QList<QAction*>::iterator theiter);
   QString IP;
   int thisview;
   QString profilename;
   QString URI;
   QString IPRmark;
   int totalview;
   QPoint thispoint;
   double PX;
   double PY;
   double Rect_W;
   double Rect_H;
   QList<QAction*>::iterator thisiter;
   QRectF  boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
              QWidget *widget );
   void setColor(const QColor &color) { brushColor = color; }

protected:
   // 悬停事件处理函数，设置光标外观和提示
   void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
   // 右键菜单事件处理函数，为图形项添加一个右键菜单
   void  contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
   // 鼠标按下事件处理函数，设置被点击的图形项获得焦点，并改变光标外观
   void mousePressEvent(QGraphicsSceneMouseEvent *);

 private:
   QColor brushColor;

 };


 class  ViewLayout:public QGraphicsView
 {

   Q_OBJECT
public:
   ViewLayout(QDialog *parent = 0);
   ~ViewLayout();

   //  void mousePressEvent(QMouseEvent *event);
 //    void mouseMoveEvent(QMouseEvent *event);
     void mouseDoubleClickEvent(QMouseEvent *event);
    // void  dragEnterEvent(QDragEnterEvent *event);

  signals:
  void PaintIpView() ;

 };

 class LayoutScene:public QGraphicsScene
 {
   Q_OBJECT
 public:
   LayoutScene(QGraphicsScene *parent = 0);
   ~LayoutScene();


 //  void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
   void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
   void  dropEvent(QGraphicsSceneDragDropEvent *event);

 };

class IPTextview : public QGraphicsTextItem
{
  Q_OBJECT
public:
  IPTextview(double rect_w ,double rect_h , double x , double y ,  QString ip ,QString mark ,QString Uri);
  double w;
  double h ;
  double px;
  double py;
  QString IP;
  QString uri;
  QString Mark;
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};


#endif // NVR_LAYOUT_UI_H
