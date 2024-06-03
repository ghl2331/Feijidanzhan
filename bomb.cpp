#include "bomb.h"

Bomb::Bomb()
{
    //所有爆炸资源 放入数组
    for(int i = 1; i <= BOMB_MAX; i++){
        QString str = QString (BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    m_x = 0;
    m_y = 0;

    //空闲状态
    m_Free = true;

    //当前播放图片下标
    m_index = 0;

    //爆炸间隔
    m_Recorder = 0;
}

void Bomb::updateInfo()
{
    //空闲状态
    if(m_Free){
        return;
    }
    m_Recorder++;
    if(m_Recorder < BOMB_INTERVAL){  //爆炸切换间隔
        return;
    }

    //重置记录
    m_Recorder= 0;

    //切换爆炸图片  即下标
    m_index++;
    if(m_index > BOMB_MAX - 1){// > 满足就说明爆炸完毕
        m_index = 0;
        m_Free = true;
    }
}
