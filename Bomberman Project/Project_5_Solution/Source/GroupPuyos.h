#include "p2Point.h"
#include "Module.h"
#include "Animation.h"
#include "Puyo.h"

class GroupPuyos {
public:
	GroupPuyos();
	
	~GroupPuyos();

	void UpdateGroup();

	Puyo Group[4];

	bool active = true;

	fPoint position;
};