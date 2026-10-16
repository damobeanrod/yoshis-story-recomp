// Declarations for functions N64Recomp leaves out (its built-in ignored /
// reimplemented lists) that the generated code still calls. N64Recomp does
// not emit prototypes for them in funcs.h, and GCC 14 rejects implicit
// declarations, so this header is force-included into every recomp_funcs/*.c
// via CMake (-include) rather than hand-edited into generated files.
//
// Implementations live in librecomp, or in src/main.cpp for the ones
// librecomp does not provide.
#ifndef YOSHI_IGNORED_FUNCS_H
#define YOSHI_IGNORED_FUNCS_H

#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx);
void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx);
void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx);
void osPfsNumFiles_recomp(uint8_t* rdram, recomp_context* ctx);
void osDpGetCounters_recomp(uint8_t* rdram, recomp_context* ctx);
void osDpSetStatus_recomp(uint8_t* rdram, recomp_context* ctx);
void __d_to_ull_recomp(uint8_t* rdram, recomp_context* ctx);

// Native helpers called from [[patches.hook]] entries in config.toml
// (implemented in src/main.cpp).
void yoshi_sync_printf(uint8_t* rdram, recomp_context* ctx);
void yoshi_report_hungup(uint8_t* rdram, recomp_context* ctx);
void yoshi_overlay_load(uint8_t* rdram, recomp_context* ctx);
void yoshi_ai_set_next_buffer(uint8_t* rdram, recomp_context* ctx);

#ifdef __cplusplus
}
#endif

#endif
