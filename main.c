#include <tamtypes.h>
#include <debug.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// Questo punta al tuo script Lua convertito in array di byte
extern unsigned char script_lua[];
extern unsigned int script_lua_size;

int main(int argc, char *argv[]) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    // Esegue il codice Lua integrato
    luaL_loadbuffer(L, (const char*)script_lua, script_lua_size, "script.lua");
    lua_pcall(L, 0, 0, 0);
    
    lua_close(L);
    return 0;
}
