#ifndef LT_GRAPHICS_HH
#define LT_GRAPHICS_HH

typedef void ( *Lt_CALL (void));

typedef struct Lt_Container_t{
	unsigned int ID;
	unsigned int Height;
	unsigned int Width;
} Lt_Container_t, *Lt_PContainer_t;

typedef struct  Lt_Window_t{
	unsigned int ID;
	unsigned int Height;
	unsigned int Width;
	unsigned long int Background;
} Lt_Window_t, *Lt_PWindow_t;

typedef struct  Lt_Button_t{
	unsigned int ID;
	unsigned int Height;
	unsigned int Width;
	const char *Text;
	unsigned long int Color;
} Lt_Button_t, *Lt_PButton_t;

typedef struct  Lt_Menubar_t{
	unsigned int ID;
	unsigned int Height;
	unsigned int Width;
	unsigned long int Color;
} Lt_Menubar_t, *Lt_PMenubar_t;

typedef struct  Lt_Menuitem_t{
	unsigned int ID;
	const char *Text;
	unsigned long int Color;
} Lt_Menuitem_t, *Lt_PMenuitem_t;

typedef struct  Lt_Sidebar_t{
	unsigned int ID;
	
	unsigned long int Color;
} Lt_Sidebar_t, *Lt_PSidebar_t;

void Container(Lt_PContainer_t Container_t);
void Lt_Window(Lt_PWindow_t Window_t);

namespace Lt_Graphics {
	namespace Fonts {
		void Fonts(const char *_FILENAME);
		void Fonts_Load(Lt_CALL);
	}
	namespace Widget {
		void Button();
		void Canvas();
		void Menubar();
		void MenuItem();
		void Sidebar();
		void Sidebar_Item();
	}
}

#endif /* LT_GRAPHICS_HH */