#ifndef WINDOW_H
#define WINDOW_H


#include "timeline.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QGridLayout>
#include <QAbstractSlider>
#include <QTextBrowser>
#include <QPushButton>
#include <QCommonStyle>
#include <QStringBuilder>
#include <QLabel>
#include <QPalette>
#include <QOpenGLWidget>


class Window : public QWidget
{
Q_OBJECT

private :
   Timeline *timeline;

    QSlider *slider;
    QSpinBox *spinbox;

private slots :

    // UI Management
    QPalette createDarkPalette();
    // Data management
    void setTimelineIndex(int value);
    void incrTimelineIndex();
    void decrTimelineIndex();

public:
    explicit Window(Timeline *tl, QWidget *parent = 0);

};

#endif // WINDOW_H