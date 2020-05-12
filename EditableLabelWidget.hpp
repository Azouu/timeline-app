#ifndef EDITABLELABELWIDGET_HPP
#define EDITABLELABELWIDGET_HPP

#include <QStackedWidget>
#include <QKeyEvent>

namespace Ui {
class EditableLabelWidget;
}

class EditableLabelWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit EditableLabelWidget(QWidget *parent = nullptr);
    ~EditableLabelWidget();

protected : 
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::EditableLabelWidget *ui;

protected slots : 
    void validateLineEdit();
};

#endif // EDITABLELABELWIDGET_HPP
