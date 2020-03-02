#include "StageScene.h"
#include "Player.h"
#include "CoronaVirus.h"

StageScene::StageScene(sf::RenderWindow& window) : Scene(window), mSpawnInterval(sf::seconds(1.0)), mCoronaDie(0)
{
	mFont.loadFromFile(R"(..\Assets\Font\���÷�2K.ttf)");
	
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

	// �ڷγ� �����ϱ�.
	if (mSpawnTimer.getElapsedTime() > mSpawnInterval) // mSpawnInterval�� �������� ��ȯ.
	{
		if (mSpawnInterval >= sf::seconds(0.4)) // mSpawnInterval�� ���� �ٿ��� ������ ��ȯ�ǵ��� ��.
			mSpawnInterval -= sf::seconds(0.02);
		AddGameObject(new CoronaVirus());
		mSpawnTimer.restart(); // Ÿ�̸� �缳��.
	}

	// ��� ���ӿ�����Ʈ�� ������Ʈ.
	for (int i = 0; i < mObjList.size(); ++i)
	{
		mObjList[i]->Update();
		// �ݸ��� üũ�� ���� �ʿ� �ֱ�
		collisionMatrix[mObjList[i]->GetTag()].push_back(mObjList[i]);
	}

	// �浹üũ �ϱ�.
	// 1�� player
	// 2�� corona
	// 3�� bullet

	// �÷��̾�� �ڷγ��� �浹��.
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

	// �ڷγ��� �Ѿ˰��� �浹��.
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

	// UI ������Ʈ.
	mUICoronaDie.setString(std::wstring(L"���� �ڷγ� ��: ") + std::to_wstring(mCoronaDie));
	
	// Destroy�� ������Ʈ ����.
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
