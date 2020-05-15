
#pragma once
#include "ui_timelinelayer.h"

#include <QWidget>
#include <QGraphicsRectItem>
#include <QPalette>

class TimelineLayer : public QWidget
{
  Q_OBJECT

  public :
    explicit TimelineLayer(QWidget *parent = nullptr);
 //  ~TimelineLayer();
    void setSelected(bool);
    void setLayerName(QString label);

protected :
  void mousePressEvent(QMouseEvent *event) override;

  private :
    Ui::timelinelayer ui;
    bool m_isVisible;
    bool m_isSelected;

signals :
    void selected(TimelineLayer*);

private slots :
    void toggleVisibility();
};
