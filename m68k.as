#uselib "m68k.dll"
#func m68k_set_int_ack_callback "m68k_set_int_ack_callback" int
#func m68k_set_bkpt_ack_callback "m68k_set_bkpt_ack_callback" int
#func m68k_set_reset_instr_callback "m68k_set_reset_instr_callback" int
#func m68k_set_pc_changed_callback "m68k_set_pc_changed_callback" int
#func m68k_set_tas_instr_callback "m68k_set_tas_instr_callback" int
#func m68k_set_illg_instr_callback "m68k_set_illg_instr_callback" int
#func m68k_set_fc_callback "m68k_set_fc_callback" int
#func m68k_set_instr_hook_callback "m68k_set_instr_hook_callback" int

#func m68k_set_cpu_type "m68k_set_cpu_type" int
#func m68k_init "m68k_init"
#func m68k_pulse_reset "m68k_pulse_reset"
#cfunc m68k_execute "m68k_execute" int
#cfunc m68k_cycles_run "m68k_cycles_run"
#cfunc m68k_cycles_remaining "m68k_cycles_remaining"
#func m68k_modify_timeslice "m68k_modify_timeslice" int
#func m68k_end_timeslice "m68k_end_timeslice"
#func m68k_set_irq "m68k_set_irq" int
#func m68k_set_virq "m68k_set_virq" int,int
#cfunc m68k_get_virq "m68k_get_virq" int
#func m68k_pulse_halt "m68k_pulse_halt"
#func m68k_pulse_bus_error "m68k_pulse_bus_error"
#cfunc m68k_context_size "m68k_context_size"
#cfunc m68k_get_context "m68k_get_context" int
#func m68k_set_context "m68k_set_context" int
#func m68k_state_register "m68k_state_register" int,int
#cfunc m68k_get_reg "m68k_get_reg" int,int
#func m68k_set_reg "m68k_set_reg" int,int
#cfunc m68k_is_valid_instruction "m68k_is_valid_instruction" int,int
#cfunc m68k_disassemble "m68k_disassemble" int,int,int
#cfunc m68k_disassemble_raw "m68k_disassemble_raw" int,int,int,int,int
