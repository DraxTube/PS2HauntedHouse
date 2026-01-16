EE_BIN = HauntedHouse.elf
EE_OBJS = main.o script_lua.o
EE_LIBS = -lpups2lua -ldebug -lgraph -ldraw -lpacket -ldma -lgraph -lm

all: $(EE_BIN)

# Converte lo script lua in un file oggetto compilabile
script_lua.s: script.lua
	bin2s script.lua script_lua.s script_lua

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
