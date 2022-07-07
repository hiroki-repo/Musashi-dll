#ifndef __dllmain___
#define __dllmain___

#ifdef __cplusplus
extern "C" {
#endif
unsigned int cpu_read_byte(unsigned int addr);
unsigned int cpu_read_word(unsigned int addr);
unsigned int cpu_read_long(unsigned int addr);

void cpu_write_byte(unsigned int addr, unsigned int value);
void cpu_write_word(unsigned int addr, unsigned int value);
void cpu_write_long(unsigned int addr, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif