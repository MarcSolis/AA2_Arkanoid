#pragma once
class Vec2
{
public:

//Atributes
	int x, y;

//Constructors
	Vec2();
	Vec2(const int, const int);
	Vec2(const Vec2 &);
//Functions
	void ChangeVec2Values(const int&, const int&);
//Destructor
	~Vec2();
};

