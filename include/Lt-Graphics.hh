#ifndef LT_GRAPHICS_HH
#define LT_GRAPHICS_HH

typedef struct Container_t{
	int x;
	int xx;
	int xxx;
} Lt_Container_t, *Lt_PContainer_t;

typedef const Lt_Container_t* Lt_PCContainer_t;

// void Container(Lt_Container_t Lt_PContainer_t);
void Window();
void SubWindow();

namespace Lt_Graphics {
	namespace Widget {
		void Button();
		void Menubar();
		void MenuItem();
	}
}

#endif /* LT_GRAPHICS_HH */