#ifndef CARD_H
#define CARD_H
#include<QString>
//T=1 leader
//T=2 gold
//T=3 silver
//T=4 bronze
//Ability  1
#define CSIZEW width()/8
#define CSIZEH height()/4
#define GCSIZEW width()/24
#define GCSIZEH height()/12
class Card
{
public:
    int attack;//攻击力
    int num;//卡牌数
    int T;//金银铜
    int id;//编号
    int job;//战场位置1，2，3。 4指魔法
    int quality;//属性
    int where;
    QString name;//卡牌名称
    QString path;//图片路径
    int ability;//魔法效果，怪物特效
    Card(QString name="",int attack=0,int num=0,int T=0,int id=0,int job=0,int quality=0,QString path="",int ability=0,int where=0)
    {
     this->name = name;
     this->attack = attack;
     this->num = num;
     this->job=job;
     this->quality=quality;
     this->T = T;
     this->id = id;
     this->path = path;
     this->ability = ability;
     this->where = where;
    }

public:
    void defCard();
};
//void makeit(int mn);
#endif // CARD_H
