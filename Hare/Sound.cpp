#include "Sound.h"

using namespace Audio;

Sound::Sound(const char* filePath)
	:filePath(filePath), isLooped(false)
{

}

Sound::Sound(const char* filePath, bool isLooped) 
	:filePath(filePath), isLooped(isLooped)
{

}

Sound::~Sound()
{

}