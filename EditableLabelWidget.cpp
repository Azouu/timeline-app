#include <EditableLabelWidget.hpp>

#include "ui_editablelabelwidget.h"

EditableLabelWidget::EditableLabelWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::EditableLabelWidget)
{
    ui->setupUi(this);


    /************** CONNECTIONS *************/
    // QLineEdit connections 
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &EditableLabelWidget::validateLineEdit);
    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &EditableLabelWidget::validateLineEdit);
    
}

EditableLabelWidget::~EditableLabelWidget()
{
    delete ui;
}

// MouseDoubleClickEvent plays only on the QLabel (first page)
void EditableLabelWidget::mouseDoubleClickEvent(QMouseEvent *event) 
{
    if (currentIndex() == 0) 
    {   // Switch to the QLineEdit page (the second one)
        setCurrentIndex(1);
        ui->lineEdit->setFocus();
    }  
}



// Catches the enter key on the QLineEdit widget
// Saves the entered text and switches back to the QLabel page with the changes
// Or if the the text is empty, doesn't change anything
void EditableLabelWidget::validateLineEdit() 
{
    QString text = ui->lineEdit->text();   
    if (text.isEmpty()) {
        setCurrentIndex(0);
    } else {
        setCurrentIndex(0);
        ui->label->setText(text);
        ui->lineEdit->clear();
    }
}

void EditableLabelWidget::setLabelText(QString text) {
    ui->label->setText(text);
}