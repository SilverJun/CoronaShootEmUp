#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Scene
{
	static Scene* mCurrentScene;
protected:
	sf::RenderWindow& mWindow;
	std::vector<GameObject*> mObjList;
	sf::Texture mBGTexture;
	sf::Sprite mBackground;
	static sf::Font mFont;
	
public:
	Scene(sf::RenderWindow& window);
	virtual ~Scene();

	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}

	void SetBackground(std::string path);
	void AddGameObject(GameObject* gameObject);
	bool CollisionCheck(GameObject* box1, GameObject* box2);

	static void SceneChange(Scene* newScene);
	static Scene** GetCurrentScene() { return &mCurrentScene; }
};

