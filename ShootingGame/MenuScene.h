#pragma once
#include "Scene.h"
class MenuScene :
	public Scene
{
	sf::Text mLogo;
	sf::Text mStart;
	sf::Text mExit;

	sf::Clock mSplashTime;
	sf::RectangleShape mSplash;
	bool mSplashEnd;
	
public:
	MenuScene(sf::RenderWindow& window);
	virtual ~MenuScene();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

