#include "bullet.h"
#include "config.h"

Bullet::Bullet()
{
    //加载图片资源
    m_Bullet.load(BULLET_PATH);

    //子弹的坐标
    m_x = GAME_WIDTH / 2.0 - m_Bullet.width() / 2.0;
    m_y = GAME_HEIGHT;

    //子弹状态
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框设置
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);
}

void Bullet::updatePostion()
{
    if(m_Free){//空闲不需要计算位置
        return;
    }
    //子弹向上移动
    m_y -= m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //状态改变
    if(m_y <= -m_Rect.height()){//子弹超出窗口
        m_Free = true;
    }
}
