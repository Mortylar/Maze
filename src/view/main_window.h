#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

#include "widgets.h"

class MainWindow: public QMainWindow {

  private:
    QWidget* main_widget_;
    QHBoxLayout* main_layout_;
    QPushButton* button1_;
    Pannel* pannel_;

  public:

  MainWindow() {
    main_widget_ = new QWidget();
    main_widget_-> setWindowTitle("Window");

    main_layout_ = new QHBoxLayout();
    main_widget_->setLayout(main_layout_);

    button1_ = new QPushButton("1");
    main_layout_->addWidget(button1_);
    
    pannel_ = new Pannel();
    main_layout_->addWidget(pannel_);
  }

  void show() {
    main_widget_->show();
  }
    

};



#endif
