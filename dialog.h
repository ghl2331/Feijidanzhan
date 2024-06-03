#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTimer>
#include"map.h"
#include"heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

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

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionCheck();



public:
    //定时器
    QTimer m_Timer;
    //地图对象
    Map m_map;
    //飞机对象
    HeroPlane m_HeroPlane;

    //test: 子弹对象
    //Bullet temp_bullet;

    //敌机对象数组
    Enemyplane m_enemys[ENEMY_NUM];

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //敌机出现间隔
    int m_enemy_recorder;

};

#endif // DIALOG_H
