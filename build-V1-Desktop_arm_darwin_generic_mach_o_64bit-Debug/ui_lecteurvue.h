/********************************************************************************
** Form generated from reading UI file 'lecteurvue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTEURVUE_H
#define UI_LECTEURVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LecteurVue
{
public:
    QAction *action_quitter;
    QAction *action_changer_diaporama;
    QAction *action_enlever_diaporama;
    QAction *action_vitesse_defilement;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titre;
    QLabel *image;
    QHBoxLayout *horizontalLayout_2;
    QLabel *categorie;
    QSpacerItem *horizontalSpacer;
    QLabel *rang;
    QHBoxLayout *horizontalLayout;
    QPushButton *precedent;
    QPushButton *lancer_diaporama;
    QPushButton *suivant;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LecteurVue)
    {
        if (LecteurVue->objectName().isEmpty())
            LecteurVue->setObjectName(QString::fromUtf8("LecteurVue"));
        LecteurVue->resize(640, 480);
        action_quitter = new QAction(LecteurVue);
        action_quitter->setObjectName(QString::fromUtf8("action_quitter"));
        action_changer_diaporama = new QAction(LecteurVue);
        action_changer_diaporama->setObjectName(QString::fromUtf8("action_changer_diaporama"));
        action_enlever_diaporama = new QAction(LecteurVue);
        action_enlever_diaporama->setObjectName(QString::fromUtf8("action_enlever_diaporama"));
        action_vitesse_defilement = new QAction(LecteurVue);
        action_vitesse_defilement->setObjectName(QString::fromUtf8("action_vitesse_defilement"));
        centralwidget = new QWidget(LecteurVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titre = new QLabel(centralwidget);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setAlignment(Qt::AlignHCenter);

        verticalLayout->addWidget(titre);

        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setScaledContents(true);

        verticalLayout->addWidget(image);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        categorie = new QLabel(centralwidget);
        categorie->setObjectName(QString::fromUtf8("categorie"));

        horizontalLayout_2->addWidget(categorie);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        rang = new QLabel(centralwidget);
        rang->setObjectName(QString::fromUtf8("rang"));

        horizontalLayout_2->addWidget(rang);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        precedent = new QPushButton(centralwidget);
        precedent->setObjectName(QString::fromUtf8("precedent"));

        horizontalLayout->addWidget(precedent);

        lancer_diaporama = new QPushButton(centralwidget);
        lancer_diaporama->setObjectName(QString::fromUtf8("lancer_diaporama"));

        horizontalLayout->addWidget(lancer_diaporama);

        suivant = new QPushButton(centralwidget);
        suivant->setObjectName(QString::fromUtf8("suivant"));

        horizontalLayout->addWidget(suivant);


        verticalLayout->addLayout(horizontalLayout);

        LecteurVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LecteurVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 36));
        LecteurVue->setMenuBar(menubar);
        statusbar = new QStatusBar(LecteurVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LecteurVue->setStatusBar(statusbar);

        retranslateUi(LecteurVue);

        QMetaObject::connectSlotsByName(LecteurVue);
    } // setupUi

    void retranslateUi(QMainWindow *LecteurVue)
    {
        LecteurVue->setWindowTitle(QCoreApplication::translate("LecteurVue", "Mon Application", nullptr));
        action_quitter->setText(QCoreApplication::translate("LecteurVue", "Sortir", nullptr));
        action_changer_diaporama->setText(QCoreApplication::translate("LecteurVue", "Changer diaporama", nullptr));
        action_enlever_diaporama->setText(QCoreApplication::translate("LecteurVue", "Enlever diaporama", nullptr));
        action_vitesse_defilement->setText(QCoreApplication::translate("LecteurVue", "Vitesse de d\303\251filement", nullptr));
        titre->setText(QCoreApplication::translate("LecteurVue", "Titre", nullptr));
        image->setText(QCoreApplication::translate("LecteurVue", "Image", nullptr));
        categorie->setText(QCoreApplication::translate("LecteurVue", "Cat\303\251gorie", nullptr));
        rang->setText(QCoreApplication::translate("LecteurVue", "Rang", nullptr));
        precedent->setText(QCoreApplication::translate("LecteurVue", "Pr\303\251c\303\251dent", nullptr));
        lancer_diaporama->setText(QCoreApplication::translate("LecteurVue", "Lancer Diaporama", nullptr));
        suivant->setText(QCoreApplication::translate("LecteurVue", "Suivant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LecteurVue: public Ui_LecteurVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEURVUE_H
