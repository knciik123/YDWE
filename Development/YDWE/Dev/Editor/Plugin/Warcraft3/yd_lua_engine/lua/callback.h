#pragma once

#include <ydwe/lua/state.h>
#include <lua.hpp>
#include <cstdint>

_BASE_BEGIN
namespace warcraft3 { namespace lua_engine {

	lua::state*& instance();	
	void         do_buffer(const char* name, const char* buffer, size_t size);

	struct callback
	{
	public:
		callback();
		callback(lua::state* ls, uint32_t index);
		callback(uint32_t ref);
		operator uint32_t();
		int      create(lua::state* ls, uint32_t index);
		bool     call_pre() const;
		uint32_t call(int nargs, bool result = true) const;

	private:
		uint32_t ref_;
	};


}}

_BASE_END
