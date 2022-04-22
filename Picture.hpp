/********************************************************************************
** Form generated from reading UI file 'Picture.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Picture_H
#define UI_Picture_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QCloseEvent>
#include <memory>
QT_BEGIN_NAMESPACE

class Ui_Picture: public QWidget
{
Q_OBJECT
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *scale_label;
    QSpinBox *scale_value;
    QLabel *pause_label;
    QSpinBox *pause_factor;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *all_lives;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pause_button;
    QPushButton *end_button;

    void setupUi(QWidget *);
    void retranslateUi(QWidget*);
  
signals: 
    virtual void closeEvent(QCloseEvent *event) = 0;
    virtual void mousePressEvent(QMouseEvent *ev) = 0;
};

namespace Ui {
    class Picture: public Ui_Picture {
    
    Q_OBJECT
      public:
        Picture(std::shared_ptr<const unsigned char[]> _data, unsigned int cols, unsigned int rows);
        ~Picture();

      signals:
        void closeEvent(QCloseEvent *event);
        //void resizeEvent(QResizeEvent *event);
        void mousePressEvent(QMouseEvent *ev);
		void callculate(void);
		
      private:
        QImage *image = NULL;
		std::shared_ptr<const unsigned char[]> image_data;
		QTimer *timer = NULL;
        void refresh(void);
        QSize max_size;
        QSize min_size;
        unsigned long long run;
        QString window_title;
      
      private slots:
        void pause_changed(int _value);
        void run_stop(void);
        void ustaw_wielkosc(void);
  };

} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Picture_H
