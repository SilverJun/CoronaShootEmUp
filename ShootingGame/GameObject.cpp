#include "GameObject.h"
#include <iostream>

std::unordered_map<std::string, sf::Texture*> GameObject::resMap;

GameObject::GameObject(std::string path) : mIsDestroy(false)
{
	if (resMap[path] == nullptr)
	{
		//std::cout << "Loading texture" << std::endl;
		resMap[path] = new sf::Texture();
		resMap[path]->loadFromFile(path);
	}
	
	//mTexture = *resMap[path]; // 이미지 읽기
	mSprite.setTexture(*resMap[path]);
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
