
#include <TimelineLayerFrame.hpp>
#include <QDebug> 


//TODO SCROLLAREA AS CONTAINER
TimelineLayerFrame::TimelineLayerFrame(QWidget *parent)
    : QWidget(parent) {

    ui.setupUi(this);

    m_layerCount = 1;
    m_selectedLayerId = -1;
    
    m_layout = new QVBoxLayout(ui.scrollAreaWidgetContents);
    /* Layout adjustments */
    m_layout->setSpacing(0);
    m_layout->setMargin(1);
    m_layout->addStretch();

    this->initializeBackgroundLayer();

    ui.scrollAreaWidgetContents->setLayout(m_layout);
    m_cptLayerName = 0;


    connect(ui.addLayerBtn, &QPushButton::clicked, this, &TimelineLayerFrame::addLayerOnTop);
    connect(ui.deleteLayerBtn, &QPushButton::clicked, this, &TimelineLayerFrame::deleteSelectedLayer);
    connect(ui.upBtn, &QPushButton::clicked, this, &TimelineLayerFrame::upSelectedLayer);
    connect(ui.downBtn, &QPushButton::clicked, this, &TimelineLayerFrame::downSelectedLayer);


}

TimelineLayer* TimelineLayerFrame::initializeBackgroundLayer() {
    TimelineLayer *new_layer = new TimelineLayer();
    new_layer->setLayerName("Background");
    m_layout->insertWidget(0,new_layer);

    connect(new_layer, &TimelineLayer::selected, this, &TimelineLayerFrame::updateSelected);
}
void TimelineLayerFrame::addTimelineLayer(TimelineLayer *tlLayer) {
    m_layerCount++;
    m_layout->insertWidget(0,tlLayer);
    connect(tlLayer, &TimelineLayer::selected, this, &TimelineLayerFrame::updateSelected);
}

TimelineLayerFrame::~TimelineLayerFrame() {
    delete &ui;
}

void TimelineLayerFrame::updateSelected(TimelineLayer* layer){
    unselectAll();
    layer->setSelected(true);
    m_selectedLayerId = getLayerID(layer);
}

   void TimelineLayerFrame::updateSelectedById(int index) {
       unselectAll();
   //    qDebug() << "UpdateSelectedById before : "  << m_selectedLayerId;
       getLayerAt(index)->setSelected(true);
   //       qDebug() << "UpdateSelectedById after1 : "  << m_selectedLayerId;
       m_selectedLayerId = index;
    //      qDebug() << "UpdateSelectedById after2 : "  << m_selectedLayerId;
   }


bool TimelineLayerFrame::hasSelected() {
    return m_selectedLayerId != -1;
}
void TimelineLayerFrame::unselectAll() {
    if (hasSelected()) {
        qDebug() << "Unselecting layer at selected index " << m_selectedLayerId;
        getSelectedLayer()->setSelected(false);
        m_selectedLayerId = -1;
    }
}

TimelineLayer* TimelineLayerFrame::getLayerAt(int index) {
    QLayoutItem *item = m_layout->itemAt(index);
    if (item != 0) {
        TimelineLayer *layer = dynamic_cast<TimelineLayer*>(item->widget());
        if (layer == nullptr) {
            qDebug() << "TimelineLayer pointer at " << index << "is null";
        }        
        return layer;
    } 
    return 0;
}

int TimelineLayerFrame::getLayerID(TimelineLayer* layer) {
    for (int i = 0; i < m_layout->count(); i++) {
        if (layer == m_layout->itemAt(i)->widget()) {
            qDebug() << "Retrieved ID is " << i;
            return i;
        }
    }
    return -1;
}

 TimelineLayer* TimelineLayerFrame::getSelectedLayer() {
    return getLayerAt(m_selectedLayerId);   
 }

void TimelineLayerFrame::addLayerOnTop() {
    unselectAll();
    m_layerCount++;
    TimelineLayer *newLayer = new TimelineLayer();

    m_cptLayerName++;
    newLayer->setLayerName("Calque " + QString::number(m_cptLayerName));
    m_layout->insertWidget(0,newLayer);

    connect(newLayer, &TimelineLayer::selected, this, &TimelineLayerFrame::updateSelected);
}
    

void TimelineLayerFrame::deleteSelectedLayer() {
    // CRASH if you try to delete last item (condition mandatory to avoid this problem)
    if (hasSelected() && ! isBackgroundLayer(m_selectedLayerId)) {
    //QLayoutItem* item = m_layout->takeAt(m_selectedLayerId);
    qDebug() << "On deletion of a layer : Trying to delete the layer at index " << m_selectedLayerId;
   // delete item;
    QLayoutItem* item = m_layout->takeAt(m_selectedLayerId);
    m_layout->removeWidget(item->widget());
    item->widget()->deleteLater();
    
    updateSelectedById(m_selectedLayerId);
    qDebug() << "After deletion, selected index is " << m_selectedLayerId;

    m_layerCount--;

    }
}    


void TimelineLayerFrame::upSelectedLayer() {
    if (m_selectedLayerId > 0 && ! isBackgroundLayer(m_selectedLayerId)) {
        qDebug() << "Upping the layer of ID" << m_selectedLayerId;
        QLayoutItem* item = m_layout->takeAt(m_selectedLayerId);
        m_layout->insertItem(m_selectedLayerId - 1, item);
        m_selectedLayerId = m_selectedLayerId - 1;
        qDebug() << "After upping the layer, new selectedLayerID is " << m_selectedLayerId;
    }
}

void TimelineLayerFrame::downSelectedLayer() {
     if (m_selectedLayerId >= 0 && m_selectedLayerId < m_layerCount - 2) {
        qDebug() << "Push the layer of ID" << m_selectedLayerId << "down";
        QLayoutItem* item = m_layout->takeAt(m_selectedLayerId);
        m_layout->insertItem(m_selectedLayerId + 1, item);
        m_selectedLayerId = m_selectedLayerId  + 1;
        qDebug() << "After pushing down the layer, new selectedLayerID is " << m_selectedLayerId;
    }
}

   bool TimelineLayerFrame::isBackgroundLayer(int index) {
       return index == m_layerCount - 1;
   }

