#pragma once
#include <unordered_map>
#include <SFML/Audio.hpp>

enum class eSound
{
	StageBG,
	MenuBG,
	Explosion,
	Fire,
};

class SoundManager
{
	std::unordered_map<eSound, sf::Music> mSoundTable;
	
	SoundManager();

public:
	~SoundManager();
	
	void Init();

	static SoundManager* GetInstance();

	void PlaySound(eSound sound);
	void StopSound(eSound sound);
};

