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
	// 윈도우 창 생성.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shooting Game");

	window.setFramerateLimit(60); // 프레임 레이트를 60으로 맞춘다.
	window.setVerticalSyncEnabled(true); // 수직동기화 옵션을 켠다.

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
		while (window.pollEvent(event)) // 쌓인 이벤트를 받아옴 (한번에 하나씩, while루프 돌면서.)
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//player.Update();
		currentScene->Update();
		
		// clear the window with black color
		window.clear(sf::Color::Black);

		// 플레이어 그리기.
		//player.Render(window);
		//corona.Render(window);

		currentScene->Render();
		
		// end the current frame
		window.display();
	}

	return 0;
}
