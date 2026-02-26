#pragma once
namespace dx3d
{
	class Logger
	{
	public:
		enum LogLevel
		{
			Error = 0,
			Warning,
			Info
		};
		explicit Logger(LogLevel logLevel);
		~Logger();
		void log(LogLevel level, const char* message);
	protected:
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator = (const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;
	private:
		Logger::LogLevel m_logLevel = Logger::LogLevel::Error;
	};

}
#define DX3D12Log(logger, type, message)\
logger.log(type, message)

#define DX3D12LogThrow(logger, exception, type, message)\
{\
DX3D12Log(logger,type,message);\
throw exception(message);\
}