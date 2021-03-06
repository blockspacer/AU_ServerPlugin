#pragma once

#include "Lock.h"
#include "CHElement.h"
#include "windows.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
// #include <API/ARK/Ark.h>

class ConsoleHelper {

	HANDLE _stdout, _stdin;
	CHRenderElement *curhovered;

public:
	int w, h;
	static ConsoleHelper *instance;

	std::map<std::string, CHElement *> elements;
	std::vector<CHRenderElement *> renderElements;
	std::map<std::string, CHRenderElement *> needRedrawElements;

	Lock elementsLock, outLock, updateLock, deleteLock;

	HANDLE hthread;
	volatile bool needExit, executeState;

	ConsoleHelper();
	virtual ~ConsoleHelper();

	void addElement(CHElement *element);
	void delElement(CHElement *element);

	CHElement *getElement(std::string name);
	static CHElement *_getElement(std::string name);

	void moveElement(CHRenderElement *element, int, int);
	void drawElement(CHRenderElement *element);
	void updateElements();

	void outstr(std::string, bool nc, int w);
	void outWithSpaces(std::string s, bool nc, int w, bool waling);

	void processInpitEvents();

	virtual void onKey(KEY_EVENT_RECORD ke);
	virtual void onMouse(MOUSE_EVENT_RECORD me);

	void clear();

	void setPos(int x, int y);
	DWORD thread();
};
