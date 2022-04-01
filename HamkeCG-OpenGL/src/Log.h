#include "spdlog/spdlog.h"
#include <memory>
namespace HamkeCG {
	class Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

	};
}
#ifdef __DEBUG__
// Core log macros
#define CG_CORE_WARN(...)        ::HamkeCG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CG_CORE_INFO(...)        ::HamkeCG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CG_CORE_FATAL(...)       ::HamkeCG::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define CG_CORE_TRACE(...)       ::HamkeCG::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CG_CORE_ERROR(...)       ::HamkeCG::Log::GetCoreLogger()->error(__VA_ARGS__)
#else
#define CG_CORE_WARN(...) 
#define CG_CORE_INFO(...) 
#define CG_CORE_FATAL(...)
#define CG_CORE_TRACE(...)
#define CG_CORE_ERROR(...)
#endif
