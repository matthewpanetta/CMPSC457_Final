#pragma once
class Building
{
public:
	Building();
	float get_x();
	float get_y();
	void draw_building();
	~Building();
private:
	float x, y;
};

