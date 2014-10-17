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

	TimeCounter 다음발사까지대기타이머;
	int 발사횟수;
	int 최대발사횟수;
	float 발사횟수만료시딜레이;
	int 총알소리;

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

	void SetBullet(int Damage, float speed, float 연속발사딜레이, int 발사횟수, float 발사횟수만료시딜레이, D3DXVECTOR3 *Mother, int 총알소리 = 0)
	{
		Attack_Damage = Damage;
		bltSpeed = speed;
		BltDelay = 연속발사딜레이;
		bltMother = Mother;
		this->최대발사횟수 = 발사횟수;
		this->발사횟수만료시딜레이 = 발사횟수만료시딜레이;
		this->총알소리 = 총알소리;
	}
	bool LunchBullet(D3DXVECTOR3 Position, int angle, const char *img, bool selfActiveTimer = false)
	{
		if (최대발사횟수 <= 0 || 발사횟수 < 최대발사횟수)
		{
			if (Bullettimer.pass(BltDelay) || selfActiveTimer)
			{

				t_bullet = new T;

				t_bullet->retainCount = 1;
				t_bullet->Initalize(img);
				t_bullet->Attack_Damage = Attack_Damage;
				t_bullet->Position.x = Position.x - t_bullet->Img.Source.right / 2;
				t_bullet->Position.y = Position.y - t_bullet->Img.Source.bottom / 2;
				t_bullet->단위속도 = bltSpeed;
				t_bullet->SetAngle(angle);
				t_bullet->Mother = bltMother;
				t_bullet->Visible = true;

				list.push_back(*t_bullet);
				다음발사까지대기타이머.start();
				t_bullet = NULL;

				if (selfActiveTimer == false)
				{
					Bullettimer.start();
					발사횟수;
				}

				Sound->Play("Missile1", CHAN_PLAYER_BLT);
				return true;
			}
		}
		else if (다음발사까지대기타이머.pass(발사횟수만료시딜레이))
		{
			발사횟수 = 0;
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