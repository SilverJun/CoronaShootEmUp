#include "Scene.h"

Scene* Scene::mCurrentScene = nullptr;

Scene::Scene(sf::RenderWindow& window) : mWindow(window)
{
}

Scene::~Scene()
{
}

void Scene::SetBackground(std::string path)
{
	mBGTexture.loadFromFile(path);
	mBackground.setTexture(mBGTexture);
	auto winSize = mWindow.getSize();
	auto textureSize = mBGTexture.getSize();
	mBackground.setScale(sf::Vector2f((float)winSize.x / textureSize.x, (float)winSize.y / textureSize.y));
}

void Scene::AddGameObject(GameObject* gameObject)
{
	mObjList.push_back(gameObject);
	mObjList.back()->Init();
}

bool Scene::CollisionCheck(GameObject* box1, GameObject* box2)
{
	auto b1 = box1->GetBoundingBox();
	auto b2 = box2->GetBoundingBox();
	return b1.intersects(b2);
}

void Scene::SceneChange(Scene* newScene)
{
	if (mCurrentScene)
	{
		mCurrentScene->Release();
		delete mCurrentScene;
	}
	
	mCurrentScene = newScene;
	mCurrentScene->Init();
}
