#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: Z:\ProgSandbot\DE0-nano\DE0_Nano.sof to: "..\flash/DE0_Nano_epcs_flash_controller_0.flash"
#
sof2flash --input="Z:/ProgSandbot/DE0-nano/DE0_Nano.sof" --output="../flash/DE0_Nano_epcs_flash_controller_0.flash" --epcs 

#
# Programming File: "..\flash/DE0_Nano_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/DE0_Nano_epcs_flash_controller_0.flash" --base=0x0 --epcs --sidp=0x800 --id=0x0 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program 

#
# Converting ELF File: Z:\ProgSandbot\DE0-nano\software\FinalVersion\FinalVersion.elf to: "..\flash/FinalVersion_epcs_flash_controller_0.flash"
#
elf2flash --input="Z:/ProgSandbot/DE0-nano/software/FinalVersion/FinalVersion.elf" --output="../flash/FinalVersion_epcs_flash_controller_0.flash" --epcs --after="../flash/DE0_Nano_epcs_flash_controller_0.flash" 

#
# Programming File: "..\flash/FinalVersion_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/FinalVersion_epcs_flash_controller_0.flash" --base=0x0 --epcs --sidp=0x800 --id=0x0 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program 

