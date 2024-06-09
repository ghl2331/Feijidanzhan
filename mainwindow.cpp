// mainwindow.cpp
#include "mainwindow.h"
#include <QCoreApplication>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "Getting instance of Gameframe with MainWindow pointer: " << this;
    m_game =  (Gameframe*)&Gameframe::GetInstance(this);
    //设置窗口固定尺寸
    setFixedSize(GAME_START_WIDTH,GAME_START_HEIGHT);

    setWindowTitle("飞机大战v2.0");

    // 创建开始按钮
    startButton = new QPushButton("开始游戏", this);
    startButton->setGeometry(100, 100, 200, 50);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);

    // 创建退出按钮
    exitButton = new QPushButton("退出游戏", this);
    exitButton->setGeometry(100, 200, 200, 50);


    //connect函数的第三个参数是可选的Qt会自动识别信号发送者并将其作为第三个参数。
    connect(exitButton, &QPushButton::clicked,/*QCoreApplication::instance(),*/&QCoreApplication::quit);

    //当您调用QCoreApplication::instance()时，返回的指针可能是一个指向QCoreApplication或者QApplication的指针
}

MainWindow::~MainWindow()
{
}

void MainWindow::startGame()
{
    // 在这里处理点击开始按钮后的逻辑，比如进入游戏界面
    m_game->show();
    this->hide();

}


