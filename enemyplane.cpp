#include "enemyplane.h"
#include"config.h"

Enemyplane::Enemyplane()
{
    //敌机资源
   m_EnemyPlane.load(ENEMY_PLANE_PATH);

   //敌机的位置
   m_x = 0;
   m_y = 0;

   //敌机状态
   m_Free = true;

   //敌机速度
   m_Speed = ENEMY_SPEED;

   //敌机矩形  -- 碰撞判断
   m_Rect.setWidth(m_EnemyPlane.width());
   m_Rect.setHeight(m_EnemyPlane.height());
   m_Rect.moveTo(m_x,m_y);
}

void Enemyplane::updateposition()
{
    //空闲状态敌机不计算坐标
    if(m_Free){
        return;
    }
    m_y += m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //超出屏幕  重置空闲状态
    if(m_y >= GAME_HEIGHT + m_Rect.height()){
        m_Free = true;
    }

}
