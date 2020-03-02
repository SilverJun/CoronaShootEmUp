#include "Bullet.h"



Bullet::Bullet(sf::Vector2f position) : GameObject(R"(..\Assets\Sprite\bullet.png)")
{
	mSprite.setScale(0.5, 0.5); // 스프라이트의 스케일을 0.2배 함.
	mSprite.setOrigin(mSprite.getTextureRect().width / 2.0f, mSprite.getTextureRect().height / 2.0f); // 스프라이트의 원점을 중심으로 맞춤.
	mSprite.setPosition(position); // 플레이어의 위치에 오도록 입력받은 position으로 위치를 설정

	SetTag(3);
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	mSprite.move(0, -5);

	if (mSprite.getPosition().y < 0) Destroy();
}

void Bullet::Render(sf::RenderWindow& window)
{
	GameObject::Render(window);
	RenderBoundingBox(window);
}

void Bullet::OnCollide(GameObject* other)
{
	if (other->GetTag() == 2)
		Destroy();
}
