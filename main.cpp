
#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QColor>

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsAnchorLayout>
#include <QGraphicsProxyWidget>

#include <TimelineLayer.hpp>
#include <TimelineLayerFrame.hpp>


int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  TimelineLayerFrame tlframe(0);
  TimelineLayer tl(0);
  tlframe.addTimelineLayer(&tl);
  TimelineLayer tl2(1);
  tlframe.addTimelineLayer(&tl2);
  tlframe.show();
  return app.exec();
}
