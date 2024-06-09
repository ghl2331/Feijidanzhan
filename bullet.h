#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>
#include<QRect>
class Bullet
{
public:
    Bullet();

    //更新子弹坐标
    void updatePostion();
public:
    //子弹图片对象
    QPixmap m_Bullet;
    //子弹坐标
    int m_x;
    int m_y;

    //子弹移动速度
    int m_Speed;

    //子弹是否闲置  考虑子弹的存储
    bool m_Free;

    //子弹的矩形边框（碰撞检测）
    QRect m_Rect;
};

#endif // BULLET_H
