#include "dialog.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource(GAME_IMAGE_PATH);//注册二进制文件资源



    Dialog w;
    w.show();

    return a.exec();
}
