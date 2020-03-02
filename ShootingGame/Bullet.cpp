#include "Bullet.h"



Bullet::Bullet(sf::Vector2f position) : GameObject(R"(..\Assets\Sprite\bullet.png)")
{
	mSprite.setScale(0.5, 0.5); // ��������Ʈ�� �������� 0.2�� ��.
	mSprite.setOrigin(mSprite.getTextureRect().width / 2.0f, mSprite.getTextureRect().height / 2.0f); // ��������Ʈ�� ������ �߽����� ����.
	mSprite.setPosition(position); // �÷��̾��� ��ġ�� ������ �Է¹��� position���� ��ġ�� ����

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
