#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(sf::Vector2f position);
	virtual ~Bullet();

	void Update() override;
	void Render(sf::RenderWindow& window) override;

	void OnCollide(GameObject* other) override;
};

