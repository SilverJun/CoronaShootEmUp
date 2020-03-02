#include "StageScene.h"
#include "Player.h"
#include "CoronaVirus.h"

StageScene::StageScene(sf::RenderWindow& window) : Scene(window), mSpawnInterval(sf::seconds(1.0)), mCoronaDie(0)
{
	mFont.loadFromFile(R"(..\Assets\Font\스플래2K.ttf)");
	
	mUICoronaDie.setFont(mFont);
	mUICoronaDie.setPosition(50, 50);
	mUICoronaDie.setFillColor(sf::Color::White);
	mUICoronaDie.setCharacterSize(30);
}


StageScene::~StageScene()
{
}

void StageScene::Init()
{
	SetBackground(R"(..\Assets\Sprite\background.jpg)");
	
	AddGameObject(new Player());
	AddGameObject(new CoronaVirus());
	
	for (int i = 0; i < mObjList.size(); ++i)
	{
		mObjList[i]->Init();
	}
	mSpawnTimer.restart();
}

void StageScene::Update()
{
	std::map<int, std::vector<GameObject*>> collisionMatrix;

	// 코로나 스폰하기.
	if (mSpawnTimer.getElapsedTime() > mSpawnInterval) // mSpawnInterval의 간격으로 소환.
	{
		if (mSpawnInterval >= sf::seconds(0.4)) // mSpawnInterval을 점점 줄여서 빠르게 소환되도록 함.
			mSpawnInterval -= sf::seconds(0.02);
		AddGameObject(new CoronaVirus());
		mSpawnTimer.restart(); // 타이머 재설정.
	}

	// 모든 게임오브젝트들 업데이트.
	for (int i = 0; i < mObjList.size(); ++i)
	{
		mObjList[i]->Update();
		// 콜리전 체크를 위한 맵에 넣기
		collisionMatrix[mObjList[i]->GetTag()].push_back(mObjList[i]);
	}

	// 충돌체크 하기.
	// 1은 player
	// 2는 corona
	// 3은 bullet

	// 플레이어와 코로나의 충돌비교.
	if (!collisionMatrix[1].empty())
	{
		for (int i = 0; i < collisionMatrix[2].size(); ++i)
		{
			if (CollisionCheck(collisionMatrix[1][0], collisionMatrix[2][i]))
			{
				collisionMatrix[1][0]->OnCollide(collisionMatrix[2][i]);
				collisionMatrix[2][i]->OnCollide(collisionMatrix[1][0]);
			}
		}
	}

	// 코로나와 총알간의 충돌비교.
	for (int i = 0; i < collisionMatrix[2].size(); ++i)
	{
		for (int j = 0; j < collisionMatrix[3].size(); ++j)
		{
			if (CollisionCheck(collisionMatrix[2][i], collisionMatrix[3][j]))
			{
				mCoronaDie++;
				collisionMatrix[2][i]->OnCollide(collisionMatrix[3][j]);
				collisionMatrix[3][j]->OnCollide(collisionMatrix[2][i]);
			}
		}
	}

	// UI 업데이트.
	mUICoronaDie.setString(std::wstring(L"맞춘 코로나 수: ") + std::to_wstring(mCoronaDie));
	
	// Destroy된 오브젝트 삭제.
	for (int i = 0; i < mObjList.size(); ++i)
	{
		if (mObjList[i]->IsDestroy())
		{
			mObjList[i]->Release();
			delete mObjList[i];
			mObjList[i] = nullptr;
		}
	}

	mObjList.erase(std::remove(mObjList.begin(), mObjList.end(), nullptr), mObjList.end());
}

void StageScene::Render()
{
	mWindow.draw(mBackground);
	
	for (int i = 0; i < mObjList.size(); ++i)
	{
		mObjList[i]->Render(mWindow);
	}
	
	mWindow.draw(mUICoronaDie);
}

void StageScene::Release()
{
	for (int i = 0; i < mObjList.size(); ++i)
	{
		mObjList[i]->Release();
	}
}
