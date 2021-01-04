#ifndef SOUND_H_
#define SOUND_H_

#include <string>
#include <SDL.h>

namespace Audio
{
	struct Sound
	{
		Sound(const char* filePath, bool isLooped);
		Sound(const char* filePath);
		~Sound();

		bool isLooped;
		std::string filePath;
	};
}

#endif