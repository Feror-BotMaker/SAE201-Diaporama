#ifndef CHANGEURDIAPORAMA_H
#define CHANGEURDIAPORAMA_H

#include <QDialog>
#include <modele.h>
#include <QRadioButton>

namespace Ui {
class ChangeurDiaporama;
}

class ChangeurDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeurDiaporama(ListeDiaporamas listeDiapos, QWidget *parent = nullptr);
    ~ChangeurDiaporama();
    int getIdChoisi();
private:
    Ui::ChangeurDiaporama *ui;
private slots:
    void onCellClicked(int, int);
};

#endif // CHANGEURDIAPORAMA_H
