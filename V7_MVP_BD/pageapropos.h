#ifndef PAGEAPROPOS_H
#define PAGEAPROPOS_H

#include <QDialog>

namespace Ui {
class PageAPropos;
}

class PageAPropos : public QDialog
{
    Q_OBJECT

public:
    explicit PageAPropos(QWidget *parent = nullptr);
    ~PageAPropos();
private:
    Ui::PageAPropos *ui;
};

#endif // PAGEAPROPOS_H
