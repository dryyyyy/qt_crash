/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionMirror;
    QAction *actionNegative;
    QAction *actionTurn_clockwise;
    QAction *actionTurn_counter_clockwise;
    QAction *actionsave;
    QAction *actionSave_as;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->resize(677, 422);
        actionOpen = new QAction(ImageViewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(ImageViewer);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionMirror = new QAction(ImageViewer);
        actionMirror->setObjectName(QStringLiteral("actionMirror"));
        actionNegative = new QAction(ImageViewer);
        actionNegative->setObjectName(QStringLiteral("actionNegative"));
        actionTurn_clockwise = new QAction(ImageViewer);
        actionTurn_clockwise->setObjectName(QStringLiteral("actionTurn_clockwise"));
        actionTurn_counter_clockwise = new QAction(ImageViewer);
        actionTurn_counter_clockwise->setObjectName(QStringLiteral("actionTurn_counter_clockwise"));
        actionsave = new QAction(ImageViewer);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionSave_as = new QAction(ImageViewer);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        centralWidget = new QWidget(ImageViewer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 347));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 80, 120, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 78));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 220, 211, 91));
        ImageViewer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        ImageViewer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageViewer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageViewer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageViewer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageViewer->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionsave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionMirror);
        menuEdit->addAction(actionNegative);
        menuEdit->addAction(actionTurn_clockwise);
        menuEdit->addAction(actionTurn_counter_clockwise);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "ImageViewer", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ImageViewer", "Open", Q_NULLPTR));
        actionClose->setText(QApplication::translate("ImageViewer", "Close", Q_NULLPTR));
        actionMirror->setText(QApplication::translate("ImageViewer", "Mirror", Q_NULLPTR));
        actionNegative->setText(QApplication::translate("ImageViewer", "Negative", Q_NULLPTR));
        actionTurn_clockwise->setText(QApplication::translate("ImageViewer", "Turn clockwise", Q_NULLPTR));
        actionTurn_counter_clockwise->setText(QApplication::translate("ImageViewer", "Turn counter clockwise", Q_NULLPTR));
        actionsave->setText(QApplication::translate("ImageViewer", "Save", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("ImageViewer", "Save as", Q_NULLPTR));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("ImageViewer", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("ImageViewer", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
