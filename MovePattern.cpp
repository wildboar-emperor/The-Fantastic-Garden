#include "stdafx.h"
#include "MovePattern.h"


MovePattern::MovePattern()
{
	timer.start();
}


MovePattern::~MovePattern()
{
}
void MovePattern::init(int* Angle, D3DXVECTOR3* Position, float �����ӵ�, D3DXVECTOR3 *Speed)
{
	this->Angle = Angle;
	this->Position = Position;
	this->�����ӵ� = �����ӵ�;
	this->Speed = Speed;
}
void MovePattern::Process()
{
}


void MovePattern::LookPoint(D3DXVECTOR3 Point)
{
	double Angle = atan2(
		(Position->y - Point.y),
		(Position->x - Point.x)
		) * 180 / Math_PI -90;

	SetAngle(ceil(Angle));
}

void MovePattern::SetAngle(int Angle)
{
	Angle %= 360;
	this->Angle = &Angle;

	Speed->x = cosf((Angle-90)* Math_PI / 180) * �����ӵ�;
	Speed->y = sinf((Angle-90)* Math_PI / 180) * �����ӵ�;
}

float MovePattern::MoveTime(D3DXVECTOR3 Point)
{
	return sqrt(
		pow(Point.x - Position->x, 2) +
		pow(Point.y - Position->y, 2)) / �����ӵ�;
}