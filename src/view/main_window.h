#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

#include "widgets.h"

class MainWindow: public QMainWindow {
  Q_OBJECT
  private:
    QWidget* main_widget_;
    QHBoxLayout* main_layout_;
    DrawingArea* area_;
    Pannel* pannel_;

  public:

    MainWindow() {
      main_widget_ = new QWidget();
      main_widget_-> setWindowTitle("Window");

      main_layout_ = new QHBoxLayout();
      main_widget_->setLayout(main_layout_);

      area_ = new DrawingArea();
      area_->setFixedSize(500,500);
      main_layout_->addWidget(area_);
    
      pannel_ = new Pannel();
      main_layout_->addWidget(pannel_);
      connect(pannel_, SIGNAL(mySignal()), this, SLOT(drawSlot()));
    }

    void show() {
      main_widget_->show();
    //area_->draw();
    }

  signals:
    void mySignal(); //TODO

  public slots:
    void drawSlot() { //TODO
      //TODO
    }
    

};



#endif
