#include "scene.h"

#include "../define.h"
#include "../include.h"

using namespace t::misc::interface;

Scene::Scene(int in_id):
/*m_isDone(false), */m_id(in_id) {
	for (int i = 0; i < t::subsystem::MAX; i++)
		m_ques[i] = NULL;
}

Scene::~Scene() {
	delete m_ques;
}
void Scene::setQue(t::subsystem::Name i_sub, t::misc::MSGQUE* i_pQue) {
	m_ques[i_sub] = i_pQue;
}

t::misc::Message& Scene::getNextMessage(t::subsystem::Name i_sub) {
	if (m_ques[i_sub])
		for (unsigned int i = 0; i < m_ques[i_sub]->size(); i++)
			if (m_ques[i_sub]->at(i).isNull())
				return m_ques[i_sub]->at(i);

	m_ques[i_sub]->push_back(t::misc::Message());
	return getNextMessage(i_sub);
}
