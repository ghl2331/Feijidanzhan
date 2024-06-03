#ifndef CONFIG_H
#define CONFIG_H

/*****游戏配置******/
#define GAME_WIDTH  480  //宽度
#define GAME_HEIGHT 700  //高度
#define GAME_TITLE "飞机大战 v1.0"       //标题
#define GAME_IMAGE_PATH "./plane.rcc"       //rcc二进制文件路径
#define GAME_PIC_PATH ":/feijidazhan__images/images/enemy2.png"    //图标加载路径
#define GAME_RATE 10     //ms      定时器刷新时间间隔

/******地图配置******/
#define GAME_MAP_PATH ":/feijidazhan__images/images/background.png"
#define GAME_MAP_SPEED 2

/*******飞机配置******/
#define PLANE_PATH ":/feijidazhan__images/images/me1.png"

/*******敌机配置******/
#define ENEMY_PLANE_PATH ":/feijidazhan__images/images/enemy1.png"
#define ENEMY_NUM  20 //敌机数目
#define ENEMY_SPEED  5 //敌机速度
#define ENEMY_INTERVAL 30 //敌机出场时间间隔


/*******子弹配置******/
#define BULLET_PATH ":/feijidazhan__images/images/bullet1.png"
#define BULLET_SPEED 5
#define BULLET_NUM 30
#define BULLET_INIERVAL 20


/******爆炸******/
#define BOMB_PATH ":/feijidazhan__images/images/enemy1_down%1.png"
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 4 //爆炸播放图片
#define BOMB_INTERVAL  20 //爆炸图片切换间隔


#endif // CONFIG_H
