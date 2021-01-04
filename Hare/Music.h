#ifndef MUSIC_H_
#define MUSIC_H_

#include <string>
#include <SDL.h>

namespace Audio
{
	struct Music
	{
		Music(const char* filePath, bool isLooped);
		~Music();

		bool isLooped;
		std::string filePath;
	};
}

#endif