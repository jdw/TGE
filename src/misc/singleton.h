#ifndef __t__SINGLETON_H
#define __t__SINGLETON_H

//TODO: Move define.h too maketarget?
#include "define.h"

namespace t {
template <class T> class Singleton {
public:
	virtual ~Singleton();

	virtual int setup() = 0;
	virtual int teardown() = 0;
	virtual int update() = 0;

	static T* getInstance();
	//static T* getInstance() { if (m_pSingleton == NULL) m_pSingleton = new T(); return m_pSingleton; }

	//void Create() { if (pSingleton != NULL) return; pSingleton = new T(); }
	//void Destroy() { if (pSingleton == NULL) return; delete pSingleton; pSingleton = NULL; }

	static T* m_pSingleton;
	protected:
		//Singleton();

	private:
};

}

//template <typename T> T* t::Singleton<T>::m_pSingleton = NULL;
//T t::Singleton<T>::m_pSingleton = NULL;

#endif // __t__SINGLETON_H
