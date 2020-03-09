#include "CoronaVirus.h"
#include <random>
#include <time.h>

CoronaVirus::CoronaVirus() : GameObject(R"(..\Assets\Sprite\corona.png)")
{
	std::default_random_engine seed(clock());
	std::uniform_int_distribution<int> genX(0, 780);
	
	mSprite.setScale(0.2, 0.2); // 스프라이트의 스케일을 0.2배 함.
	mSprite.setOrigin(mSprite.getTextureRect().width / 2.0f, mSprite.getTextureRect().height / 2.0f); // 스프라이트의 원점을 중심으로 맞춤.
	mSprite.setPosition(genX(seed), 100); // 윈도우 가운데로 맞춤.

	SetTag(2);
}

CoronaVirus::~CoronaVirus()
{
}

void CoronaVirus::Update()
{
	mSprite.move(0, 2);

	if (mSprite.getPosition().y > 600) Destroy();
}

void CoronaVirus::Render(sf::RenderWindow& window)
{
	GameObject::Render(window);
#ifdef _DEBUG
	RenderBoundingBox(window);
#endif
}

void CoronaVirus::OnCollide(GameObject* other)
{
	if (other->GetTag() == 3)
		Destroy();
}
