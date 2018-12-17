#include "Vec2.h"


//Default constructor
Vec2::Vec2() : x(0), y(0) {}

//Parameters constructor
Vec2::Vec2(const int _x, const int _y) : x(_x), y(_y) {}

//Copy constructor
Vec2::Vec2(const Vec2 &other) : x(other.x), y(other.y) {}

//Destructor
Vec2::~Vec2() {}
