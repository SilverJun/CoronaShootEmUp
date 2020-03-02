#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player :
	public GameObject
{
	sf::Clock mShootClock;
	float mShootInterval;
public:
	Player();
	virtual ~Player();

	void Init() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;

	void OnCollide(GameObject* other) override;
};

