#include "map.h"
#include"config.h"
#include<iostream>
using namespace std;
Map::Map()
{
    //初始化地图对象
    m_map1.load(GAME_MAP_PATH);
    m_map2.load(GAME_MAP_PATH);
    //Y轴初始化
    m_map1_pos.m_y = -GAME_HEIGHT;
    m_map2_pos.m_y = 0;
    //设置滚动速度
    m_speed = GAME_MAP_SPEED;
}


//地图滚动坐标计算
void Map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_pos.m_y += m_speed;
    if(m_map1_pos.m_y >= 0){
        m_map1_pos.m_y = -GAME_HEIGHT;
    }
    //处理第二章图片的滚动位置
    m_map2_pos.m_y += m_speed;
    if(m_map2_pos.m_y >= GAME_HEIGHT){
        m_map2_pos.m_y = 0;
    }
}
