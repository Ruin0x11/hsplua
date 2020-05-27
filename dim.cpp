#include "dim.h"
#include "hsplua.h"
#include "chkstat.h"
#include "hsp/hsp3plugin.h"

void hsplua_cmd::hl_pushdim() {
    PVal **p = (PVal **)lua_newuserdata(currState(), sizeof(PVal *));
    *p = exinfo->HspFunc_prm_getpval();
    luaL_getmetatable(currState(), "hsplua.dim");
    lua_setmetatable(currState(), -2);
}

static PVal *hl_dim_check(lua_State *L) {
    PVal **ud = (PVal **)luaL_checkudata(L, 1, "hsplua.dim");
    luaL_argcheck(L, ud != NULL, 1, "`dim' expected");
    return *ud;
}

static int hl_dim_len(lua_State* L) {
    PVal *ud = hl_dim_check(L);
    lua_pushnumber(L, ud->len[1]);
    lua_pushnumber(L, ud->len[2]);
    lua_pushnumber(L, ud->len[3]);
    lua_pushnumber(L, ud->len[4]);
    return 4;
}

static int hl_dim_index(lua_State* L) {
    PVal *ud = hl_dim_check(L);
    int index = luaL_checkint(L, 2);
    luaL_argcheck(L, 0 <= index && index <= ud->len[1], 2, "index out of range");
    switch (ud->flag) {
        case HSPVAR_FLAG_STR:
            lua_pushlstring(L, ud->pt, ud->len[0]);
            break;
        case HSPVAR_FLAG_INT:
            lua_pushinteger(L, *(int*)ud->pt);
            break;
        case HSPVAR_FLAG_DOUBLE:
            lua_pushnumber(L, *(double*)ud->pt);
            break;
        default:
            lua_pushnil(L);
            break;
    }
    return 1;
}

static int hl_dim_newindex(lua_State* L) {
    int var_i;
    double var_d;
    PVal *ud = hl_dim_check(L);
    int index = luaL_checkint(L, 2);
    luaL_argcheck(L, 0 <= index && index <= ud->len[1], 2, "index out of range");
    switch (ud->flag) {
    case HSPVAR_FLAG_STR:
        break;
    case HSPVAR_FLAG_INT:
        var_i = luaL_checkint(L, 3);
        *(int*)ud->pt = var_i;
        break;
    case HSPVAR_FLAG_DOUBLE:
        var_d = luaL_checknumber(L, 3);
        *(double*)ud->pt = var_d;
        break;
    default:
        break;
    }
    return 0;
}

static int hl_dim_gc(lua_State* L) {
    return 0;
}

static luaL_Reg meta[] = {
    { "__len", hl_dim_len },
    { "__index", hl_dim_index },
    { "__newindex", hl_dim_newindex },
    { "__gc", hl_dim_gc },
    { NULL, NULL }
};

void hsplua_cmd::hl_openlibs_dim() {
    luaL_newmetatable(currState(), "hsplua.dim");
    luaL_setfuncs(currState(), meta, 0);
    lua_pop(currState(), 1);
}