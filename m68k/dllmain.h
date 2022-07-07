#ifndef __dllmain___
#define __dllmain___

#ifdef __cplusplus
extern "C" {
#endif
unsigned int cpu_read_byte(int addr);
unsigned int cpu_read_word(int addr);
unsigned int cpu_read_long(int addr);

void cpu_write_byte(int addr, int value);
void cpu_write_word(int addr, int value);
void cpu_write_long(int addr, int value);

#ifdef __cplusplus
}
#endif

#endif