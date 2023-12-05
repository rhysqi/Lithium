/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Risky Akbar
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LT_CORE_HH
#define LT_CORE_HH

#include <stdio.h>
#include <stdlib.h>

// X11 section
#ifdef _X11
#include <X11/Xlib.h>

// Function core X11 declarations
void Lt_Core_X11(volatile int STATE, const char *Lt_N);
void Lt_Read_X11(const char *FILE, const char *F_RD);
void Lt_Write_X11(const char *FILE, const char *F_WR);
void Lt_LineCounter_X11();

void Lt_Backups_X11();
void Lt_HotKeys_X11();
void Lt_Setting_X11();

#endif /* _X11 */

// Win32 section
#ifdef _WIN32
#include <Windows.h>

// Function core win32 declarations
void Lt_Core_Win32();
void Lt_Read_Win32();
void Lt_Write_Win32();
void Lt_LineCounter_Win32();

void Lt_Backups_Win32();
void Lt_HotKeys_Win32();
void Lt_Setting_Win32();

#endif /* _WIN32 */

#endif /* LT_CORE_HH */