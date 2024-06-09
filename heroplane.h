#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include "bullet.h"
#include "config.h"


class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x, int y);
public:
    //飞机图片对象
    QPixmap m_Plane;
    //飞机坐标
    Pos m_pos;

    //弹匣
    Bullet m_bullets[BULLET_NUM];

    //子弹发射间隔
    int m_recorder;


    //飞机的矩形边框
    QRect m_Rect;
};

#endif // HEROPLANE_H
