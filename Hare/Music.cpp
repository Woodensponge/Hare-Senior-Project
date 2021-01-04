#include "Music.h"

using namespace Audio;

Music::Music(const char* filePath)
	:filePath(filePath), isLooped(false)
{

}

Music::Music(const char* filePath, bool isLooped)
	:filePath(filePath), isLooped(isLooped)
{

}

Music::~Music()
{

}
