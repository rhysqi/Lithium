#ifndef LT_SYSTEM_HH
#define LT_SYSTEM_HH

namespace Lt_System {

	void Buffer();
	void File();

	namespace Encoding {
		int Name(const char *NAME);
	}
	
	namespace Security {
		void Check();
		int Limiter();
		int Validation();
	}
}

#endif /* LT_SYSTEM_HH */