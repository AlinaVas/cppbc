#include "Move.h"
#include <iostream>

Move::Move(double a /*= 0*/, double b /*= 0*/) : x(a), y(b) {}

void
Move::showmove() const {
	
	cout << "x: " << x << ", y: " << y << endl;
}

Move
Move::add(const Move & m) const {

	Move obj(x + m.x, y + m.y);
	return obj;
}

void
Move::reset(double a /*= 0*/, double b /*= 0*/) {

	x = a;
	y = b;
}
