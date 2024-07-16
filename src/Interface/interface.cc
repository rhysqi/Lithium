#include "../../include/Lt-System.hh"

#include <malloc.h>

#include <Windows.h>
#include <Msi.h>

class Lt_Init
{
	public:
		virtual void Public_WinInit();

	protected: 
		virtual void Protected_WinInit();

	private:
		virtual void Private_WinInit();

};

class Lt_Win_Init
{
	public:
		
};

class Lt_Component
{
	public:
		
};