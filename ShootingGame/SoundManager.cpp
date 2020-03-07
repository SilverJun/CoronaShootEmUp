#include "SoundManager.h"
#include <iostream>


SoundManager::SoundManager()
{
}

void SoundManager::Init()
{
	/*
	StageBG,
	MenuBG,
	Explosion,
	Fire,*/
	mSoundTable[eSound::StageBG].openFromFile(R"(..\Assets\Sound\Stage.ogg)");
	mSoundTable[eSound::StageBG].setLoop(true);
	mSoundTable[eSound::StageBG].setVolume(70);
	
	mSoundTable[eSound::MenuBG].openFromFile(R"(..\Assets\Sound\Menu.ogg)");
	mSoundTable[eSound::MenuBG].setLoop(true);
	mSoundTable[eSound::MenuBG].setVolume(50);
	
	mSoundTable[eSound::Explosion].openFromFile(R"(..\Assets\Sound\explosion.ogg)");
	mSoundTable[eSound::Explosion].setLoop(false);
	mSoundTable[eSound::Explosion].setVolume(100);
	
	mSoundTable[eSound::Fire].openFromFile(R"(..\Assets\Sound\attack.ogg)");
	mSoundTable[eSound::Fire].setLoop(false);
	mSoundTable[eSound::Fire].setVolume(80);
}


SoundManager::~SoundManager()
{
}

SoundManager* SoundManager::GetInstance()
{
	static SoundManager* instance = new SoundManager();
	return instance;
}

void SoundManager::PlaySound(eSound sound)
{
	mSoundTable[sound].setPlayingOffset(sf::seconds(0.0f));
	mSoundTable[sound].play();
}

void SoundManager::StopSound(eSound sound)
{
	mSoundTable[sound].stop();
}

