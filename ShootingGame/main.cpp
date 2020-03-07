#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "CoronaVirus.h"
#include "Bullet.h"
#include "Scene.h"
#include "StageScene.h"
#include "SoundManager.h"

int main()
{
	// ������ â ����.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shooting Game");

	window.setFramerateLimit(60); // ������ ����Ʈ�� 60���� �����.
	window.setVerticalSyncEnabled(true); // ��������ȭ �ɼ��� �Ҵ�.

	//Player player;
	//CoronaVirus corona;
	SoundManager::GetInstance()->Init();
	Scene::SceneChange(new StageScene(window));
	Scene* currentScene = Scene::GetCurrentScene();
	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) // ���� �̺�Ʈ�� �޾ƿ� (�ѹ��� �ϳ���, while���� ���鼭.)
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//player.Update();
		currentScene->Update();
		
		// clear the window with black color
		window.clear(sf::Color::Black);

		// �÷��̾� �׸���.
		//player.Render(window);
		//corona.Render(window);

		currentScene->Render();
		
		// end the current frame
		window.display();
	}

	return 0;
}
