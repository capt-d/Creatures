/********************************************************************************
** Form generated from reading UI file 'Main.ui_kopia'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Main_H
#define UI_Main_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "MapGenerator.hpp"
#include "UIntValidator.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow: public QMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *start;
    QPushButton *stop;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *set_torus;
    QPushButton *init_board;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *szerokoLabel;
    QLineEdit *cols;
    QLabel *wysokoLabel;
    QLineEdit *rows;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_3;
    QLabel *procentYwychLabel;
    QLineEdit *percent;
    QFormLayout *formLayout_2;
    QLabel *iloWTkWLabel;
    QLineEdit *threads_count;
    QSpacerItem *verticalSpacer;
    
    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);
};

namespace Ui {
    class Picture;
 
    class MainWindow: public Ui_MainWindow {
      Q_OBJECT
           
          private: 
            std::unique_ptr<MapGenerator> map_gen;
            UIntValidator *ui_validator = NULL;
            QDoubleValidator *percent_validator = NULL;
            Picture *obraz = NULL;
            
            void preinit_game_setup(void);
            void init_game(void);            
            void stop_game(void);
            
            void enable_init(void);
            void enter_next(void);
            void zakoncz(void);
            void show_image(void);
             
        public slots:  
             void focusChanged(QWidget*, QWidget*); 
		 void generate(void);
			 
        
        public: 
         MainWindow();
         ~MainWindow();   
  };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Main_H
