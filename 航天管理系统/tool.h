#pragma once
#include"AriportRoutes.h"
#include"Pananger.h"
static int SIZE=11;
//������Ϣ
void airpote_show();
//�˿Ͳ˵�
void pannager_show();
//��ȡ�ļ�����������Ϣ
void creatairport(AriportRoutes *&airportrouts);
//��ȡ�ļ������򲹳˿���Ϣ
void ceratbackpananger(Pananger*& backpananger);
//�����յ�վ��ѯ������Ϣ
void serchairport(AriportRoutes*& airportrouts);
//��Ʊ��Ϣ
void booktiket(Pananger*& pananger,  AriportRoutes*& airportrouts,string name, Pananger*& backpananger);
//��Ʊ
void refund(Pananger*& pananger, AriportRoutes*& airportrouts, string name, Pananger*& backpananger);
//3.��    ǩ
void changeticket(Pananger*& pananger, AriportRoutes*& airportrouts, string name);
//��ʾ������Ϣ
void showperson(Pananger*& pananger, string name);
//��ʼ���˿���
void creatpananger(Pananger *&pananger);
//���ݺ���ź��û���������������
void init(Pananger *&backpananger,string name,string flight,int ticketnumber);
//�����û���ɾ����Ʊ����
void delatebackpananger(Pananger*& backpananger, string name);
//����⵽������Ʊʱ��������Ʊ����
void houbu(Pananger*& pananger, Pananger*& backpananger, AriportRoutes& airportrouts);
//������д���ļ�
void write(Pananger* pananger, AriportRoutes airportrouts[], Pananger* backpananger);
//5.�鿴������
void showall(Pananger*& backpananger);
//��ʾ��Ʊ����
void showallpananger(Pananger*& pananger);
//�鿴������Ϣ
void showairport(AriportRoutes *&airportrouts);
