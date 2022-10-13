#define LUA_LIB

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "xtea.h"

static int lxtea_encipher(lua_State* L) {
    double r = luaL_checknumber(L, 1);
    luaL_checktype(L, 2, LUA_TTABLE);
    luaL_checktype(L, 3, LUA_TTABLE);

    lua_pushnumber(L, 1);
    lua_gettable(L, 2);
    lua_Integer v1 = lua_tointeger(L, -1);
    lua_pushnumber(L, 2);
    lua_gettable(L, 2);
    lua_Integer v2 = lua_tointeger(L, -1);
    uint32_t v[2]= {v1, v2};

    lua_pushnumber(L, 1);
    lua_gettable(L, 3);
    lua_Integer k1 = lua_tointeger(L, -1);
    lua_pushnumber(L, 2);
    lua_gettable(L, 3);
    lua_Integer k2 = lua_tointeger(L, -1);
    lua_pushnumber(L, 3);
    lua_gettable(L, 3);
    lua_Integer k3 = lua_tointeger(L, -1);
    lua_pushnumber(L, 4);
    lua_gettable(L, 3);
    lua_Integer k4 = lua_tointeger(L, -1);

    uint32_t k[4]= {k1, k2, k3, k4};
    encipher(r, v, k);
    lua_pushnumber(L, v[0]);
    lua_pushnumber(L, v[1]);
    return 2;
}

static int lxtea_decipher(lua_State* L) {
    // unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]

    double r = luaL_checknumber(L, 1);
    luaL_checktype(L, 2, LUA_TTABLE);
    luaL_checktype(L, 3, LUA_TTABLE);

    lua_pushnumber(L, 1);
    lua_gettable(L, 2);
    lua_Integer v1 = lua_tointeger(L, -1);
    lua_pushnumber(L, 2);
    lua_gettable(L, 2);
    lua_Integer v2 = lua_tointeger(L, -1);
    uint32_t v[2]= {v1, v2};

    lua_pushnumber(L, 1);
    lua_gettable(L, 3);
    lua_Integer k1 = lua_tointeger(L, -1);
    lua_pushnumber(L, 2);
    lua_gettable(L, 3);
    lua_Integer k2 = lua_tointeger(L, -1);
    lua_pushnumber(L, 3);
    lua_gettable(L, 3);
    lua_Integer k3 = lua_tointeger(L, -1);
    lua_pushnumber(L, 4);
    lua_gettable(L, 3);
    lua_Integer k4 = lua_tointeger(L, -1);

    uint32_t k[4]= {k1, k2, k3, k4};
    decipher(r, v, k);
    lua_pushnumber(L, v[0]);
    lua_pushnumber(L, v[1]);
    return 2;
}


LUAMOD_API int luaopen_xtea(lua_State *L) {
  luaL_checkversion(L);
    luaL_Reg fns [] = {
        {"encipher", lxtea_encipher},
        {"decipher", lxtea_decipher},
        {NULL, NULL}
    };
    luaL_newlib(L,fns);
    return 1;
}