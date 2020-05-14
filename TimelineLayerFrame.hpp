
#pragma once
#include "ui_timelinelayerframe.h"

#include <QWidget>
#include <QLayout>
#include <QToolBar>

#include <TimelineLayer.hpp>

class TimelineLayerFrame : public QWidget
{
  Q_OBJECT
  public :
   explicit TimelineLayerFrame(QWidget *parent = nullptr);
   ~TimelineLayerFrame();

   void addTimelineLayer(TimelineLayer *tlLayer);

  private :
    Ui::mainWidget ui;
    QVBoxLayout *m_layout;

    std::vector<TimelineLayer*> m_layers;

  signals :

  public slots :
    void updateSelected(int index);
    void paintEvent(QPaintEvent *) override;
};
