#include "battleshipgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc > 1 && strncmp(argv[1], "--cliOnly", 9)==0) {
        Game game;
        game.startCli();
        return 0;
    } else {
        QApplication a(argc, argv);
        BattleshipGUI w;
        w.show();
        return a.exec();
    }
}
