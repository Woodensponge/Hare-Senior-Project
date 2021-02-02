#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <sstream>
#include <string>

//LOGGING MACROS
#define DEBUG_LOG(argument) Debug::Log() << argument	
#define DEBUG_LOG_DEBUGONLY(argument) Debug::Log(Debug::LogEnum::DebugOnly) << argument
#define DEBUG_LOG_RELEASEONLY(argument) Debug::Log(Debug::LogEnum::ReleaseOnly) << argument	

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