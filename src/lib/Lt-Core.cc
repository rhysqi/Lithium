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

#include "../../include/Lt-Core.hh"
#include "../../include/Lt-Component.hh"

#ifdef _X11_

void Lt_Core_X11(volatile int STATE, const char *N){

    Lt_X11 XCore;
    Lt_Win XWin;

    XCore.Dsp = XOpenDisplay(NULL);

    int Scr = DefaultScreen(XCore.Dsp);
    int Root = RootWindow(XCore.Dsp, Scr);
    
    if (STATE == 3 && XCore.Dsp != NULL) {
        while (STATE != 1) {
            XNextEvent(XCore.Dsp, &XCore.Xe);
            
        }
    }else {
        printf("Cannot open display !\n");
        exit(1);
    }
    
    XCloseDisplay(XCore.Dsp);
}

void Lt_Read_X11(const char *FILE, const char *F_RD){
    if (F_RD != NULL) {
        fopen(F_RD, "r");
    }else {
        printf("No file to read !\n");
    }
}

void Lt_Write_X11(const char *FILE, const char *F_WR){
    
}

#endif /* _X11_ */


#ifdef _WIN32_
void Lt_Core_Win32(){

}
#endif /* _WIN32_ */