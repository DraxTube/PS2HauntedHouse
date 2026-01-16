EE_BIN = HauntedHouse.elf
EE_OBJS = main.o script_lua.o
# Aggiungiamo le librerie Lua e i percorsi necessari
EE_INCS += -I$(PS2SDK)/ports/include
EE_LDFLAGS += -L$(PS2SDK)/ports/lib
EE_LIBS = -llua -ldebug -lgraph -ldraw -lpacket -ldma -lm -lc

all: $(EE_BIN)

# Converte lo script lua in un file oggetto
script_lua.s: script.lua
	bin2s script.lua script_lua.s script_lua

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
