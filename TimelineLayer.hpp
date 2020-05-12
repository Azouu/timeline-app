
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
   ~TimelineLayer();

  protected :
  void mousePressEvent(QMouseEvent *event) override; 
  void focusOutEvent(QFocusEvent *event) override;
  
  private :
    Ui::timelinelayer ui;
    bool m_isVisible;
    bool m_isSelected;

   signals :

  private slots :
    void toggleVisibility();
};