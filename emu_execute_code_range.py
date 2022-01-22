import flare_emu
import hexdump

eh = flare_emu.EmuHelper()
eh.emulateRange(0x140001124, endAddr=0x140001130, skipCalls=False)

ret = eh.getRegVal( "rax" )
print("==== rax ====")
hexdump.hexdump(eh.getEmuBytes(ret, 0x20 ))
print("=============")
print( "%s" %( eh.getEmuString(ret) ))