#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

#include "../controller/controller.h"
#include "widgets.h"

class MainWindow: public QMainWindow {
  Q_OBJECT
  private:
    Controller* controller_;
    QWidget* main_widget_;
    QHBoxLayout* main_layout_;
    DrawingArea* area_;
    Pannel* pannel_;

  public:

    MainWindow(Controller* controller): controller_(controller) {
      main_widget_ = new QWidget();
      main_widget_-> setWindowTitle("Window");

      main_layout_ = new QHBoxLayout();
      main_widget_->setLayout(main_layout_);

      area_ = new DrawingArea();
      area_->setFixedSize(500,500); //TODO
      main_layout_->addWidget(area_);
    
      pannel_ = new Pannel();
      main_layout_->addWidget(pannel_);
      //connect(pannel_, SIGNAL(mySignal()), this, SLOT(drawSlot()));
      connect(pannel_, SIGNAL(fileChoosen(const QString&)), this, SLOT(drawSlot(const QString&)));
    }

    void show() {
      main_widget_->show();
    }

  signals:
    void mySignal(); //TODO

  public slots:
    void drawSlot(const QString& file) { //TODO
       std::cout << "AAAA   " << file.toStdString() << std::endl;
      //TODO
    }
    

};



#endif
