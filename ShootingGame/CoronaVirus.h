#pragma once
#include "GameObject.h"
class CoronaVirus :
	public GameObject
{
public:
	CoronaVirus();
	virtual ~CoronaVirus();

	void Update() override;
	void Render(sf::RenderWindow& window) override;
	void OnCollide(GameObject* other) override;
};

