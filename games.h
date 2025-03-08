#pragma once
//取消UNICODE字符集
#ifdef UNICODE
#undef UNICODE
#endif

#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<string>
#include<iostream>
#include<thread>
#include<wingdi.h>
#pragma comment(lib,"winmm.lib")//加载静态库
#pragma comment( lib, "MSIMG32.LIB")
using namespace std;

//定义初始化数据
#define GAME "最终幻想XVII"

#define win_width 1280
#define win_height 720

#define button_width0 300
#define button_height0 80

#define button_width 400
#define button_height 100

#define original_HPP 500
#define original_MPP 500

#define original_HPM 5000

#define HP_width 200
#define HP_height 20

#define MP_width 200
#define MP_height 20

//绘制透明背景的PNG函数
inline void DrawPNG(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor) {
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	//使用Windows GDI函数实现透明位图
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

