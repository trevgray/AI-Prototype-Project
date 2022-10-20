#pragma once

#include "MMath.h"

class Tile;

class Node {
private:
	int label;
	MATH::Vec3 position;
	Tile* tile;
public:
	Node(int label_, MATH::Vec3 position_ = MATH::Vec3()) { 
		label = label_; 
		position = position_;
		tile = nullptr;
	}
	~Node() {}
	int GetLabel() { return label; }
	MATH::Vec3 GetPos() { return position; }

	void SetTile(Tile* tile_) { tile = tile_; }
	Tile* GetTile() { return tile; }
};