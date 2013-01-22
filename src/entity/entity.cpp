#include "entity.h"

#include "../misc/include.h"
#include "../misc/define.h"
#include "../graphics/animation.h"

using namespace t::entity;

Entity::Entity(const unsigned int i_graphicsId, const unsigned int i_soundId, const unsigned int i_physicsId) {
	m_ids[type::GFX] = i_graphicsId;
	m_ids[type::SFX] = i_soundId;
	m_ids[type::PFX] = i_physicsId;
	m_posX = 0;
	m_posY = 0;
	m_isActive = false;
	m_isDead = false;
	m_isVisible = false;
}

Entity::Entity() {
	m_ids[type::GFX] = 0;
	m_ids[type::SFX] = 0;
	m_ids[type::PFX] = 0;
	m_posX = 0; //TODO: Fix vector
	m_posY = 0;
	m_isActive = false;
	m_isDead = false;
	m_isVisible = false;
}

Entity::~Entity() {
	//delete m_pAnimation;
}

int Entity::update(const unsigned int& i_time) { START
	updateGraphics(i_time);
	updatePhysics(i_time);
	updateSound(i_time);
STOP }

int Entity::updateGraphics(const float& i_time) { START

STOP }

int Entity::updatePhysics(const float& i_time) { START

STOP }

int Entity::updateSound(const float& i_time) { START

STOP }
