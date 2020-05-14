
#include <TimelineLayerFrame.hpp>



TimelineLayerFrame::TimelineLayerFrame(QWidget *parent)
    : QWidget(parent) {

    ui.setupUi(this);

    m_layout = new QVBoxLayout;
    /* Layout adjustments */
    m_layout->setSpacing(0);
    m_layout->setMargin(1);
    m_layout->addStretch();

    ui.scrollAreaWidgetContents->setLayout(m_layout);

}

void TimelineLayerFrame::addTimelineLayer(TimelineLayer *tlLayer) {
    m_layout->insertWidget(0,tlLayer);
    m_layers.push_back(tlLayer);
    connect(tlLayer, &TimelineLayer::selected, this, &TimelineLayerFrame::updateSelected);
}

TimelineLayerFrame::~TimelineLayerFrame() {

}

void TimelineLayerFrame::updateSelected(int index){
    for(auto l:m_layers){
        if(index == l->getIndex()) l->setSelected(true);
        else l->setSelected(false);
    }
}
