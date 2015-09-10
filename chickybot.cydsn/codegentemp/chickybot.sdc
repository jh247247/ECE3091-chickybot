# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Nick\Dropbox\Uni Docs\y4s2\ECE3091 - Engineering Design\PSoc Creator\eng_design_2015\ECE3091-chickybot\chickybot.cydsn\chickybot.cyprj
# Date: Wed, 09 Sep 2015 01:51:48 GMT
#set_units -time ns
create_clock -name {ClockCamera(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {ClockLcdBacklight(routed)} -period 100000 -waveform {0 50000} [list [get_pins {ClockBlock/dclk_3}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {ClockCamera} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ClockCsBtns} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_clock -name {ClockCsBtns(fixed-function)} -period 83.333333333333329 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_1}]
create_generated_clock -name {ClockUsPWM} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {ClockLcdBacklight} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2401 4801} [list [get_pins {ClockBlock/dclk_glb_3}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Nick\Dropbox\Uni Docs\y4s2\ECE3091 - Engineering Design\PSoc Creator\eng_design_2015\ECE3091-chickybot\chickybot.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Nick\Dropbox\Uni Docs\y4s2\ECE3091 - Engineering Design\PSoc Creator\eng_design_2015\ECE3091-chickybot\chickybot.cydsn\chickybot.cyprj
# Date: Wed, 09 Sep 2015 01:51:39 GMT
