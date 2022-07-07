// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

#include "m68k.h"
#include "dllmain.h"

int (*m68kmemaccess)(int, int, int);

int swapendianess32(int tmp) { return (((tmp >> (8 * 3)) & 0xFF) << (8 * 0)) | (((tmp >> (8 * 2)) & 0xFF) << (8 * 1)) | (((tmp >> (8 * 1)) & 0xFF) << (8 * 2)) | (((tmp >> (8 * 0)) & 0xFF) << (8 * 3)); }
int swapendianess16(int tmp) { return (((tmp >> (8 * 1)) & 0xFF) << (8 * 0)) | (((tmp >> (8 * 0)) & 0xFF) << (8 * 1)); }


int databussize = 0;

    unsigned int cpu_read_byte(unsigned int addr) { if (databussize == 0) { return m68kmemaccess(addr, 0, 1); } else { return m68kmemaccess(addr, 0, 1 | (1 << 8)); } }
    unsigned int cpu_read_word(unsigned int addr) { if (databussize == 0) { return swapendianess16(m68kmemaccess(addr, 0, 1)); } else if (databussize == 1) { return swapendianess16((m68kmemaccess(addr, 0, 1 | (1 << 8)) << (8 * 0)) | (m68kmemaccess(addr + 1, 0, 1 | (1 << 8)) << (8 * 1))); } else if (databussize >= 2) { return swapendianess16(m68kmemaccess(addr, 0, 1 | (2 << 8))); } }
    unsigned int cpu_read_long(unsigned int addr) { if (databussize == 0) { return swapendianess32(m68kmemaccess(addr, 0, 1)); } else if (databussize == 1) { return swapendianess32((m68kmemaccess(addr, 0, 1 | (1 << 8)) << (8 * 0)) | (m68kmemaccess(addr + 1, 0, 1 | (1 << 8)) << (8 * 1)) | (m68kmemaccess(addr + 2, 0, 1 | (1 << 8)) << (8 * 2)) | (m68kmemaccess(addr + 3, 0, 1 | (1 << 8)) << (8 * 3))); } else if (databussize == 2) { return swapendianess32((m68kmemaccess(addr, 0, 1 | (2 << 8)) << (16 * 0)) | (m68kmemaccess(addr + 2, 0, 1 | (2 << 8)) << (16 * 1))); } else if (databussize >= 4) { return swapendianess32(m68kmemaccess(addr, 0, 1 | (4 << 8))); } }

    void cpu_write_byte(unsigned int addr, unsigned int value) { if (databussize == 0) { m68kmemaccess(addr, value, 0); } else { m68kmemaccess(addr, value, 0 | (1 << 8)); } }
    void cpu_write_word(unsigned int addr, unsigned int value) { if (databussize == 0) { m68kmemaccess(addr, swapendianess16(value), 0); } else if (databussize == 1) { m68kmemaccess(addr, ((value >> (8 * 1)) & 0xFF), 0 | (1 << 8)); m68kmemaccess(addr + 1, ((value >> (8 * 0)) & 0xFF), 0 | (1 << 8)); } else if (databussize >= 2) { m68kmemaccess(addr, swapendianess16(value), 0 | (2 << 8)); } }
    void cpu_write_long(unsigned int addr, unsigned int value) { if (databussize == 0) { m68kmemaccess(addr, swapendianess32(value), 0); } else if (databussize == 1) { m68kmemaccess(addr, ((value >> (8 * 3)) & 0xFF), 0 | (1 << 8)); m68kmemaccess(addr + 1, ((value >> (8 * 2)) & 0xFF), 0 | (1 << 8)); m68kmemaccess(addr + 2, ((value >> (8 * 1)) & 0xFF), 0 | (1 << 8)); m68kmemaccess(addr + 3, ((value >> (8 * 0)) & 0xFF), 0 | (1 << 8)); } else if (databussize == 2) { m68kmemaccess(addr, swapendianess16((value >> (16 * 1)) & 0xFFFF), 0 | (2 << 8)); m68kmemaccess(addr + 2, swapendianess16((value >> (16 * 0)) & 0xFFFF), 0 | (2 << 8)); } else if (databussize >= 4) { m68kmemaccess(addr, swapendianess32(value), 0 | (4 << 8)); } }

#ifdef __cplusplus
    extern "C" {
#endif
    __declspec(dllimport) void setmemaccess(int (*tmp)(int, int, int), int modetmp);
    void setmemaccess(int (*tmp)(int, int, int), int modetmp) { m68kmemaccess = tmp; databussize = modetmp; }
#ifdef __cplusplus
}
#endif

//#include "m68k.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

