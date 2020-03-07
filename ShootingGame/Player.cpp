#include "Player.h"
#include <iostream>
#include <algorithm>
#include "Scene.h"
#include "SoundManager.h"

Player::Player() : GameObject(R"(..\Assets\Sprite\player.png)"), mShootInterval(0.2)
{
	mSprite.setScale(0.2, 0.2); // ��������Ʈ�� �������� 0.2�� ��.
	mSprite.setOrigin(mSprite.getTextureRect().width / 2.0f, mSprite.getTextureRect().height / 2.0f); // ��������Ʈ�� ������ �߽����� ����.
	mSprite.setPosition(400, 300); // ������ ����� ����.
	SetTag(1);
}

Player::~Player()
{
}

void Player::Init()
{
	mShootClock.restart();
}

void Player::Update()
{
	// Ű���� �Է� �޾Ƽ� �̵� �� ȸ�� ��Ű�� �ڵ�.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mSprite.move(-4, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSprite.move(4, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mSprite.move(0, -4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		mSprite.move(0, 4);
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		mSprite.rotate(-2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		mSprite.rotate(2);
	}*/

	// �Ѿ��� �߻��ϴ� �ڵ�.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && mShootClock.getElapsedTime() > sf::seconds(mShootInterval))
	{
		// �Ѿ� ����...
		//mBullets.push_back(Bullet(mSprite.getPosition()));
		mShootClock.restart();
		SoundManager::GetInstance()->PlaySound(eSound::Fire);
		Scene::GetCurrentScene()->AddGameObject(new Bullet(mSprite.getPosition()));
	}
}

void Player::Render(sf::RenderWindow & window)
{
	GameObject::Render(window);
	RenderBoundingBox(window);
}

void Player::OnCollide(GameObject* other)
{
	if (other->GetTag() == 2)
		Destroy();
}
