#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <sstream>
#include <string>
#include <SDL_video.h>

//LOGGING MACROS
/*
Logs a message to the console as well as an output file.
Works in any build.
*/
#define DEBUG_LOG Debug::Log()

/*
Logs a message to the console as well as an output file.
Only works with debug builds.
*/
#define DEBUG_LOG_DEBUGONLY Debug::Log(Debug::LogEnum::DebugOnly)

/*
Logs a message to the console as well as an output file.
Only works in release builds.
*/
#define DEBUG_LOG_RELEASEONLY Debug::Log(Debug::LogEnum::ReleaseOnly)	

namespace Debug
{
	enum class LogEnum
	{
		NoRestrictions,				//Log the data with no restrictions
		DebugOnly,					//If program is not a debug build, dont output anything.
		ReleaseOnly					//If program is not a release build, dont output anything.
	};

	struct Log
	{
		Log();
		Log(LogEnum mode);

		~Log();

		template <typename T>
		Log& operator<<(T const& value)
		{
			oss << value;
			return *this;
		}

	private:
		std::ostringstream oss;
		bool canLog = true;
	};

	struct Error
	{
		/*
		Output an error message through an SDL2 message box.
		*/
		static void ShowSDLMessageBox(const char* errorMessage);
	};
}

#endif