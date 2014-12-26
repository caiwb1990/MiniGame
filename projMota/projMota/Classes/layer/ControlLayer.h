#ifndef __CONTROLLAYER_H__
#define __CONTROLLAYER_H__

#include "MTGame.h"

USING_NS_CC;

class ControlLayer : public CCLayer
{
public:
	ControlLayer(void);
	~ControlLayer(void);
    
	//node方法会调用此函数
	virtual bool init();
    
	CREATE_FUNC(ControlLayer);
    
	//方向按钮点击事件的回调
	void menuCallBackMove(CCObject* pSender);
    
	//关闭按钮点击事件的回调
	void menuCloseCallback(CCObject* pSender);
};

#endif
