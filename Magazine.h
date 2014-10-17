#pragma once
#include "Bullet.h"
#include "TimeCounter.h"
#include <list>
#include "SoundManager.h"
template <class T>
class Magazine
{
public:
	std::list<T> list;
	T *t_bullet;
	TimeCounter Bullettimer;

	float BltDelay;
	int BltAngle;
	int Angle;

	int Attack_Damage;
	float bltSpeed;
	D3DXVECTOR3 *bltMother;

	TimeCounter �����߻�������Ÿ�̸�;
	int �߻�Ƚ��;
	int �ִ�߻�Ƚ��;
	float �߻�Ƚ������õ�����;
	int �Ѿ˼Ҹ�;

public:
	Magazine()
	{
		//Init();
	}

	~Magazine()
	{
		//Release();
	}

public:
	void Init()
	{
		t_bullet = new T;
	}

	void Release()
	{
		SAFE_DELETE(t_bullet);
	}

	void SetBullet(int Damage, float speed, float ���ӹ߻������, int �߻�Ƚ��, float �߻�Ƚ������õ�����, D3DXVECTOR3 *Mother, int �Ѿ˼Ҹ� = 0)
	{
		Attack_Damage = Damage;
		bltSpeed = speed;
		BltDelay = ���ӹ߻������;
		bltMother = Mother;
		this->�ִ�߻�Ƚ�� = �߻�Ƚ��;
		this->�߻�Ƚ������õ����� = �߻�Ƚ������õ�����;
		this->�Ѿ˼Ҹ� = �Ѿ˼Ҹ�;
	}
	bool LunchBullet(D3DXVECTOR3 Position, int angle, const char *img, bool selfActiveTimer = false)
	{
		if (�ִ�߻�Ƚ�� <= 0 || �߻�Ƚ�� < �ִ�߻�Ƚ��)
		{
			if (Bullettimer.pass(BltDelay) || selfActiveTimer)
			{

				t_bullet = new T;

				t_bullet->retainCount = 1;
				t_bullet->Initalize(img);
				t_bullet->Attack_Damage = Attack_Damage;
				t_bullet->Position.x = Position.x - t_bullet->Img.Source.right / 2;
				t_bullet->Position.y = Position.y - t_bullet->Img.Source.bottom / 2;
				t_bullet->�����ӵ� = bltSpeed;
				t_bullet->SetAngle(angle);
				t_bullet->Mother = bltMother;
				t_bullet->Visible = true;

				list.push_back(*t_bullet);
				�����߻�������Ÿ�̸�.start();
				t_bullet = NULL;

				if (selfActiveTimer == false)
				{
					Bullettimer.start();
					�߻�Ƚ��;
				}

				Sound->Play("Missile1", CHAN_PLAYER_BLT);
				return true;
			}
		}
		else if (�����߻�������Ÿ�̸�.pass(�߻�Ƚ������õ�����))
		{
			�߻�Ƚ�� = 0;
		}

		return false;

	}

	void MoveBullet()
	{
		for (std::list<T>::iterator itr = list.begin(); itr != list.end();)
		{
			
			itr->SetAngle(itr->Angle);
			itr->Process();

			if (itr->Visible == false)
			{
				itr->Release();
				list.erase(itr++);
			}
			else
			{
				itr++;
			}
		}
	}
	void DrawBullet()
	{
		for (std::list<T>::iterator itr = list.begin(); itr != list.end(); itr++)
		{
			itr->Render();
		}
	}
	void ClearList()
	{
		/*
		for (std::list<T>::iterator itr = list.begin(); itr != list.end(); itr++)
		{
		itr->Release();
		itr = list.erase(itr);
		}
		*/
		list.clear();
	}
};