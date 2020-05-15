
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
   void unselectAll();
   TimelineLayer* getLayerAt(int index);
   TimelineLayer* getSelectedLayer();
   int getLayerID(TimelineLayer* layer);
   bool hasSelected();
   bool isBackgroundLayer(int index);
   int getNextLayerNumber();
   TimelineLayer* initializeBackgroundLayer();
   void updateSelectedById(int index);

  private :
    Ui::mainWidget ui;
    QVBoxLayout *m_layout;
    
    int m_cptLayerName;
    int m_selectedLayerId;
    int m_layerCount;

  signals :

  public slots :
    void updateSelected(TimelineLayer* layer);
    void deleteSelectedLayer();
    void upSelectedLayer();
    void downSelectedLayer();
    void addLayerOnTop();
};
