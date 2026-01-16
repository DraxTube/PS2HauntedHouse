#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

extern unsigned char script_lua[];
extern unsigned int script_lua_size;

int main(int argc, char *argv[]) {
    SifInitRpc(0);
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Carica ed esegue lo script che ti ho dato prima
    if (luaL_loadbuffer(L, (const char*)script_lua, script_lua_size, "script.lua") || lua_pcall(L, 0, 0, 0)) {
        // Errore in caso di fallimento
        return 1;
    }

    lua_close(L);
    return 0;
}
