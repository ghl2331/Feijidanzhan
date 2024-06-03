#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<QPixmap>
#include<QRect>

class Enemyplane
{
public:
    Enemyplane();

    //更新坐标
    void updateposition();

public:
    //敌机图片对象
    QPixmap m_EnemyPlane;
    //位置
    int m_x;
    int m_y;

    //敌机的矩形边框
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int  m_Speed;

};

#endif // ENEMYPLANE_H
