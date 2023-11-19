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

#include <X11/Xlib.h>

typedef struct D_Lt_Window{
    const char *title;
    short int id;
    unsigned int POSX;
    unsigned int POSY;
    unsigned int height;
    unsigned int width;
} D_Lt_Window;

typedef struct D_Lt_Menu{
    const char *text;
    int id;
} D_Lt_Menu;

typedef struct D_Lt_Button{
    int ID;
    const char *name;
    unsigned int height;
    unsigned int width;
} D_Lt_Button;

void Lt_Window(Display *Dsp, D_Lt_Window _D_);
void Lt_Window_Title(volatile char *title[]);
void Lt_WindowBG(volatile char *BG[]);
void Lt_WindowParent(int Lt_Win_ID);

void Lt_InputBox(int Lt_Input_ID, const char *text[]);
void Lt_InputBox_Multiline(int Lt_Input_ID, const char *text[]);

void Lt_Button(int Lt_Btn_ID, const char *text[]);
void Lt_ButtonParent(int Lt_Btn_ID);
void Lt_Check_Button(int Lt_Btn_ID);
void Lt_Radio_Button(int Lt_Btn_ID);

void Lt_Menu(int Lt_Menu_ID, const char *text[]);
void Lt_MenuOverlay(int Lt_Menu_ID, const char *text[]);
void Lt_MenuItem(int Lt_Menu_ID, const char *text[]);

#endif /* LT_COMPONENT_HH */
