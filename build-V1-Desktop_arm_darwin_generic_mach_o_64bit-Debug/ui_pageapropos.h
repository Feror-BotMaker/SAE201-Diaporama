/********************************************************************************
** Form generated from reading UI file 'pageapropos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEAPROPOS_H
#define UI_PAGEAPROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageAPropos
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *numVersion;
    QLabel *dateCreation;
    QLabel *auteurs;

    void setupUi(QWidget *PageAPropos)
    {
        if (PageAPropos->objectName().isEmpty())
            PageAPropos->setObjectName(QString::fromUtf8("PageAPropos"));
        PageAPropos->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PageAPropos->sizePolicy().hasHeightForWidth());
        PageAPropos->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(PageAPropos);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        numVersion = new QLabel(PageAPropos);
        numVersion->setObjectName(QString::fromUtf8("numVersion"));
        numVersion->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(numVersion);

        dateCreation = new QLabel(PageAPropos);
        dateCreation->setObjectName(QString::fromUtf8("dateCreation"));
        dateCreation->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(dateCreation);

        auteurs = new QLabel(PageAPropos);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));
        auteurs->setAlignment(Qt::AlignCenter);
        auteurs->setWordWrap(true);

        verticalLayout_2->addWidget(auteurs);


        retranslateUi(PageAPropos);

        QMetaObject::connectSlotsByName(PageAPropos);
    } // setupUi

    void retranslateUi(QWidget *PageAPropos)
    {
        PageAPropos->setWindowTitle(QCoreApplication::translate("PageAPropos", "\303\200 propos", nullptr));
        numVersion->setText(QCoreApplication::translate("PageAPropos", "Lecteur de diaporama - V3", nullptr));
        dateCreation->setText(QCoreApplication::translate("PageAPropos", "05/04/2023", nullptr));
        auteurs->setText(QCoreApplication::translate("PageAPropos", "Auteurs de l'application : Bodin Maximilien, Dumas Valentin et Suares Jokin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageAPropos: public Ui_PageAPropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEAPROPOS_H
