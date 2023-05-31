#ifndef CHANGEURDIAPORAMA_H
#define CHANGEURDIAPORAMA_H

#include <QDialog>

namespace Ui {
class ChangeurDiaporama;
}

class ChangeurDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeurDiaporama(QWidget *parent = nullptr);
    ~ChangeurDiaporama();

private:
    Ui::ChangeurDiaporama *ui;
};

#endif // CHANGEURDIAPORAMA_H
