#include "gameframe.h"
#include "ui_gameframe.h"
#include "config.h"
#include <CTime>
#include<QDebug>
#include<QPainter>
#include <QMouseEvent>
#include "mainwindow.h"
#include"enemyplane.h"
Gameframe::Gameframe(QWidget *parent,MainWindow * window) :
    QDialog(parent)
{
    //调用初始化场景
    initScene();
    playGame();
}

Gameframe::~Gameframe()
{
    m_Timer.stop();  // 停止定时器

}

Gameframe &Gameframe::GetInstance(MainWindow * window)//单例游戏窗口
{
    /**
     * 局部静态特性的方式实现单实例。
     * 静态局部变量只在当前函数内有效，其他函数无法访问。
     * 静态局部变量只在第一次被调用的时候初始化，也存储在静态存储区，生命周期从第一次被初始化起至程序结束止。
     */
    static Gameframe game(window);
    game.m_window = window;
    return game;

}

void Gameframe::initScene()//系统定义
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_PIC_PATH));

    //定时器的设置
    m_Timer.setInterval(GAME_RATE);
    //调用 setMouseTracking(true) 可以让窗口部件（widget）在没有按下鼠标按钮的情况下也能接收鼠标移动事件
    setMouseTracking(true);

    //随机数  时间种子
    srand((unsigned int ) time(NULL) );
}

void Gameframe::playGame()//开始游戏
{
    //启动定时器
    m_Timer.start();
    //监听信号
    connect(&m_Timer, &QTimer::timeout,[=](){
        //更新元素坐标
        updatePosition();
        //绘制到屏幕中
        update(); //会自动调用paintEvent  我们就重写paintEvent
    });

}

void Gameframe::updatePosition()//更新元素位置
{
    m_map.mapPosition();
}

void Gameframe::paintEvent(QPaintEvent *)//重新绘图
{
    //更新地图的坐标
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_pos.m_y,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_pos.m_y,m_map.m_map2);
    //绘制飞机
    painter.drawPixmap(m_HeroPlane.m_pos.m_x,m_HeroPlane.m_pos.m_y,m_HeroPlane.m_Plane);
}

void Gameframe::mouseMoveEvent(QMouseEvent *event)//重写鼠标事件
{
    //优化鼠标位置
   int x = event->x()-m_HeroPlane.m_Rect.width() * 0.5;
   int y = event->y()-m_HeroPlane.m_Rect.height() * 0.5;
   //边界检测
   if(x <= 0){
       x = 0;
   }
   if(x >= GAME_WIDTH - m_HeroPlane.m_Rect.width()){
       x = GAME_WIDTH - m_HeroPlane.m_Rect.width();
   }
   if( y <= 0){
       y = 0;
   }
   if(y >= GAME_HEIGHT - m_HeroPlane.m_Rect.height()){
       y = GAME_HEIGHT - m_HeroPlane.m_Rect.height();
   }

   m_HeroPlane.setPosition(x,y);
}

//重写游戏窗口关闭事件
void Gameframe::closeEvent(QCloseEvent *Event)
{
    if (m_window) {
        m_window->show();
        Event->accept();   // 接受关闭事件
    } else {
        qDebug() << "m_window pointer is null";
    }
}
