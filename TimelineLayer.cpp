
#include <TimelineLayer.hpp>


TimelineLayer::TimelineLayer(QWidget *parent) :  QWidget(parent)
{

    m_isVisible = true;
    m_isSelected = false;

    ui.setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsRectItem *item1 = new QGraphicsRectItem(0,0,25,42);
    item1->setBrush(QBrush(QColor(60,60,60)));
    scene->addItem(item1);
    ui.timeline->setScene(scene);
    ui.timeline->setAlignment(Qt::AlignLeft);

    connect(ui.visibilityButton, &QPushButton::clicked, this, &TimelineLayer::toggleVisibility);

}

void TimelineLayer::toggleVisibility() {
  m_isVisible = ! m_isVisible;

  // change the icon depending on the visibility
  if (m_isVisible) {
    ui.visibilityButton->setIcon(QIcon(":/resources/eye.png"));
  } else {
    ui.visibilityButton->setIcon(QIcon(":/resources/crossed-eye.png"));
  }
}

void TimelineLayer::mousePressEvent(QMouseEvent *event) {
// setselected is done by frame
  emit selected(this);
}

void TimelineLayer::setSelected(bool s){
  m_isSelected = s;
  if(m_isSelected)
    setStyleSheet(("background-color : #4da6ff; color : #fff; font-size : 12px"));
   else
    setStyleSheet("font-size : 12px");

}

void TimelineLayer::setLayerName(QString name) {
  ui.stackedWidget->setLabelText(name);
}
