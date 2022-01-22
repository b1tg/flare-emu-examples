import flare_emu
import hexdump
test_input = "https://b1tg.github.io"
eh = flare_emu.EmuHelper()
eh.emulateRange(0x00000140001070, skipCalls=False, registers={'arg1': test_input }) 
ret = eh.getRegVal( "rax" )
hexdump.hexdump(eh.getEmuBytes(ret, 0x20 ))