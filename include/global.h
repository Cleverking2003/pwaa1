#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <stddef.h>
#include "gba/gba.h"
#include "main.h"
#include "declarations.h"

#define PALETTE 0x05000000

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))
#define MAX_OAM_OBJ_COUNT 128

#define IO_REG_STRUCT_MEMBER(localBgStruct, field) \
    *((u32 *) localBgStruct + (offsetof(struct LCDIORegisters, field) / 4)) \

#define SPRITE_ATTR0(y, affineMode, objMode, mosaic, bpp, shape) \
	((y) + ((affineMode) << 8) + ((objMode) << 10) + ((mosaic) << 12) + ((bpp) << 13) + ((shape) << 14)) \

//#define SPRITE_ATTR1()
//TODO: make different macros for affine and non affine sprites, aka Pidgey is lazy
#define SPRITE_ATTR2(tileNum, priority, paletteNum) \
	((tileNum) + ((priority) << 10) + ((paletteNum) << 12)) \


#define KEY_NEW() ({ (*(u16 *)REG_ADDR_KEYINPUT) ^ KEYS_MASK; })

#define _Sin( a ) (gSineTable[(a)])
#define _Cos( a ) (gSineTable[(a)+64])


#endif//GUARD_GLOBAL_H