#include "MenuScene.h"
#include "StageScene.h"
#include "SoundManager.h"


MenuScene::MenuScene(sf::RenderWindow& window) : Scene(window), mSplash(sf::Vector2f(mWindow.getSize()))
{
	SetBackground(R"(..\Assets\Sprite\menu.png)");

	mSplash.setFillColor(sf::Color::White);
	mSplashTime.restart();
	mSplashEnd = false;
	
	mLogo.setFont(mFont);
	mLogo.setString("Corona! Shoot'em Up!");
	mLogo.setFillColor(sf::Color::White);
	mLogo.setOutlineThickness(8.0f);
	mLogo.setOutlineColor(sf::Color::Red);
	mLogo.setStyle(sf::Text::Bold | sf::Text::Italic);
	mLogo.setCharacterSize(60);
	mLogo.setPosition(50, 100);

	mStart.setFont(mFont);
	mStart.setString(L"시작하기");
	mStart.setFillColor(sf::Color::White);
	mStart.setOutlineThickness(1.0f);
	mStart.setOutlineColor(sf::Color::Green);
	mStart.setPosition(120, 300);
	
	mExit.setFont(mFont);
	mExit.setString(L"종료하기");
	mExit.setFillColor(sf::Color::White);
	mExit.setOutlineThickness(1.0f);
	mExit.setOutlineColor(sf::Color::Green);
	mExit.setPosition(140, 400);
}


MenuScene::~MenuScene()
{
}

void MenuScene::Init()
{
	SoundManager::GetInstance()->PlaySound(eSound::MenuBG);
}

auto _easeFunctions = [](float t, float b, float c, float d) -> float
{
	return c * t / d + b;
};

void MenuScene::Update()
{
	sf::Uint8 value = (sf::Uint8)_easeFunctions(mSplashTime.getElapsedTime().asSeconds(), 0, 255, 2);
	if (!mSplashEnd)
	{
		/// t : current time
		/// b : start value
		/// c : end value
		/// d : duration

		mSplash.setFillColor(sf::Color(value, value, value, 255));

		if (mSplashTime.getElapsedTime() >= sf::seconds(2))
		{
			mSplashEnd = true;
		}
	}
	if (mSplashTime.getElapsedTime() >= sf::seconds(2))
		mLogo.setScale((value / 255.0f) + 0.5, (value / 255.0f) + 0.5);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		auto pos = sf::Mouse::getPosition(mWindow);
		if (mStart.getGlobalBounds().contains(pos.x, pos.y))
		{
			SceneChange(new StageScene(mWindow));
			return;
		}
		if (mExit.getGlobalBounds().contains(pos.x, pos.y))
		{
			exit(0);
		}
	}
}

void MenuScene::Render()
{
	mWindow.draw(mBackground);
	
	mWindow.draw(mLogo);
	mWindow.draw(mStart);
	mWindow.draw(mExit);
	if (!mSplashEnd)
		mWindow.draw(mSplash);
}

void MenuScene::Release()
{
	SoundManager::GetInstance()->StopSound(eSound::MenuBG);
}
