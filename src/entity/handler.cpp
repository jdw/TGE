#include "handler.h"

#include "../misc/define.h"
#include "../database/handler.h"
#include "../entity/entity.h"
#include "../graphics/handler.h"

using namespace t::entity;

static t::entity::Handler* g_pHandlerInstance = NULL;

Handler::Handler():
t::misc::interface::Handler() {
	m_pEntitys = new std::map<unsigned int, boost::shared_ptr<Entity > >();
}

Handler::~Handler() {
	delete m_pEntitys;
}

int Handler::update(const unsigned int& i_time) { START

STOP }

int Handler::setup() { START

STOP }

int Handler::teardown() { START

STOP }

int Handler::fetch(const unsigned int i_id, SPENTITY& i_spEntity) { START
	std::map<unsigned int, SPENTITY>::iterator it = m_pEntitys->find(i_id);

	if (m_pEntitys->end() == it) { // Entity not loaded
		load(i_id); // Load entity
		it = m_pEntitys->find(i_id);
	}

	i_spEntity = it->second;
STOP }

int Handler::load(const unsigned int in_id) { START
	unsigned int t_g = 0;
	unsigned int t_s = 0;
	unsigned int t_p = 0;

	t::graphics::Handler::instance()->fetch(in_id, t_g);
	//t::graphics::SPANIMATION t_spA;
	//t::database::Handler::getInstance()->readGraphics(in_id, t_spA);
	//t::DatabaseHandler::getInstance()->readSound(in_id, &t_s);
	//t::DatabaseHandler::getInstance()->readPhysics(in_id, &t_p);
	m_pEntitys->insert(std::pair<unsigned int, SPENTITY >(in_id, SPENTITY(new Entity(t_g, t_s, t_p))));
STOP }

Handler* Handler::instance() {
	if (NULL == g_pHandlerInstance)
		g_pHandlerInstance = new Handler();

	return g_pHandlerInstance;
}

