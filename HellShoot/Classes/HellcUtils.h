//
//  HellcUtils.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/2.
//
//

#ifndef __HellShoot__HellcUtils__
#define __HellShoot__HellcUtils__

#include "cocos2d.h"

using namespace std;


class HellcUtils
{
public:
    //获得时间
    static string getCurrentTime();
    
    //Win32将GBK编码转换为UTF-8
    static string gbk_to_utf8(const string text);
};
#endif /* defined(__HellShoot__HellcUtils__) */
