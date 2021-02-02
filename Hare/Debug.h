#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <sstream>
#include <string>

//LOGGING MACROS
#define DEBUG_LOG Debug::Log()
#define DEBUG_LOG_DEBUGONLY Debug::Log(Debug::LogEnum::DebugOnly)
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
			_buffer << value;
			return *this;
		}
	private:
		std::ostringstream _buffer;
		bool canLog = true;
	};
}

#endif