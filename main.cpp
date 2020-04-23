#include "window.h"
#include "timeline.h"

#include <QApplication>
#include <QStyleFactory>
#include <QPalette>


int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  

  Timeline *timeline = new Timeline(90);
  Window window(timeline);
  window.show();
  
  return app.exec();
}