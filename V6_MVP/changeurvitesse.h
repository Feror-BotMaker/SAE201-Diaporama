#ifndef CHANGEURVITESSE_H
#define CHANGEURVITESSE_H

#include <QDialog>
#include <QRegExpValidator>

namespace Ui {
class ChangeurVitesse;
}

class ChangeurVitesse : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeurVitesse(QWidget *parent = nullptr);
    ~ChangeurVitesse();
    int getVitesse();
private:
    Ui::ChangeurVitesse *ui;
public slots:
    void updateSlider();
    void updateLabel();
};

#endif // CHANGEURVITESSE_H
