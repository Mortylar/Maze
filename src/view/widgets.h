#ifndef WIDGETS_H_
#define WIDGETS_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtGui/QPainter>
#include <QtCore/QString>

#include <iostream>
#include "../common/line.h"

class MainPannel: public QFrame {
  Q_OBJECT
  private:
    const QString file_button_name_ = "Load";
    const QString maze_button_name_ = "Maze";
    const QString cave_button_name_ = "Cave";
    QGridLayout* root_;
    QPushButton* file_button_;
    QString file_name_;
    QPushButton* swap_field_button_;


  public:
    MainPannel() {
      root_ = new QGridLayout(this);
      file_button_ = new QPushButton(file_button_name_);
      connect(file_button_, SIGNAL(clicked()), this, SLOT(readFile()));

      swap_field_button_ = new QPushButton(maze_button_name_);
      connect(swap_field_button_, SIGNAL(clicked()), this, SLOT(swapField()));
      root_->addWidget(file_button_, 0,0,1,2);
      root_->addWidget(swap_field_button_, 0,2,1,1);

      this->setFrameStyle(QFrame::Box | QFrame::Raised);
    }

  signals:
    void mySignal(); //TODO
    void fileChoosen(const QString&);

  public slots:
    void readFile() {
      file_name_ = QFileDialog::getOpenFileName();
      std::cout << "51 emit " << file_name_.toStdString() << std::endl;
      /*if (!file_name_.size())*/ emit fileChoosen(file_name_);
      //std::cout << file_name_.toStdString() << std::endl; //TODO
    }

    void swapField() {
      emit mySignal();
      std::cout << "Swap" << std::endl; //TODO
    }
};


class SizePannel: public QFrame {
  Q_OBJECT

  private:
    QGridLayout* root_;
    QLabel* rows_label_; 
    QLabel* cols_label_;
    QSpinBox* rows_;
    QSpinBox* cols_;
    QPushButton* button_;

    void CreateGrid() {
      root_ = new QGridLayout();
      this->setLayout(root_);
    }

    void CreateLabel() {
      rows_label_ = new QLabel("Rows");
      cols_label_ = new QLabel("Cols");
    }

    void CreateSpinBox() {
      rows_ = new QSpinBox();
      cols_ = new QSpinBox();
    }
   
    void Placement() {
      root_->addWidget(rows_label_,0,0,1,1); 
      root_->addWidget(cols_label_,0,1,1,1);
      root_->addWidget(rows_,1,0,1,1);
      root_->addWidget(cols_,1,1,1,1);
    }

  public:
    SizePannel() {
     CreateGrid();
     CreateLabel();
     CreateSpinBox();
     Placement();
     this->setFrameStyle(QFrame::Box | QFrame::Raised);
    }

    QGridLayout* Root() {
      return root_;
    }

  signals:
    void mySignal(); //TODO

  public slots:
    void mySlot() {}; //TODO

};

class SolvPannel: public QFrame {
  Q_OBJECT
  private:
    QGridLayout* root_;
    QLabel* path_;
    QLabel* coord_;
    QLabel* start_;
    QLabel* end_;
    QLabel* x_;
    QLabel* y_;
    QSpinBox* start_x_;
    QSpinBox* end_x_;
    QSpinBox* start_y_;
    QSpinBox* end_y_;

    void createLabels() {
      path_ = new QLabel("Pathfinding");
      path_->setAlignment(Qt::AlignCenter);
      coord_ = new QLabel("Coordinate");
      coord_->setAlignment(Qt::AlignCenter);
      start_ = new QLabel("Start");
      start_->setAlignment(Qt::AlignLeft);
      end_ = new QLabel("End");
      end_->setAlignment(Qt::AlignLeft);
      x_ = new QLabel("X");
      x_->setAlignment(Qt::AlignCenter);
      y_ = new QLabel("Y");
      y_->setAlignment(Qt::AlignCenter);
    }

    void createSpinButtons() {
      start_x_ = new QSpinBox();
      start_y_ = new QSpinBox();
      end_x_ = new QSpinBox();
      end_y_ = new QSpinBox();
    }
  public:

