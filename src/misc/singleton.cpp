//TODO: Make singleton child-classes destruct properly

#include "singleton.h"
#include "define.h"
#include "include.h"

using namespace t;

template <class T> T* Singleton<T>::m_pSingleton = NULL;
/*
template <class T> Singleton::Singleton() {

}
*/

