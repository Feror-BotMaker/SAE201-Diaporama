#ifndef PAGEAPROPOS_H
#define PAGEAPROPOS_H

#include <QWidget>

namespace Ui {
class PageAPropos;
}

class PageAPropos : public QWidget
{
    Q_OBJECT

public:
    explicit PageAPropos(QWidget *parent = nullptr);
    ~PageAPropos();
private:
    Ui::PageAPropos *ui;
};

#endif // PAGEAPROPOS_H
