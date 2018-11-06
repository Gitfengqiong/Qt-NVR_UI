#include "nvr_main_ui.h"
#include <QApplication>
#include <QStyle>
#include <QStyleFactory>
#include <fusion.h>
#include <windows.h>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setStyle(QStyleFactory::create("windows"));
  NVR_main_ui w;
  w.setWindowTitle("NVR 主窗口");
  /*
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("IP.db");
  //db.setUserName("admin");
 // db.setPassword("admin");
  if (!db.open()) {
     QMessageBox::critical(0, "Cannot open database1",
                           "Unable to establish a database connection.", QMessageBox::Cancel);
     return false;
      }
 QSqlQuery query(db);
 query.exec("create table IP (id int primary key, "
                    "IP varchar ,Remark nvarchar , profilenum int ,profileName1 nvarchar ,profileName2 nvarchar , profileName3 nvarchar ,  profiles1  nvarchar , profiles2 nvarchar , proflies3 nvarchar)");

//db.close();

/*
 QSqlDatabase dbs = QSqlDatabase::addDatabase("QSQLITE","NVR_Data");
 dbs.setDatabaseName("IP_Layout.db");
 dbs.setUserName("admin");
 dbs.setPassword("admin");
 dbs.open();
 QSqlQuery quers(dbs);
 quers.exec("create table IP_Layout (id int primary key, "
            "physical int , IP varchar ,Remark nvarchar , totalViews int , thisview int ,profileName nvarchar,  profile  nvarchar  )");
dbs.close();
//quers.clear();
*/
 QPalette Mainpale;
  QPixmap windows_pix = QPixmap("./windows.png").scaled(w.size());
 Mainpale =w.palette();
//  Mainpale.setColor(QPalette::Window,"#39f");
 // Mainpale.setColor(QPalette::);
  Mainpale.setBrush(QPalette::Background,QBrush(windows_pix));
  w.setPalette(Mainpale);
  w.show();

  return a.exec();
}
