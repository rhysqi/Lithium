#ifndef LT_COMPONENT_HH
#define LT_COMPONENT_HH

typedef struct{
    const char *title;
    short int id;
    unsigned int POSX;
    unsigned int POSY;
    unsigned int height;
    unsigned int width;
} D_Lt_Window;

typedef struct{
    const char *text;
    int id;
} D_Lt_Menu;

typedef struct{
    const char *name;
    unsigned int height;
    unsigned int width;
} D_Lt_Button;

void Lt_Window();
void Lt_WindowBG();
void Lt_WindowParent();

void Lt_InputBox();
void Lt_InputBox_Multiline();

void Lt_Button();
void Lt_ButtonParent();
void Lt_Check_Button();
void Lt_Radio_Button();

void Lt_Menu();
void Lt_MenuOverlay();
void Lt_MenuItem();

#endif /* LT_COMPONENT_HH */