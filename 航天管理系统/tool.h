#pragma once
#include"AriportRoutes.h"
#include"Pananger.h"
static int SIZE=11;
//航天信息
void airpote_show();
//乘客菜单
void pannager_show();
//读取文件创建航班信息
void creatairport(AriportRoutes *&airportrouts);
//读取文件创建候补乘客信息
void ceratbackpananger(Pananger*& backpananger);
//根据终点站查询航班信息
void serchairport(AriportRoutes*& airportrouts);
//订票信息
void booktiket(Pananger*& pananger,  AriportRoutes*& airportrouts,string name, Pananger*& backpananger);
//退票
void refund(Pananger*& pananger, AriportRoutes*& airportrouts, string name, Pananger*& backpananger);
//3.改    签
void changeticket(Pananger*& pananger, AriportRoutes*& airportrouts, string name);
//显示个人信息
void showperson(Pananger*& pananger, string name);
//初始化乘客类
void creatpananger(Pananger *&pananger);
//传递航班号和用户名姓名创建链表
void init(Pananger *&backpananger,string name,string flight,int ticketnumber);
//根据用户名删除候补票链表
void delatebackpananger(Pananger*& backpananger, string name);
//当检测到有人退票时，遍历候补票链表
void houbu(Pananger*& pananger, Pananger*& backpananger, AriportRoutes& airportrouts);
//将内容写入文件
void write(Pananger* pananger, AriportRoutes airportrouts[], Pananger* backpananger);
//5.查看候补名单
void showall(Pananger*& backpananger);
//显示订票名单
void showallpananger(Pananger*& pananger);
//查看航线信息
void showairport(AriportRoutes *&airportrouts);
