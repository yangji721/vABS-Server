#ifndef PBUTTON
#define PBUTTON

#include <QPushButton>
#include "dialog2.h"

class PButton : public QPushButton
{
    Q_OBJECT

public:
    PButton(QWidget *parent);
    void paintEvent(QPaintEvent *);
    void setclick();

public slots:
    void display();
private:
    dialog2 *dialog = new dialog2;
};

#endif // PBUTTON
