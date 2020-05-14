
#pragma once
#include "ui_timelinelayer.h"

#include <QWidget>
#include <QGraphicsRectItem>
#include <QPalette>

class TimelineLayer : public QWidget
{
  Q_OBJECT

  public :
    explicit TimelineLayer(int index, QWidget *parent = nullptr);
   ~TimelineLayer();
    void setSelected(bool);

    int getIndex() const { return m_index; }
    void setIndex(int index) { m_index = index; }


protected :
  void mousePressEvent(QMouseEvent *event) override;

  private :
    Ui::timelinelayer ui;
    bool m_isVisible;
    bool m_isSelected;
    int m_index;
signals :
    void selected(int);

private slots :
    void toggleVisibility();
};
