#ifndef __PUSHPOP_H
#define __PUSHPOP_H

namespace hsplua_cmd {
	void hl_pop();
	void hl_pushboolean();
	void hl_pushfunction();
	void hl_pushinteger();
	void hl_pushlightuserdata();
	void hl_pushlstring();
	void hl_pushnil();
	void hl_pushnumber();
	void hl_pushstring();
	void hl_pushvalue();
    void hl_pushvarptr();
    void hl_gettable();
    void hl_getmetatable();
    void hl_getglobal();
    void hl_getfield();
    void hl_settable();
    void hl_setmetatable();
    void hl_setglobal();
    void hl_setfield();
    void hl_pushglobaltable();
    void hl_newtable();
    void hl_newmetatable();
}

#endif
