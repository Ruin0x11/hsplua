#ifndef __READVAL_H
#define __READVAL_H

namespace hsplua_func {
	int hl_toboolean();
	int hl_tocfunction();
	int hl_tointeger();
	int hl_tonumber();
	int hl_topointer();
	int hl_tostring();
    int hl_touserdata();
    int hl_gettop();
    int hl_pcall();
    int hl_dofile();
    int hl_dostring();
}

#endif
