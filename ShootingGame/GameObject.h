#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mTag;
	bool mIsDestroy;
	
public:
	GameObject(std::string path);
	virtual ~GameObject();

	virtual void Init();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	virtual void Release();

	virtual void OnCollide(GameObject* other) {}

	bool IsDestroy() const { return mIsDestroy; }
	void Destroy() { mIsDestroy = true; }
	void SetTag(int tag) { mTag = tag; }
	int GetTag() const { return mTag; }
	auto GetBoundingBox() { return mSprite.getGlobalBounds(); }
	void RenderBoundingBox(sf::RenderWindow& window);
};

