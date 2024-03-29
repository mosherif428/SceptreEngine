#pragma once

#include "Core.h"
#include "Log.h"
#include <filesystem>

#ifdef SC_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define SC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { SC##type##ERROR(msg, __VA_ARGS__); SC_DEBUGBREAK(); } }
#define SC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) SC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define SC_INTERNAL_ASSERT_NO_MSG(type, check) SC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", SC_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define SC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define SC_INTERNAL_ASSERT_GET_MACRO(...) SC_EXPAND_MACRO( SC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, SC_INTERNAL_ASSERT_WITH_MSG, SC_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define SC_ASSERT(...) SC_EXPAND_MACRO( SC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define SC_CORE_ASSERT(...) SC_EXPAND_MACRO( SC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define SC_ASSERT(...)
#define SC_CORE_ASSERT(...)
#endif