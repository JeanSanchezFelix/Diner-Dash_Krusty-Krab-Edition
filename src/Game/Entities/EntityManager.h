#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	int getPL(){return players_left;}
private: 
	int players_left = 0;

};