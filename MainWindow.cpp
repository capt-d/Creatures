//#include <math.h>

#include <QtWidgets/QMessageBox>
#include <QTimer>
#include "MainWindow.hpp"
#include "Picture.hpp"

void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(200, 250);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(200, 250));
        MainWindow->setMaximumSize(QSize(200, 250));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 200, 250));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        start = new QPushButton(gridLayoutWidget);
        start->setObjectName(QStringLiteral("start"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy1);
        start->setMinimumSize(QSize(50, 20));
        start->setMaximumSize(QSize(50, 20));
        start->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(start);

        stop = new QPushButton(gridLayoutWidget);
        stop->setObjectName(QStringLiteral("stop"));
        sizePolicy1.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy1);
        stop->setMinimumSize(QSize(50, 20));
        stop->setMaximumSize(QSize(50, 20));
        stop->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(stop);


        gridLayout->addLayout(horizontalLayout_6, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);

        set_torus = new QCheckBox(gridLayoutWidget);
        set_torus->setObjectName(QStringLiteral("set_torus"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(set_torus->sizePolicy().hasHeightForWidth());
        set_torus->setSizePolicy(sizePolicy2);
        set_torus->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(set_torus, 5, 1, 1, 1);

        init_board = new QPushButton(gridLayoutWidget);
        init_board->setObjectName(QStringLiteral("init_board"));
                sizePolicy1.setHeightForWidth(init_board->sizePolicy().hasHeightForWidth());
        init_board->setSizePolicy(sizePolicy1);
        init_board->setMinimumSize(QSize(50, 20));
        init_board->setMaximumSize(QSize(50, 20));
        init_board->setLayoutDirection(Qt::RightToLeft);
        init_board->setAutoDefault(true);
        init_board->setDefault(false);

        gridLayout->addWidget(init_board, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(6, 6, 6, 6);
        szerokoLabel = new QLabel(gridLayoutWidget);
        szerokoLabel->setObjectName(QStringLiteral("szerokoLabel"));
        sizePolicy2.setHeightForWidth(szerokoLabel->sizePolicy().hasHeightForWidth());
        szerokoLabel->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::LabelRole, szerokoLabel);

        cols = new QLineEdit(gridLayoutWidget);
        cols->setObjectName(QStringLiteral("cols"));
        cols->setMinimumSize(QSize(100, 0));
        cols->setMaximumSize(QSize(100, 20));
        cols->setSizeIncrement(QSize(100, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, cols);

        wysokoLabel = new QLabel(gridLayoutWidget);
        wysokoLabel->setObjectName(QStringLiteral("wysokoLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, wysokoLabel);

        rows = new QLineEdit(gridLayoutWidget);
        rows->setObjectName(QStringLiteral("rows"));
        rows->setMinimumSize(QSize(100, 20));
        rows->setMaximumSize(QSize(100, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, rows);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(6, 6, 6, 6);
        procentYwychLabel = new QLabel(gridLayoutWidget);
        procentYwychLabel->setObjectName(QStringLiteral("procentYwychLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, procentYwychLabel);

        percent = new QLineEdit(gridLayoutWidget);
        percent->setObjectName(QStringLiteral("percent"));
        percent->setMinimumSize(QSize(50, 20));
        percent->setMaximumSize(QSize(50, 20));
        percent->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, percent);


        gridLayout->addLayout(formLayout_3, 4, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, 6, 6, 6);
        iloWTkWLabel = new QLabel(gridLayoutWidget);
        iloWTkWLabel->setObjectName(QStringLiteral("iloWTkWLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, iloWTkWLabel);

        threads_count = new QLineEdit(gridLayoutWidget);
        threads_count->setObjectName(QStringLiteral("threads_count"));
        threads_count->setText("0");
        sizePolicy1.setHeightForWidth(threads_count->sizePolicy().hasHeightForWidth());
        threads_count->setSizePolicy(sizePolicy1);
        threads_count->setMinimumSize(QSize(50, 20));
        threads_count->setMaximumSize(QSize(50, 20));
        threads_count->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, threads_count);


        gridLayout->addLayout(formLayout_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    
  setTabOrder(cols, rows);
  setTabOrder(rows, init_board);
  setTabOrder(init_board, threads_count);
  setTabOrder(threads_count, percent);
  setTabOrder(percent, set_torus);
  setTabOrder(set_torus, start); 


} // setupUi

void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
  //MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Conway's game of life", Q_NULLPTR));
  MainWindow->setWindowTitle(QString("%1").arg(CHAR_BIT));
  start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
  stop->setText(QApplication::translate("MainWindow", "Zamknij", Q_NULLPTR));
  set_torus->setText(QApplication::translate("MainWindow", "Zawijanie krawedzi", Q_NULLPTR));
  init_board->setText(QApplication::translate("MainWindow", "Tw\303\263rz", Q_NULLPTR));
  szerokoLabel->setText(QApplication::translate("MainWindow", "Szeroko\305\233\304\207", Q_NULLPTR));
  wysokoLabel->setText(QApplication::translate("MainWindow", "Wysoko\305\233\304\207", Q_NULLPTR));
  procentYwychLabel->setText(QApplication::translate("MainWindow", "Procent \305\274ywych", Q_NULLPTR));
  percent->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
  iloWTkWLabel->setText(QApplication::translate("MainWindow", "Ilo\305\233\304\207 w\304\205tk\303\263w", Q_NULLPTR));
} // retranslateUi


Ui::MainWindow::MainWindow():Ui_MainWindow()
{
  setupUi(this);
  ui_validator = new UIntValidator(this); 
  percent_validator = new QDoubleValidator(0.0001, 99.9999, 4, this);
  if (ui_validator == NULL or percent_validator == NULL)
  {
      QMessageBox msg;
      msg.setText("Insufficient memory [ui_validator or percent_validator]");
      msg.exec();
      close();
  }
  QString str = QString("Min: 100, Max: %2").arg(std::numeric_limits<unsigned int>::max());
  szerokoLabel->setToolTip(str);
  szerokoLabel->setToolTipDuration(1500);
  wysokoLabel->setToolTip(str);
  wysokoLabel->setToolTipDuration(1500);
  cols->setValidator(ui_validator);
  rows->setValidator(ui_validator);
  threads_count->setValidator(ui_validator);
  percent->setValidator(percent_validator);
  preinit_game_setup();
  
  connect(cols, &QLineEdit::returnPressed, this, &Ui::MainWindow::enter_next); 
  connect(rows, &QLineEdit::returnPressed, this, &Ui::MainWindow::enter_next);
  connect(cols, &QLineEdit::textEdited, this, &Ui::MainWindow::enable_init);
  connect(rows, &QLineEdit::textEdited, this, &Ui::MainWindow::enable_init);
  connect(init_board, &QPushButton::clicked, this, &Ui::MainWindow::init_game);
  connect(start, &QPushButton::clicked, this, &Ui::MainWindow::show_image);

  connect(threads_count, &QLineEdit::returnPressed, this, &Ui::MainWindow::enter_next);
  connect(percent, &QLineEdit::returnPressed, this, &Ui::MainWindow::enter_next);
  connect(set_torus, &QCheckBox::stateChanged, this, &Ui::MainWindow::enter_next);
 
 };

void Ui::MainWindow::preinit_game_setup(void)
{
  ui_validator->setRange(100 , std::numeric_limits<unsigned int>::max()); 
  cols->setEnabled(true);
  rows->setEnabled(false);
  init_board->setEnabled(false);
  threads_count->setEnabled(false);
  percent->setEnabled(false);
  set_torus->setEnabled(false);
  start->setEnabled(false);
  stop->setEnabled(true);
  stop->setText("Anuluj");
  cols->setFocus();
  connect(stop, &QPushButton::clicked, this, &Ui::MainWindow::close);
}

Ui::MainWindow::~MainWindow()
{
}

void Ui::MainWindow::focusChanged(QWidget *old, QWidget *now)
{
    if (old == cols || old == rows || old == threads_count || old == percent)
    {
      QLineEdit *old_ = reinterpret_cast<QLineEdit*>(old);
      if (!(old_->hasAcceptableInput()))
      {  
        old_->setFocus();
        return;
      }
/*       if (old == threads_count)
	  {
		if (map_gen)
			threads_count->setText(QString::number(map_gen->setThreadsCount(threads_count->text().toUInt())));
	  } */
	}
}

void Ui::MainWindow::enter_next(void)
{
  QObject *o = QObject::sender();
  if(o == threads_count)
    threads_count->setText(QString::number(map_gen->setThreadsCount(threads_count->text().toInt())));  
  focusNextChild();
}

void Ui::MainWindow::enable_init(void)
{
  init_board->setEnabled(cols->hasAcceptableInput() && rows->hasAcceptableInput());
  rows->setEnabled(cols->hasAcceptableInput());
}

void Ui::MainWindow::init_game(void)
{
  try
  {
	  map_gen.reset(new MapGenerator(cols->text().toUInt(), rows->text().toUInt())); 
  }
  catch (std::runtime_error &e)
  { 
    QMessageBox msg;
    msg.setText("No memory given for bits object");
    msg.exec();
    return; 
  }      
  start->setEnabled(true);
  cols->setEnabled(false);
  rows->setEnabled(false);
  threads_count->setEnabled(true);
  //percent->setEnabled(true); 
  ui_validator->setRange(0,100);
  //set_torus->setEnabled(true);
  stop->setText("Stop");
  init_board->setEnabled(false);
  connect(stop, &QPushButton::clicked, this, &Ui::MainWindow::preinit_game_setup);
  disconnect(stop, &QPushButton::clicked, this, &Ui::MainWindow::close);
  connect(obraz, &Picture::callculate, this, &Ui::MainWindow::generate); 
}

void Ui::MainWindow::show_image()
{
  if(obraz == NULL)
  {
    try
	{
		obraz = new Picture(map_gen->generate(), cols->text().toUInt(), rows->text().toUInt());
		if (obraz)
		{
			obraz->setParent(this, Qt::Window);
			start->setEnabled(false);
			obraz->show();
			connect(obraz, &Ui::Picture::closeEvent, this, &Ui::MainWindow::preinit_game_setup);
			connect(obraz, &Ui::Picture::callculate, this, &Ui::MainWindow::generate);
		}
	}
	catch (std::runtime_error &e)
	{
		QMessageBox msg;
		msg.setText("No memory given for Picture object");
		msg.exec();
		return; 	
	}
  }
}

void Ui::MainWindow::generate(void)
{
	map_gen->generate();
}