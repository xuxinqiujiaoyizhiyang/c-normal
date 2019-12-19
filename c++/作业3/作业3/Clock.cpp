#include "Clock.h"
#include <iostream>


using namespace std;
Clock::Clock(int NewH, int NewM, int NewS)
{
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
	cout << "Constructor called" << endl;
}

Clock::~Clock() {
	cout << "Desturctor called.\n";
}

void Clock::ShowTime() {
	cout << "Ê±¼äÎª£º" << Hour << ":" << Minute << ":" << Second;
}