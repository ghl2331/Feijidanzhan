#ifndef MAP_H
#define MAP_H
#include<QPixmap> //图片库
#include "config.h"

class Map
{
public:
    Map();
    //地图滚动坐标计算
    void mapPosition();
public:
    //地图对象
    QPixmap m_map1;
    QPixmap m_map2;
    //地图Y轴坐标
    Pos m_map1_pos;
    Pos m_map2_pos;
    //地图滚动幅度
    int m_speed;
};

#endif // MAP_H
