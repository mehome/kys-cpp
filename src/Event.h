#pragma once
#include "save.h"
#include "Head.h"
#include <direct.h>
#include <corecrt_io.h>
#include <functional>

//#include "cocos2d.h"
//USING_NS_CC;
using namespace std;

//typedef function<int(int,int,int,int,int)> EventFunc;

class Operation
{
public:
    short num;
    vector <short> par;
};



//内部载入指令的数据流，传入值为当前指令的指针，返回值为指针需要移动的值，用宏简化代码
//#define EVENT_FUNC(name) int name(int p1=-2,int p2=-2, int p3=-2, int p4=-2,int p5=-2)

//class EventInstruct  //各种指令的实现写这里
//{
//public:
//    //static vector<EventFunc> funcs;
//public:
//    EventInstruct();
//    void clear();
//    void talk();
//
//    void XXX();
//};


class EventData
{
public:
    const vector<Operation>* getOperation();
    void setId(int num);
    bool checkId(int num);
    void arrByOperation(unsigned char* Data, int len);          //按指令进行整理数据;以后与事件组织相关的内容就以这个为基础
    int getOperationLen(int num);   //获取指令数据长度;

private:
    int _id;
    vector<Operation>_operations;
};

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();
    static EventManager eventManager;
    static EventManager* getInstance()
    {
        return &eventManager;
    }
    bool initEventData();       //加载事件数据


    bool callEvent(int num);    //调用指令的内容写这里
    std::vector<EventData> eventData;

    int eventCount = 0;
	

	void clear();
	void talk();
	int getGongtiLevel(int rnum, int gongti);
	int getRoleSpeed(int rnum, bool equip);
	int getRoleDefence(int rnum, bool equip);
	int getRoleAttack(int rnum, bool equip);
	int getRoleBoxing(int rnum, bool equip);	
	int getRoleFencing(int rnum, bool equip);	
	int getRoleKnife(int rnum, bool equip);
	int getRoleSpecial(int rnum, bool equip);
	int getRoleShader(int rnum, bool equip);
	int getRoleDefpoi(int rnum, bool equip);
	int getRoleAttpoi(int rnum, bool equip);
	int getRoleUsepoi(int rnum, bool equip);
	int getRoleAttpoi(int rnum, bool equip);
	int getRoleMedpoi(int rnum, bool equip);
	int getRoleMedicine(int rnum, bool equip);

	int GetItemCount(int inum);

	void StudyMagic(int rnum, int magicnum, int newmagicnum, int level, int dismode);

	void JumpScene(int snum, int x, int y);

	
};






