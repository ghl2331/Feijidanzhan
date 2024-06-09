#include "heroplane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    m_Plane.load(PLANE_PATH);
    //初始化飞机坐标
    m_pos.m_x = (GAME_WIDTH - m_Plane.width()) / 2;
    m_pos.m_y = (GAME_HEIGHT - m_Plane.height());


    //子弹间隔记录
    m_recorder = 0;

    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_pos.m_x,m_pos.m_y);
}

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //如果记录的数字，未达到发射子弹的时间间隔，就不发
    if(m_recorder < BULLET_INIERVAL){
        return;
    }
    //发射
        m_recorder = 0;
    for(int i = 0; i < BULLET_NUM; i++){
        //如果是空闲子弹
        if(m_bullets[i].m_Free){
            //将状态转为false
            m_bullets[i].m_Free = false;
            //设置子弹目标
            m_bullets[i].m_x = m_pos.m_x + m_Rect.width() * 0.5;
            m_bullets[i].m_y = m_pos.m_y - 25;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_pos.m_x = x;
    m_pos.m_y = y;
    m_Rect.moveTo(m_pos.m_x,m_pos.m_y);
}
