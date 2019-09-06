/********************************************************************************
** Form generated from reading UI file 'tdlasdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDLASDIALOG_H
#define UI_TDLASDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tdlasDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *lazer1openclose;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QDoubleSpinBox *setlazer1tcbox;
    QPushButton *setlazer1tc;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QPushButton *lazer2openclose;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QCheckBox *das;
    QCheckBox *wms;
    QFrame *line;
    QVBoxLayout *verticalLayout_das;
    QHBoxLayout *horizontalLayout_4;
    QLabel *das_basefr_lab;
    QDoubleSpinBox *das_basefr;
    QHBoxLayout *horizontalLayout_5;
    QLabel *das_duty_lab;
    QDoubleSpinBox *das_duty;
    QHBoxLayout *horizontalLayout_6;
    QLabel *das_maxwl_lab;
    QDoubleSpinBox *das_maxwl;
    QHBoxLayout *horizontalLayout_7;
    QLabel *das_minwl_lab;
    QDoubleSpinBox *das_minwl;
    QVBoxLayout *verticalLayout_wms;
    QHBoxLayout *horizontalLayout_8;
    QLabel *wms_basefr_lab;
    QDoubleSpinBox *wms_basefr;
    QHBoxLayout *horizontalLayout_9;
    QLabel *wms_duty_lab;
    QDoubleSpinBox *wms_duty;
    QHBoxLayout *horizontalLayout_10;
    QLabel *wms_maxwl_lab;
    QDoubleSpinBox *wms_maxwl;
    QHBoxLayout *horizontalLayout_11;
    QLabel *wms_minwl_lab;
    QDoubleSpinBox *wms_minwl;
    QHBoxLayout *horizontalLayout_12;
    QLabel *wms_sinfr_lab;
    QDoubleSpinBox *wms_sinfr;
    QHBoxLayout *horizontalLayout_13;
    QLabel *wms_sinam_lab;
    QDoubleSpinBox *wms_sinam;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tdlasDialog)
    {
        if (tdlasDialog->objectName().isEmpty())
            tdlasDialog->setObjectName(QStringLiteral("tdlasDialog"));
        tdlasDialog->resize(532, 330);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tdlasDialog->sizePolicy().hasHeightForWidth());
        tdlasDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(tdlasDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(tdlasDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lazer1openclose = new QPushButton(tab);
        lazer1openclose->setObjectName(QStringLiteral("lazer1openclose"));
        lazer1openclose->setEnabled(true);
        lazer1openclose->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(lazer1openclose);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        setlazer1tcbox = new QDoubleSpinBox(tab);
        setlazer1tcbox->setObjectName(QStringLiteral("setlazer1tcbox"));
        setlazer1tcbox->setSingleStep(0.01);

        horizontalLayout->addWidget(setlazer1tcbox);

        setlazer1tc = new QPushButton(tab);
        setlazer1tc->setObjectName(QStringLiteral("setlazer1tc"));
        setlazer1tc->setAutoDefault(true);

        horizontalLayout->addWidget(setlazer1tc);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lazer2openclose = new QPushButton(tab);
        lazer2openclose->setObjectName(QStringLiteral("lazer2openclose"));
        lazer2openclose->setMaximumSize(QSize(60, 16777215));
        lazer2openclose->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(lazer2openclose);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        das = new QCheckBox(tab_2);
        das->setObjectName(QStringLiteral("das"));

        gridLayout->addWidget(das, 0, 0, 1, 1);

        wms = new QCheckBox(tab_2);
        wms->setObjectName(QStringLiteral("wms"));

        gridLayout->addWidget(wms, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        line = new QFrame(tab_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_das = new QVBoxLayout();
        verticalLayout_das->setObjectName(QStringLiteral("verticalLayout_das"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        das_basefr_lab = new QLabel(tab_2);
        das_basefr_lab->setObjectName(QStringLiteral("das_basefr_lab"));

        horizontalLayout_4->addWidget(das_basefr_lab);

        das_basefr = new QDoubleSpinBox(tab_2);
        das_basefr->setObjectName(QStringLiteral("das_basefr"));

        horizontalLayout_4->addWidget(das_basefr);


        verticalLayout_das->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        das_duty_lab = new QLabel(tab_2);
        das_duty_lab->setObjectName(QStringLiteral("das_duty_lab"));

        horizontalLayout_5->addWidget(das_duty_lab);

        das_duty = new QDoubleSpinBox(tab_2);
        das_duty->setObjectName(QStringLiteral("das_duty"));

        horizontalLayout_5->addWidget(das_duty);


        verticalLayout_das->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        das_maxwl_lab = new QLabel(tab_2);
        das_maxwl_lab->setObjectName(QStringLiteral("das_maxwl_lab"));

        horizontalLayout_6->addWidget(das_maxwl_lab);

        das_maxwl = new QDoubleSpinBox(tab_2);
        das_maxwl->setObjectName(QStringLiteral("das_maxwl"));

        horizontalLayout_6->addWidget(das_maxwl);


        verticalLayout_das->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        das_minwl_lab = new QLabel(tab_2);
        das_minwl_lab->setObjectName(QStringLiteral("das_minwl_lab"));

        horizontalLayout_7->addWidget(das_minwl_lab);

        das_minwl = new QDoubleSpinBox(tab_2);
        das_minwl->setObjectName(QStringLiteral("das_minwl"));

        horizontalLayout_7->addWidget(das_minwl);


        verticalLayout_das->addLayout(horizontalLayout_7);


        horizontalLayout_3->addLayout(verticalLayout_das);

        verticalLayout_wms = new QVBoxLayout();
        verticalLayout_wms->setObjectName(QStringLiteral("verticalLayout_wms"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        wms_basefr_lab = new QLabel(tab_2);
        wms_basefr_lab->setObjectName(QStringLiteral("wms_basefr_lab"));

        horizontalLayout_8->addWidget(wms_basefr_lab);

        wms_basefr = new QDoubleSpinBox(tab_2);
        wms_basefr->setObjectName(QStringLiteral("wms_basefr"));

        horizontalLayout_8->addWidget(wms_basefr);


        verticalLayout_wms->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        wms_duty_lab = new QLabel(tab_2);
        wms_duty_lab->setObjectName(QStringLiteral("wms_duty_lab"));

        horizontalLayout_9->addWidget(wms_duty_lab);

        wms_duty = new QDoubleSpinBox(tab_2);
        wms_duty->setObjectName(QStringLiteral("wms_duty"));

        horizontalLayout_9->addWidget(wms_duty);


        verticalLayout_wms->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        wms_maxwl_lab = new QLabel(tab_2);
        wms_maxwl_lab->setObjectName(QStringLiteral("wms_maxwl_lab"));

        horizontalLayout_10->addWidget(wms_maxwl_lab);

        wms_maxwl = new QDoubleSpinBox(tab_2);
        wms_maxwl->setObjectName(QStringLiteral("wms_maxwl"));

        horizontalLayout_10->addWidget(wms_maxwl);


        verticalLayout_wms->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        wms_minwl_lab = new QLabel(tab_2);
        wms_minwl_lab->setObjectName(QStringLiteral("wms_minwl_lab"));

        horizontalLayout_11->addWidget(wms_minwl_lab);

        wms_minwl = new QDoubleSpinBox(tab_2);
        wms_minwl->setObjectName(QStringLiteral("wms_minwl"));

        horizontalLayout_11->addWidget(wms_minwl);


        verticalLayout_wms->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        wms_sinfr_lab = new QLabel(tab_2);
        wms_sinfr_lab->setObjectName(QStringLiteral("wms_sinfr_lab"));

        horizontalLayout_12->addWidget(wms_sinfr_lab);

        wms_sinfr = new QDoubleSpinBox(tab_2);
        wms_sinfr->setObjectName(QStringLiteral("wms_sinfr"));

        horizontalLayout_12->addWidget(wms_sinfr);


        verticalLayout_wms->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        wms_sinam_lab = new QLabel(tab_2);
        wms_sinam_lab->setObjectName(QStringLiteral("wms_sinam_lab"));

        horizontalLayout_13->addWidget(wms_sinam_lab);

        wms_sinam = new QDoubleSpinBox(tab_2);
        wms_sinam->setObjectName(QStringLiteral("wms_sinam"));

        horizontalLayout_13->addWidget(wms_sinam);


        verticalLayout_wms->addLayout(horizontalLayout_13);


        horizontalLayout_3->addLayout(verticalLayout_wms);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(tdlasDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(setlazer1tcbox);
        label_4->setBuddy(doubleSpinBox_2);
        das_basefr_lab->setBuddy(das_basefr);
        das_duty_lab->setBuddy(das_duty);
        das_maxwl_lab->setBuddy(das_maxwl);
        das_minwl_lab->setBuddy(das_minwl);
        wms_basefr_lab->setBuddy(das_basefr);
        wms_duty_lab->setBuddy(das_duty);
        wms_maxwl_lab->setBuddy(das_maxwl);
        wms_minwl_lab->setBuddy(das_minwl);
        wms_sinfr_lab->setBuddy(das_minwl);
        wms_sinam_lab->setBuddy(das_minwl);
#endif // QT_NO_SHORTCUT

        retranslateUi(tdlasDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), tdlasDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tdlasDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);
        setlazer1tc->setDefault(false);
        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(tdlasDialog);
    } // setupUi

    void retranslateUi(QDialog *tdlasDialog)
    {
        tdlasDialog->setWindowTitle(QApplication::translate("tdlasDialog", "Dialog", 0));
        label->setText(QApplication::translate("tdlasDialog", "laser 1", 0));
        lazer1openclose->setText(QApplication::translate("tdlasDialog", "PushButton", 0));
        label_2->setText(QApplication::translate("tdlasDialog", "\346\270\251\345\272\246", 0));
        setlazer1tc->setText(QApplication::translate("tdlasDialog", "PushButton", 0));
        label_3->setText(QApplication::translate("tdlasDialog", "laser 2", 0));
        lazer2openclose->setText(QApplication::translate("tdlasDialog", "PushButton", 0));
        label_4->setText(QApplication::translate("tdlasDialog", "\346\270\251\345\272\246", 0));
        pushButton_2->setText(QApplication::translate("tdlasDialog", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("tdlasDialog", "laser", 0));
        das->setText(QApplication::translate("tdlasDialog", "DAS", 0));
        wms->setText(QApplication::translate("tdlasDialog", "WMS", 0));
        das_basefr_lab->setText(QApplication::translate("tdlasDialog", "\345\237\272\346\263\242\351\242\221\347\216\207", 0));
        das_duty_lab->setText(QApplication::translate("tdlasDialog", "\345\215\240\347\251\272\346\257\224", 0));
        das_maxwl_lab->setText(QApplication::translate("tdlasDialog", "\346\234\200\345\244\247\345\200\274", 0));
        das_minwl_lab->setText(QApplication::translate("tdlasDialog", "\346\234\200\345\260\217\345\200\274", 0));
        wms_basefr_lab->setText(QApplication::translate("tdlasDialog", "\345\237\272\346\263\242\351\242\221\347\216\207", 0));
        wms_duty_lab->setText(QApplication::translate("tdlasDialog", "\345\237\272\346\263\242\345\215\240\347\251\272\346\257\224", 0));
        wms_maxwl_lab->setText(QApplication::translate("tdlasDialog", "\345\237\272\346\263\242\346\234\200\345\244\247\345\200\274", 0));
        wms_minwl_lab->setText(QApplication::translate("tdlasDialog", "\345\237\272\346\263\242\346\234\200\345\260\217\345\200\274", 0));
        wms_sinfr_lab->setText(QApplication::translate("tdlasDialog", "\346\255\243\345\274\246\346\263\242\351\242\221\347\216\207(Hz)", 0));
        wms_sinam_lab->setText(QApplication::translate("tdlasDialog", "\346\255\243\345\274\246\346\263\242\345\271\205\345\200\274", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("tdlasDialog", "DAS&&WMS", 0));
    } // retranslateUi

};

namespace Ui {
    class tdlasDialog: public Ui_tdlasDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDLASDIALOG_H
