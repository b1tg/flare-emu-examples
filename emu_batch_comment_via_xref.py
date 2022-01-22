import flare_emu
import hexdump
eh = flare_emu.EmuHelper()

for addr in XrefsTo(0x140001070, 0):
    addr_call = addr.frm
    addr_before = prev_head(addr_call) # 前一个指令
    addr_after = next_head(addr_call) # 后一个指令
    # 校验前一个指令是在传参，符合 lea rcx, unk_xxx
    if print_insn_mnem(addr_before) == "lea" and print_operand(addr_before, 0) == "rcx":
        #print("0x{:x} => 0x{:x}".format(addr_before, addr_call))
        eh.emulateRange(addr_before, endAddr=addr_after, skipCalls=False)
        ret = eh.getRegVal( "rax" )
        print( "decrypted at 0x%x: %s" %( addr_call ,eh.getEmuString(ret) ))
        # 设置注释
        set_cmt(addr_call, "decrypted: " + eh.getEmuString(ret).decode(), 0)
    
 