
#include <TimelineLayerFrame.hpp>

static void paintLayout(QPainter *painter, QLayoutItem *item)
{
    QLayout *layout = item->layout();
    if (layout) {
        for (int i = 0; i < layout->count(); ++i)
            paintLayout(painter, layout->itemAt(i));
    }
    painter->drawRect(item->geometry());
}

void TimelineLayerFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (layout())
        paintLayout(&painter, layout());

    painter.setPen(QColor(100, 0, 100));
    if(m_layout)
        paintLayout(&painter, m_layout);

    auto pen{painter.pen()};
    pen.setColor(QColor(200, 0,0));
    pen.setWidthF(4.5);
    painter.setPen(pen);
    static int cpt=10;
    painter.drawLine(cpt, 0, cpt, 500);

    cpt++;
    if(cpt>width()) cpt=0;

}

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
