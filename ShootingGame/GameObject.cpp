#include "GameObject.h"


GameObject::GameObject(std::string path) : mIsDestroy(false)
{
	mTexture.loadFromFile(path); // 이미지 읽기
	mSprite.setTexture(mTexture);
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::Render(sf::RenderWindow& window)
{
	window.draw(mSprite);
}

void GameObject::Release()
{
}

void GameObject::RenderBoundingBox(sf::RenderWindow& window)
{

	auto b1 = GetBoundingBox();
	sf::RectangleShape boundingBox(sf::Vector2f(b1.width, b1.height));
	boundingBox.setPosition(b1.left, b1.top);
	boundingBox.setOutlineColor(sf::Color::Green);
	boundingBox.setOutlineThickness(3.0f);
	boundingBox.setFillColor(sf::Color::Transparent);

	window.draw(boundingBox);
}
