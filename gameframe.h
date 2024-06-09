#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QDialog>
#include<QTimer>
#include "map.h"
#include"heroplane.h"
#include"mainwindow.h"

class MainWindow;

namespace Ui {
class Gameframe;
}

class Gameframe : public QDialog
{
    Q_OBJECT
private:
    explicit Gameframe(QWidget *parent = 0,MainWindow * window = nullptr);
    ~Gameframe();
    //禁止外部拷贝构造
    Gameframe(const Gameframe &gameframe ) = delete;
    //禁止外部赋值操作
    const Gameframe &operator=(const Gameframe &gameframe ) = delete;

public:
    static Gameframe& GetInstance(MainWindow* window);
     //初始化场景
    void initScene();
    //启动游戏
    void playGame();
    //更新
    void updatePosition();
    //绘制   //函数名称不能改QT
    void  paintEvent(QPaintEvent* );
    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);
    //重写游戏窗口关闭事件
    void closeEvent(QCloseEvent * Event);

private:
    Ui::Gameframe *ui;
public:
    //主界面对象指针
    MainWindow* m_window;
    //定时器
    QTimer m_Timer;
    //地图对象
    Map m_map;
    //玩家飞机对象
    HeroPlane m_HeroPlane;
};

#endif // GAMEFRAME_H
