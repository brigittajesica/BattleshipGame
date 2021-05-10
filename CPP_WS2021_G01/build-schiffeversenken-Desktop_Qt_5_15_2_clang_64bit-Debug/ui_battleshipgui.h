/********************************************************************************
** Form generated from reading UI file 'battleshipgui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLESHIPGUI_H
#define UI_BATTLESHIPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BattleshipGUI
{
public:
    QWidget *centralwidget;
    QLabel *instructions;
    QGroupBox *shipGroup;
    QPushButton *ship1;
    QPushButton *ship2;
    QPushButton *ship4;
    QPushButton *ship3;
    QPushButton *ship6;
    QPushButton *ship5;
    QPushButton *ship8;
    QPushButton *ship7;
    QPushButton *ship10;
    QPushButton *ship9;
    QLabel *player1winlose;
    QTableView *player1board;
    QLabel *player2label;
    QPushButton *commonButton;
    QLabel *player1label;
    QPushButton *startgame;
    QLabel *player2winlose;
    QPushButton *doneButton;
    QTableView *player2board;
    QLabel *welcomeText;
    QPushButton *showButton;
    QPushButton *rotateButton;
    QTableView *player2shotboard;
    QTableView *player1shotboard;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BattleshipGUI)
    {
        if (BattleshipGUI->objectName().isEmpty())
            BattleshipGUI->setObjectName(QString::fromUtf8("BattleshipGUI"));
        BattleshipGUI->resize(720, 535);
        centralwidget = new QWidget(BattleshipGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        instructions = new QLabel(centralwidget);
        instructions->setObjectName(QString::fromUtf8("instructions"));
        instructions->setGeometry(QRect(20, 70, 671, 71));
        QFont font;
        font.setPointSize(14);
        instructions->setFont(font);
        shipGroup = new QGroupBox(centralwidget);
        shipGroup->setObjectName(QString::fromUtf8("shipGroup"));
        shipGroup->setGeometry(QRect(280, 150, 151, 281));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Marker Felt"));
        font1.setItalic(true);
        shipGroup->setFont(font1);
        shipGroup->setAutoFillBackground(false);
        shipGroup->setStyleSheet(QString::fromUtf8("background-color: rgba(46, 204, 113, 0.4);\n"
""));
        ship1 = new QPushButton(shipGroup);
        ship1->setObjectName(QString::fromUtf8("ship1"));
        ship1->setGeometry(QRect(5, 25, 100, 23));
        QFont font2;
        font2.setPointSize(10);
        ship1->setFont(font2);
        ship1->setMouseTracking(false);
        ship1->setAutoFillBackground(false);
        ship1->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left;"));
        ship2 = new QPushButton(shipGroup);
        ship2->setObjectName(QString::fromUtf8("ship2"));
        ship2->setGeometry(QRect(5, 50, 100, 23));
        ship2->setFont(font2);
        ship2->setMouseTracking(false);
        ship2->setAutoFillBackground(false);
        ship2->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship4 = new QPushButton(shipGroup);
        ship4->setObjectName(QString::fromUtf8("ship4"));
        ship4->setGeometry(QRect(5, 100, 100, 23));
        ship4->setFont(font2);
        ship4->setMouseTracking(false);
        ship4->setAutoFillBackground(false);
        ship4->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left;"));
        ship3 = new QPushButton(shipGroup);
        ship3->setObjectName(QString::fromUtf8("ship3"));
        ship3->setGeometry(QRect(5, 75, 100, 23));
        ship3->setFont(font2);
        ship3->setMouseTracking(false);
        ship3->setAutoFillBackground(false);
        ship3->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left;"));
        ship6 = new QPushButton(shipGroup);
        ship6->setObjectName(QString::fromUtf8("ship6"));
        ship6->setGeometry(QRect(5, 150, 100, 23));
        ship6->setFont(font2);
        ship6->setMouseTracking(false);
        ship6->setAutoFillBackground(false);
        ship6->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship5 = new QPushButton(shipGroup);
        ship5->setObjectName(QString::fromUtf8("ship5"));
        ship5->setGeometry(QRect(5, 125, 100, 23));
        ship5->setFont(font2);
        ship5->setMouseTracking(false);
        ship5->setAutoFillBackground(false);
        ship5->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship8 = new QPushButton(shipGroup);
        ship8->setObjectName(QString::fromUtf8("ship8"));
        ship8->setGeometry(QRect(5, 200, 100, 23));
        ship8->setFont(font2);
        ship8->setMouseTracking(false);
        ship8->setAutoFillBackground(false);
        ship8->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship7 = new QPushButton(shipGroup);
        ship7->setObjectName(QString::fromUtf8("ship7"));
        ship7->setGeometry(QRect(5, 175, 100, 23));
        ship7->setFont(font2);
        ship7->setMouseTracking(false);
        ship7->setAutoFillBackground(false);
        ship7->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship10 = new QPushButton(shipGroup);
        ship10->setObjectName(QString::fromUtf8("ship10"));
        ship10->setGeometry(QRect(5, 250, 100, 23));
        ship10->setFont(font2);
        ship10->setMouseTracking(false);
        ship10->setAutoFillBackground(false);
        ship10->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        ship9 = new QPushButton(shipGroup);
        ship9->setObjectName(QString::fromUtf8("ship9"));
        ship9->setGeometry(QRect(5, 225, 100, 23));
        ship9->setFont(font2);
        ship9->setMouseTracking(false);
        ship9->setAutoFillBackground(false);
        ship9->setStyleSheet(QString::fromUtf8("background-color: rgba(213, 50, 92, 0.8);\n"
"Text-align:left"));
        player1winlose = new QLabel(centralwidget);
        player1winlose->setObjectName(QString::fromUtf8("player1winlose"));
        player1winlose->setGeometry(QRect(20, 410, 91, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Marker Felt"));
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setWeight(75);
        player1winlose->setFont(font3);
        player1board = new QTableView(centralwidget);
        player1board->setObjectName(QString::fromUtf8("player1board"));
        player1board->setGeometry(QRect(20, 150, 222, 222));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1board->sizePolicy().hasHeightForWidth());
        player1board->setSizePolicy(sizePolicy);
        player1board->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player1board->setAutoFillBackground(true);
        player1board->setStyleSheet(QString::fromUtf8(""));
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
        player1board->setSelectionMode(QAbstractItemView::SingleSelection);
        player1board->setIconSize(QSize(0, 0));
        player1board->setGridStyle(Qt::DashDotDotLine);
        player1board->setSortingEnabled(false);
        player2label = new QLabel(centralwidget);
        player2label->setObjectName(QString::fromUtf8("player2label"));
        player2label->setGeometry(QRect(470, 380, 221, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("American Typewriter"));
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        player2label->setFont(font4);
        commonButton = new QPushButton(centralwidget);
        commonButton->setObjectName(QString::fromUtf8("commonButton"));
        commonButton->setGeometry(QRect(0, 10, 0, 0));
        player1label = new QLabel(centralwidget);
        player1label->setObjectName(QString::fromUtf8("player1label"));
        player1label->setGeometry(QRect(20, 380, 221, 31));
        player1label->setFont(font4);
        startgame = new QPushButton(centralwidget);
        startgame->setObjectName(QString::fromUtf8("startgame"));
        startgame->setGeometry(QRect(20, 20, 131, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Marker Felt"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        startgame->setFont(font5);
        startgame->setAutoFillBackground(false);
        startgame->setStyleSheet(QString::fromUtf8("background-color: rgba(46, 204, 113, 0.4);\n"
""));
        player2winlose = new QLabel(centralwidget);
        player2winlose->setObjectName(QString::fromUtf8("player2winlose"));
        player2winlose->setGeometry(QRect(470, 410, 91, 31));
        player2winlose->setFont(font3);
        doneButton = new QPushButton(centralwidget);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));
        doneButton->setGeometry(QRect(275, 440, 71, 32));
        doneButton->setStyleSheet(QString::fromUtf8(""));
        player2board = new QTableView(centralwidget);
        player2board->setObjectName(QString::fromUtf8("player2board"));
        player2board->setGeometry(QRect(470, 150, 222, 222));
        sizePolicy.setHeightForWidth(player2board->sizePolicy().hasHeightForWidth());
        player2board->setSizePolicy(sizePolicy);
        player2board->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player2board->setAutoFillBackground(false);
        player2board->setStyleSheet(QString::fromUtf8(""));
        player2board->setFrameShape(QFrame::Box);
        player2board->setFrameShadow(QFrame::Plain);
        player2board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2board->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player2board->setAutoScroll(false);
        player2board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        player2board->setDragEnabled(false);
        player2board->setDragDropOverwriteMode(false);
        player2board->setDragDropMode(QAbstractItemView::NoDragDrop);
        player2board->setDefaultDropAction(Qt::IgnoreAction);
        player2board->setSelectionMode(QAbstractItemView::SingleSelection);
        player2board->setIconSize(QSize(0, 0));
        player2board->setGridStyle(Qt::DashDotDotLine);
        player2board->setSortingEnabled(false);
        welcomeText = new QLabel(centralwidget);
        welcomeText->setObjectName(QString::fromUtf8("welcomeText"));
        welcomeText->setEnabled(true);
        welcomeText->setGeometry(QRect(150, 70, 431, 51));
        QFont font6;
        font6.setFamily(QString::fromUtf8("American Typewriter"));
        font6.setPointSize(32);
        welcomeText->setFont(font6);
        showButton = new QPushButton(centralwidget);
        showButton->setObjectName(QString::fromUtf8("showButton"));
        showButton->setGeometry(QRect(360, 440, 71, 32));
        showButton->setStyleSheet(QString::fromUtf8(""));
        rotateButton = new QPushButton(centralwidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setGeometry(QRect(579, 410, 61, 25));
        rotateButton->setAutoFillBackground(false);
        rotateButton->setStyleSheet(QString::fromUtf8("background-color: rgba(194, 225, 107,1)"));
        player2shotboard = new QTableView(centralwidget);
        player2shotboard->setObjectName(QString::fromUtf8("player2shotboard"));
        player2shotboard->setGeometry(QRect(20, 150, 222, 222));
        sizePolicy.setHeightForWidth(player2shotboard->sizePolicy().hasHeightForWidth());
        player2shotboard->setSizePolicy(sizePolicy);
        player2shotboard->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player2shotboard->setAutoFillBackground(true);
        player2shotboard->setStyleSheet(QString::fromUtf8(""));
        player2shotboard->setFrameShape(QFrame::Box);
        player2shotboard->setFrameShadow(QFrame::Plain);
        player2shotboard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2shotboard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player2shotboard->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player2shotboard->setAutoScroll(false);
        player2shotboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        player2shotboard->setDragEnabled(false);
        player2shotboard->setDragDropOverwriteMode(false);
        player2shotboard->setDragDropMode(QAbstractItemView::NoDragDrop);
        player2shotboard->setDefaultDropAction(Qt::IgnoreAction);
        player2shotboard->setSelectionMode(QAbstractItemView::SingleSelection);
        player2shotboard->setIconSize(QSize(0, 0));
        player2shotboard->setGridStyle(Qt::DashDotDotLine);
        player2shotboard->setSortingEnabled(false);
        player1shotboard = new QTableView(centralwidget);
        player1shotboard->setObjectName(QString::fromUtf8("player1shotboard"));
        player1shotboard->setGeometry(QRect(470, 150, 222, 222));
        sizePolicy.setHeightForWidth(player1shotboard->sizePolicy().hasHeightForWidth());
        player1shotboard->setSizePolicy(sizePolicy);
        player1shotboard->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        player1shotboard->setAutoFillBackground(false);
        player1shotboard->setStyleSheet(QString::fromUtf8(""));
        player1shotboard->setFrameShape(QFrame::Box);
        player1shotboard->setFrameShadow(QFrame::Plain);
        player1shotboard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player1shotboard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        player1shotboard->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player1shotboard->setAutoScroll(false);
        player1shotboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        player1shotboard->setDragEnabled(false);
        player1shotboard->setDragDropOverwriteMode(false);
        player1shotboard->setDragDropMode(QAbstractItemView::NoDragDrop);
        player1shotboard->setDefaultDropAction(Qt::IgnoreAction);
        player1shotboard->setSelectionMode(QAbstractItemView::SingleSelection);
        player1shotboard->setIconSize(QSize(0, 0));
        player1shotboard->setGridStyle(Qt::DashDotDotLine);
        player1shotboard->setSortingEnabled(false);
        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setGeometry(QRect(120, 430, 113, 21));
        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
        lineEdit2->setGeometry(QRect(120, 450, 113, 21));
        BattleshipGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BattleshipGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 22));
        BattleshipGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(BattleshipGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BattleshipGUI->setStatusBar(statusbar);

        retranslateUi(BattleshipGUI);

        QMetaObject::connectSlotsByName(BattleshipGUI);
    } // setupUi

    void retranslateUi(QMainWindow *BattleshipGUI)
    {
        BattleshipGUI->setWindowTitle(QCoreApplication::translate("BattleshipGUI", "MainWindow", nullptr));
        instructions->setText(QString());
        shipGroup->setTitle(QCoreApplication::translate("BattleshipGUI", "SHIPS", nullptr));
        ship1->setText(QCoreApplication::translate("BattleshipGUI", "ship1", nullptr));
        ship2->setText(QCoreApplication::translate("BattleshipGUI", "ship2", nullptr));
        ship4->setText(QCoreApplication::translate("BattleshipGUI", "ship4", nullptr));
        ship3->setText(QCoreApplication::translate("BattleshipGUI", "ship3", nullptr));
        ship6->setText(QCoreApplication::translate("BattleshipGUI", "ship6", nullptr));
        ship5->setText(QCoreApplication::translate("BattleshipGUI", "ship5", nullptr));
        ship8->setText(QCoreApplication::translate("BattleshipGUI", "ship8", nullptr));
        ship7->setText(QCoreApplication::translate("BattleshipGUI", "ship7", nullptr));
        ship10->setText(QCoreApplication::translate("BattleshipGUI", "ship10", nullptr));
        ship9->setText(QCoreApplication::translate("BattleshipGUI", "ship9", nullptr));
        player1winlose->setText(QCoreApplication::translate("BattleshipGUI", "WIN", nullptr));
        player2label->setText(QCoreApplication::translate("BattleshipGUI", "Player 2", nullptr));
        commonButton->setText(QString());
        player1label->setText(QCoreApplication::translate("BattleshipGUI", "Player 1", nullptr));
        startgame->setText(QCoreApplication::translate("BattleshipGUI", "START GAME", nullptr));
        player2winlose->setText(QCoreApplication::translate("BattleshipGUI", "WIN", nullptr));
        doneButton->setText(QCoreApplication::translate("BattleshipGUI", "DONE", nullptr));
        welcomeText->setText(QCoreApplication::translate("BattleshipGUI", "WELCOME TO BATTLESHIP", nullptr));
        showButton->setText(QCoreApplication::translate("BattleshipGUI", "SHOW", nullptr));
        rotateButton->setText(QCoreApplication::translate("BattleshipGUI", "Rotate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BattleshipGUI: public Ui_BattleshipGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLESHIPGUI_H
