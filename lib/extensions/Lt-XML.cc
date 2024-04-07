#include "../../include/Lt-Extensions.hh"

#ifdef _WIN32

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <windows.data.xml.dom.h>

using namespace ABI::Windows::Data;

void Lt_XML_Parser(const char *_FILENAME){
	const Xml::Dom::XmlDocument *Docs;
}

#endif /* _WIN32 */