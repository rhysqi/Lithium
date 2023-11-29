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

#ifndef LT_COMPONENT_HH
#define LT_COMPONENT_HH

#include <stdio.h>
#include <stdlib.h>

#ifdef _X11_
#include <X11/Xlib.h>
#include <X11/Xatom.h>

// Function component declarations
void Lt_Window_X11();
void Lt_Window_Title_X11();
void Lt_WindowBG_X11();
void Lt_WindowParent_X11();

void Lt_InputBox_X11();
void Lt_InputBox_Multiline_X11();

void Lt_Button_X11();
void Lt_ButtonParent_X11();
void Lt_Check_Button_X11();
void Lt_Radio_Button_X11();

void Lt_Menu_X11();
void Lt_MenuOverlay_X11();
void Lt_MenuItem_X11();
#endif /* _X11_ */


// Win32 section
#ifdef _WIN32_
#include <Windows.h>

// Function component declarations
void Lt_Window_Win32();
void Lt_Window_Title_Win32();
void Lt_WindowBG_Win32();
void Lt_WindowParent_Win32();

void Lt_InputBox_Win32();
void Lt_InputBox_Multiline_Win32();

void Lt_Button_Win32();
void Lt_ButtonParent_Win32();
void Lt_Check_Button_Win32();
void Lt_Radio_Button_Win32();

void Lt_Menu_Win32();
void Lt_MenuOverlay_Win32();
void Lt_MenuItem_Win32();

#endif /* _WIN32_ */

#endif /* LT_COMPONENT_HH */
