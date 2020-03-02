#pragma once
#include "Scene.h"

class StageScene :
	public Scene
{
	sf::Time mSpawnInterval;
	sf::Clock mSpawnTimer;
	sf::Font mFont;
	sf::Text mUICoronaDie;
	int mCoronaDie;

	
public:
	StageScene(sf::RenderWindow& window);
	virtual ~StageScene();
	
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