    SolvPannel() {
      root_ = new QGridLayout();
      this->setLayout(root_);
      createLabels();
      createSpinButtons();
      root_->addWidget(path_, 0,0, 1,3);
      root_->addWidget(coord_, 1,0, 1,1);
      root_->addWidget(x_, 1,1, 1,1);
      root_->addWidget(y_, 1,2, 1,1);
      root_->addWidget(start_, 2,0, 1,1);
      root_->addWidget(start_x_, 2,1, 1,1);
      root_->addWidget(start_y_, 2,2, 1,1);
      root_->addWidget(end_, 3,0, 1,1);
      root_->addWidget(end_x_, 3,1, 1,1);
      root_->addWidget(end_y_, 3,2, 1,1);
      this->setFrameStyle(QFrame::Box | QFrame::Raised);
    }

  signals:
    void mySignal(); //TODO

  public slots:
    void mySlot() {} //TODO
};


class MazePannel: public QFrame {
  Q_OBJECT
  private:
    QVBoxLayout* root_;
    SizePannel* size_;
    SolvPannel* solv_;

  public:
    MazePannel() {
      root_ = new QVBoxLayout();
      this->setLayout(root_);

      size_ = new SizePannel();
      root_->addWidget(size_);

      solv_ = new SolvPannel();
      root_ ->addWidget(solv_);

      this->setFrameStyle(QFrame::Box | QFrame::Raised);
    }

  signals:
    void mySignal(); //TODO

  public slots:
    void mySlot() {}; //TODO
    
};

class Pannel: public QFrame {
  Q_OBJECT
  private:
    QVBoxLayout* root_;
    MainPannel* main_;
    MazePannel* maze_;
  public:
    Pannel() {
      root_ = new QVBoxLayout();
      this->setLayout(root_);
      main_ = new MainPannel(); 
      connect(main_, SIGNAL(mySignal()), this, SLOT(mySlot()));
      connect(main_, SIGNAL(fileChoosen(const QString&)), this, SLOT(fileChoosenSlot(const QString&)));
      root_->addWidget(main_);
      maze_ = new MazePannel();
      root_->addWidget(maze_);
      this->setFrameStyle(QFrame::Box | QFrame::Raised);
    }
  signals:
    void mySignal(); //TODO
    void fileChoosen(const QString& file);

  public slots:
    void mySlot() {emit mySignal();}; //TODO
    void fileChoosenSlot(const QString& file) {
      std::cout << "234 " << file.toStdString() << std::endl;
      emit fileChoosen(file);}
};

class DrawingArea : public QFrame {
  Q_OBJECT
  private:
    std::vector<Line> buffer_;

  public:
    DrawingArea() {
      //std::cout << "buffer size " << buffer_.size() << std::endl;
      buffer_ = std::vector<Line>();
      //std::cout << "buffer size " << buffer_.size() << std::endl;
    }

    void setBuffer(std::vector<Line> buffer) {
      buffer_ = buffer;
    }

    void paintEvent(QPaintEvent* event) {
      //std::cout << "buffer size " << buffer_.size() << std::endl;
      if (buffer_.size() > 0) {
        QPainter painter;
        QPen pen;
        pen.setWidth(2);
        pen.setColor(Qt::red);
        painter.begin(this);
        painter.setPen(pen);
        const float k_WIDTH = this->width() - 1;
        const float k_HEIGHT = this->height() - 1;
        for (size_t i = 0; i < buffer_.size(); ++i) {
          Line& l = buffer_[i];
          l.Print();
          float x1 = l.GetX().GetX() * k_WIDTH;
          float y1 = l.GetX().GetY() * k_HEIGHT;
          float x2 = l.GetY().GetX() * k_WIDTH;
          float y2 = l.GetY().GetY() * k_HEIGHT;

          painter.drawLine(x1, y1, x2, y2);
        }
        //painter_->setPen(Qt::blue);
        //painter_->setFont(QFont("Arial", 30));
        //painter_->drawText(rect(), Qt::AlignCenter, "rgsdhs");
        painter.end();
      }
    }

    void draw(QPaintEvent* event) {
      QPainter painter;
      painter.begin(this);
      painter.drawLine(10, 50, 150, 50);
      painter.end();
    }
  signals:
    void mySignal(); //TODO

  public slots:
    void mySlot() {}; //TODO
};


#endif
