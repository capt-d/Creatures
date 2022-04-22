#include <QtWidgets/QApplication>
#include "MainWindow.hpp"
#include <QtWidgets/QMessageBox>

int main(int argc, char *argv[])
{
  //Q_INIT_RESOURCE(application);
  
  QApplication a(argc, argv);
  Ui::MainWindow okno;
  QObject::connect(&a, SIGNAL(focusChanged(QWidget*,QWidget*)), &okno, SLOT(focusChanged(QWidget*,QWidget*)));
  okno.show();
  int result; 
  try 
  {
	 result = a.exec();
  }
  catch (std::exception &e)
  {
	  QMessageBox msg;
      msg.setText("Exception on main");
      msg.exec();
	  result = -1;
  }
  return result; 
}
