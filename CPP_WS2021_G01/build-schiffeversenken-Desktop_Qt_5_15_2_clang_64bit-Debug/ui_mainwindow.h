/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *player1board;
    QTableWidget *player2board;
    QLabel *player1label;
    QLabel *player2label;
    QLabel *player1winlose;
    QLabel *player2winlose;
    QPushButton *startgame;
    QLabel *instructions;
    QGroupBox *groupBox;
    QPushButton *ship1;
    QPushButton *ship1_2;
    QGroupBox *groupBox_2;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *upButton;
    QPushButton *leftButton;
    QPushButton *rotateButton;
    QPushButton *commonButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(682, 513);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        player1board = new QTableView(centralwidget);
        player1board->setObjectName(QString::fromUtf8("player1board"));
        player1board->setGeometry(QRect(20, 130, 221, 221));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1board->sizePolicy().hasHeightForWidth());
        player1board->setSizePolicy(sizePolicy);
        player1board->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player1board->setFrameShape(QFrame::Box);
        player1board->setFrameShadow(QFrame::Plain);
        player1board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player1board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player1board->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player1board->setAutoScroll(false);
        player1board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        player1board->setDragEnabled(false);
        player1board->setDragDropOverwriteMode(false);
        player1board->setDragDropMode(QAbstractItemView::NoDragDrop);
        player1board->setDefaultDropAction(Qt::IgnoreAction);
        player1board->setSelectionMode(QAbstractItemView::ExtendedSelection);
        player1board->setIconSize(QSize(0, 0));
        player1board->setGridStyle(Qt::DashDotDotLine);
        player1board->setSortingEnabled(false);
        player2board = new QTableWidget(centralwidget);
        if (player2board->columnCount() < 10)
            player2board->setColumnCount(10);
        if (player2board->rowCount() < 10)
            player2board->setRowCount(10);
        player2board->setObjectName(QString::fromUtf8("player2board"));
        player2board->setGeometry(QRect(440, 130, 221, 221));
        sizePolicy.setHeightForWidth(player2board->sizePolicy().hasHeightForWidth());
        player2board->setSizePolicy(sizePolicy);
        player2board->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player2board->setFrameShape(QFrame::Box);
        player2board->setFrameShadow(QFrame::Plain);
        player2board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2board->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player2board->setAutoScroll(false);
        player2board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        player2board->setSelectionMode(QAbstractItemView::SingleSelection);
        player2board->setIconSize(QSize(0, 0));
        player2board->setGridStyle(Qt::DashDotDotLine);
        player2board->setSortingEnabled(false);
        player2board->setRowCount(10);
        player2board->setColumnCount(10);
        player2board->horizontalHeader()->setVisible(false);
        player2board->horizontalHeader()->setCascadingSectionResizes(false);
        player2board->horizontalHeader()->setMinimumSectionSize(20);
        player2board->horizontalHeader()->setDefaultSectionSize(22);
        player2board->verticalHeader()->setVisible(false);
        player2board->verticalHeader()->setMinimumSectionSize(20);
        player2board->verticalHeader()->setDefaultSectionSize(22);
        player1label = new QLabel(centralwidget);
        player1label->setObjectName(QString::fromUtf8("player1label"));
        player1label->setGeometry(QRect(20, 360, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("American Typewriter"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        player1label->setFont(font);
        player2label = new QLabel(centralwidget);
        player2label->setObjectName(QString::fromUtf8("player2label"));
        player2label->setGeometry(QRect(440, 360, 111, 31));
        player2label->setFont(font);
        player1winlose = new QLabel(centralwidget);
        player1winlose->setObjectName(QString::fromUtf8("player1winlose"));
        player1winlose->setGeometry(QRect(20, 390, 51, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Marker Felt"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        player1winlose->setFont(font1);
        player2winlose = new QLabel(centralwidget);
        player2winlose->setObjectName(QString::fromUtf8("player2winlose"));
        player2winlose->setGeometry(QRect(440, 390, 51, 31));
        player2winlose->setFont(font1);
        startgame = new QPushButton(centralwidget);
        startgame->setObjectName(QString::fromUtf8("startgame"));
        startgame->setGeometry(QRect(20, 10, 131, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Marker Felt"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        startgame->setFont(font2);
        startgame->setAutoFillBackground(false);
        startgame->setStyleSheet(QString::fromUtf8("background-color: rgba(46, 204, 113, 0.4);\n"
""));
        instructions = new QLabel(centralwidget);
        instructions->setObjectName(QString::fromUtf8("instructions"));
        instructions->setGeometry(QRect(30, 70, 631, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(270, 130, 131, 221));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Marker Felt"));
        font3.setItalic(true);
        groupBox->setFont(font3);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgba(46, 204, 113, 0.4);\n"
""));
        ship1 = new QPushButton(groupBox);
        ship1->setObjectName(QString::fromUtf8("ship1"));
        ship1->setGeometry(QRect(0, 20, 60, 25));
        ship1->setAutoFillBackground(false);
        ship1->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8)"));
        ship1_2 = new QPushButton(groupBox);
        ship1_2->setObjectName(QString::fromUtf8("ship1_2"));
        ship1_2->setGeometry(QRect(0, 50, 100, 25));
        ship1_2->setMouseTracking(false);
        ship1_2->setAutoFillBackground(false);
        ship1_2->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8)"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 360, 131, 91));
        rightButton = new QPushButton(groupBox_2);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setGeometry(QRect(60, 40, 25, 25));
        rightButton->setAutoFillBackground(false);
        rightButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 190, 0, 1)"));
        downButton = new QPushButton(groupBox_2);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(30, 55, 25, 25));
        downButton->setAutoFillBackground(false);
        downButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 190, 0, 1)"));
        upButton = new QPushButton(groupBox_2);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(30, 25, 25, 25));
        upButton->setAutoFillBackground(false);
        upButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 190, 0, 1)\n"
""));
        leftButton = new QPushButton(groupBox_2);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setGeometry(QRect(0, 40, 25, 25));
        leftButton->setAutoFillBackground(false);
        leftButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 190, 0, 1)"));
        rotateButton = new QPushButton(groupBox_2);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setGeometry(QRect(95, 40, 30, 25));
        rotateButton->setAutoFillBackground(false);
        rotateButton->setStyleSheet(QString::fromUtf8("background-color: rgba(194, 225, 107,1)"));
        commonButton = new QPushButton(centralwidget);
        commonButton->setObjectName(QString::fromUtf8("commonButton"));
        commonButton->setGeometry(QRect(0, 0, 0, 0));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 682, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(startgame, SIGNAL(clicked()), groupBox, SLOT(show()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        player1label->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        player2label->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        player1winlose->setText(QCoreApplication::translate("MainWindow", "WIN", nullptr));
        player2winlose->setText(QCoreApplication::translate("MainWindow", "WIN", nullptr));
        startgame->setText(QCoreApplication::translate("MainWindow", "START GAME", nullptr));
        instructions->setText(QCoreApplication::translate("MainWindow", "INSTRUCTIONS: ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "SHIPS", nullptr));
        ship1->setText(QCoreApplication::translate("MainWindow", "ship_1", nullptr));
        ship1_2->setText(QCoreApplication::translate("MainWindow", "ship_1", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Move Ship         Rotate", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "ROT", nullptr));
        commonButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
