
#include "window.h"
#include "timeline.h"

Window::Window(Timeline *tl, QWidget *parent) : QWidget(parent) 
{   
    this->timeline = tl;
    const int nbFrames = tl->getNbFrames();
    
    QGridLayout *layout = new QGridLayout;

    // Widget creation
    QPushButton *btn_left = new QPushButton;
    QPushButton *btn_right = new QPushButton;
    QOpenGLWidget *centralWidget = new QOpenGLWidget;
    slider = new QSlider(Qt::Horizontal);
    spinbox = new QSpinBox;
    QLabel *l_nbFrames = new QLabel("of " % QString::number(nbFrames) % " frames");
    // V2 Section, to be modified
    // TODO: set this section scrollable
    // TODO: Add Status Bar
    QLabel *l_keypoints = new QLabel("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariaturaza. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    l_keypoints->setWordWrap(true);
    l_keypoints->setMaximumHeight(50);
    l_keypoints->hide();

    layout->addWidget(btn_left,1,0);
    layout->addWidget(btn_right,1,6);
    layout->addWidget(centralWidget,0,1,3,5);
    layout->addWidget(slider,4,2,1,2);
    layout->addWidget(spinbox,4,4); 
    layout->addWidget(l_nbFrames,4,5);
    layout->addWidget(l_keypoints,5,2,1,3);


    // Layout management 
    layout->setMargin(10);
    layout->setSpacing(15);
    // Column management : set the slider section to be proportionally bigger to the others, and the button section to be smaller
    layout->setColumnStretch(0,1);  // btn_left 
    layout->setColumnStretch(1,2);  // window
    layout->setColumnStretch(2,8);  // slider and window 
    layout->setColumnStretch(3,2);  // slider and window
    layout->setColumnStretch(4,0);  // spinbox and window
    layout->setColumnStretch(5,2);  // l_nbframes and window
    layout->setColumnStretch(6,1);  // btn_right
    // Add space around the "slider section"  (top and bottow)
    layout->setRowMinimumHeight(3,20);
    layout->setRowMinimumHeight(6,20);

    //Set widget parameters according to the timeline data structure
    slider->setRange(1, nbFrames);
    spinbox->setRange(1, nbFrames);
    spinbox->setKeyboardTracking(false);

    // Style of widgets 
    setPalette(createDarkPalette());
    QCommonStyle style;
    btn_left->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));    
    btn_right->setIcon(style.standardIcon(QStyle::SP_ArrowRight));


    // Dimensions of widgets
    btn_left->setMinimumHeight(70);
    btn_right->setMinimumHeight(70);
    slider->setMinimumWidth(290);

    // Shortcuts
    btn_left->setShortcut(QKeySequence("Left"));
    btn_right->setShortcut(QKeySequence("Right"));

    setLayout(layout);
    setWindowTitle("Timeline viewer");
    showMaximized();

    // Connections
    connect(btn_left, &QPushButton::clicked, this, &Window::decrTimelineIndex);
    connect(btn_right, &QPushButton::clicked, this, &Window::incrTimelineIndex);

    connect(slider, &QSlider::valueChanged, this, &Window::setTimelineIndex);
    connect(slider, &QSlider::valueChanged,  spinbox, &QSpinBox::setValue);

    connect(spinbox, SIGNAL(valueChanged(int)),  slider, SLOT (setValue(int))); 

}

QPalette Window::createDarkPalette() {
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    return darkPalette;
}

void Window::setTimelineIndex(int value) {
    timeline->setFrameIndex(value - 1); 
}

void Window::incrTimelineIndex() {
    timeline->incrFrameIndex();
    int valueToDisplay = timeline->getFrameIndex() + 1;
    slider->setValue(valueToDisplay); 
}

void Window::decrTimelineIndex() {
    timeline->decrFrameIndex();
    int valueToDisplay = timeline->getFrameIndex() + 1;
    slider->setValue(valueToDisplay); 
}