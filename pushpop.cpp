#include "pushpop.h"
#include "hsplua.h"
#include "chkstat.h"
#include "hsp/hsp3plugin.h"
#include "labelfunc.h"

void hsplua_cmd::hl_pop() {
	lua_pop(currState(), exinfo->HspFunc_prm_getdi(1));
	return;
}

void hsplua_cmd::hl_pushboolean() {
	lua_pushboolean(currState(), exinfo->HspFunc_prm_geti());
	return;
}

void hsplua_cmd::hl_pushfunction() {
	const unsigned short* label = exinfo->HspFunc_prm_getlb();
	lua_pushinteger(currState(), (int)label);
	lua_pushcclosure(currState(), labelFunc, 1);
	return;
}

void hsplua_cmd::hl_pushinteger() {
	lua_pushinteger(currState(), exinfo->HspFunc_prm_geti());
	return;
}

void hsplua_cmd::hl_pushlightuserdata() {
	lua_pushlightuserdata(currState(), (void*)exinfo->HspFunc_prm_geti());
	return;
}

void hsplua_cmd::hl_pushlstring() {
	const int result = code_getprm();
	if ((result != PARAM_OK) && (result != PARAM_SPLIT)) throw HSPERR_NO_DEFAULT;
	if (mpval->flag != TYPE_STRING) throw HSPERR_ILLEGAL_FUNCTION;
	lua_pushlstring(currState(), mpval->pt, exinfo->HspFunc_prm_getdi(mpval->len[0]));
	return;
}

void hsplua_cmd::hl_pushnil() {
	lua_pushnil(currState());
	return;
}

void hsplua_cmd::hl_pushnumber() {
	lua_pushnumber(currState(), exinfo->HspFunc_prm_getd());
	return;
}

void hsplua_cmd::hl_pushstring() {
	lua_pushstring(currState(), exinfo->HspFunc_prm_gets());
	return;
}

void hsplua_cmd::hl_pushvalue() {
	lua_pushvalue(currState(), exinfo->HspFunc_prm_geti());
	return;
}

void hsplua_cmd::hl_pushvarptr() {
	PVal* pval = exinfo->HspFunc_prm_getpval();
	lua_pushlightuserdata(currState(), pval->pt);
	return;
}

void hsplua_cmd::hl_gettable() {
    lua_gettable(currState(), exinfo->HspFunc_prm_geti());
    return;
}

void hsplua_cmd::hl_getmetatable() {
    lua_getmetatable(currState(), exinfo->HspFunc_prm_geti());
    return;
}

void hsplua_cmd::hl_getglobal() {
    lua_getglobal(currState(), exinfo->HspFunc_prm_gets());
    return;
}

void hsplua_cmd::hl_getfield() {
    int index = exinfo->HspFunc_prm_geti();
    const char* name = exinfo->HspFunc_prm_gets();
    lua_getfield(currState(), index, name);
    return;
}

void hsplua_cmd::hl_settable() {
    lua_settable(currState(), exinfo->HspFunc_prm_geti());
    return;
}

void hsplua_cmd::hl_setmetatable() {
    lua_setmetatable(currState(), exinfo->HspFunc_prm_geti());
    return;
}

void hsplua_cmd::hl_setglobal() {
    lua_setglobal(currState(), exinfo->HspFunc_prm_gets());
    return;
}

void hsplua_cmd::hl_setfield() {
    int index = exinfo->HspFunc_prm_geti();
    const char* name = exinfo->HspFunc_prm_gets();
    lua_setfield(currState(), index, name);
    return;
}

void hsplua_cmd::hl_pushglobaltable() {
    lua_pushglobaltable(currState());
    return;
}

void hsplua_cmd::hl_newmetatable() {
    luaL_newmetatable(currState(), exinfo->HspFunc_prm_gets());
    return;
}

void hsplua_cmd::hl_newtable() {
    lua_newtable(currState());
    return;
}