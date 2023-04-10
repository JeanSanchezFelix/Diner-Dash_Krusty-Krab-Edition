#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"
#include "Plankton.h"
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
	int setPL(int num){return players_left = num;}
	bool getInspecStatus(){return inspectorLeft;}
	bool setInspecStatus(bool status){
		return inspectorLeft = status;
	}
private: 

	int players_left = 0;
	bool inspectorLeft = false;

};