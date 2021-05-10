#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct{
    std::pair<int, int> coor1;
    std::pair<int, int> coor2;
} s_range;

extern int curIndex;
extern std::vector<s_range> shipList;

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int lookupShip(int sRow, int sColumn);

    void on_ship_clicked(char shiptype);

    void on_commonButton_clicked(const QObject * sender);

private slots:

    void on_player1board_itemClicked(QTableWidgetItem *item);

    void on_player1board_cellClicked(int row, int column);

    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();

    void on_rotateButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
