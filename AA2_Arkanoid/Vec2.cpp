#include "Vec2.h"


//Default constructor
Vec2::Vec2() : x(0), y(0) {}

//Parameters constructor
Vec2::Vec2(const float _x, const float _y) : x(_x), y(_y) {}

//Copy constructor
Vec2::Vec2(const Vec2 &other) : x(other.x), y(other.y) {}

//Destructor
Vec2::~Vec2() {}
