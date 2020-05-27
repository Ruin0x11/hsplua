#include "readval.h"
#include "hsplua.h"
#include "chkstat.h"
#include "hsp/hsp3plugin.h"
#include <cstdlib>
#include <cstring>

int hsplua_func::hl_toboolean() {
	ref_val.ival = lua_toboolean(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_tocfunction() {
	ref_val.ival = (int)lua_tocfunction(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_tointeger() {
	ref_val.ival = lua_tointeger(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_tonumber() {
	ref_val.dval = lua_tonumber(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_DOUBLE;
}

int hsplua_func::hl_topointer() {
	ref_val.ival = (int)lua_topointer(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_tostring() {
	const char* const tmpstr = lua_tostring(currState(), exinfo->HspFunc_prm_geti());
	const size_t strsz = strlen(tmpstr);
	char* const tmp_sval = ref_sval; // reallocŽ¸”s‘Îô
    ref_sval=hspexpand(ref_sval, strsz + 1);
	if (ref_sval == NULL) { // realloc Ž¸”sŽž
		ref_sval = tmp_sval;
		throw HSPERR_OUT_OF_MEMORY;
	}
	strncpy(ref_sval, tmpstr, strsz + 1);
	ref_sval[strsz] = '\0'; // ˆÀ‘S‚Ì‚½‚ß
	ref_val.sval = ref_sval;
	return HSPVAR_FLAG_STR;
}

int hsplua_func::hl_touserdata() {
	ref_val.ival = (int)lua_touserdata(currState(), exinfo->HspFunc_prm_geti());
	return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_gettop() {
    ref_val.ival = lua_gettop(currState());
    return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_pcall() {
    int argcount = exinfo->HspFunc_prm_geti();
    int retcount = exinfo->HspFunc_prm_geti();
    int errorhandler = exinfo->HspFunc_prm_geti();
    ref_val.ival = lua_pcall(currState(), argcount, retcount, errorhandler);
    return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_dofile() {
    ref_val.ival = luaL_dofile(currState(), exinfo->HspFunc_prm_gets());
    return HSPVAR_FLAG_INT;
}

int hsplua_func::hl_dostring() {
    ref_val.ival = luaL_dostring(currState(), exinfo->HspFunc_prm_gets());
    return HSPVAR_FLAG_INT;
}