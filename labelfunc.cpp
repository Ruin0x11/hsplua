#include "labelfunc.h"
#include <stdexcept>
#include "chkstat.h"
#include "hsplua.h"
#include "hsp/hsp3plugin.h"

int labelFunc(lua_State* l) {
	unsigned short* const label = (unsigned short*)lua_tointeger(l, lua_upvalueindex(1));
	code_call(label);
    if (ctx->retval_level == (ctx->sublev + 1)) {
        PVal* pvResult = *(exinfo->mpval);
        switch (pvResult->flag) {
            case HSPVAR_FLAG_STR:
                lua_pushlstring(currState(), pvResult->pt, pvResult->len[0]);
                return 1;
            case HSPVAR_FLAG_INT:
                lua_pushinteger(currState(), *(int*)pvResult->pt);
                return 1;
            case HSPVAR_FLAG_DOUBLE:
                lua_pushnumber(currState(), *(double*)pvResult->pt);
                return 1;
            default:
                break;
        }
    }
	return 0;
}
