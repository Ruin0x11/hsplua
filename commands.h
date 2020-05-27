#ifndef __COMMANDS_H
#define __COMMANDS_H

namespace hsplua_cmd {
	void hl_newstate(); // 新規Luaステート
	void hl_switchstate(); // Luaステート切り替え
	void hl_close(); // Luaステート破棄
    void hl_error();
    void hl_openlibs();
}

#endif
