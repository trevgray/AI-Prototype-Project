#include "Tile.h"

void Tile::Render() {
	SDL_Renderer* renderer = scene->game->getRenderer();

	SDL_Rect rect;

	Vec3 topLeftScreenCoords;
	Vec3 bottomRightScreenCoords;

	Vec3 topLeftWorld;
	Vec3 bottomRightWorld;

	//node position is at the center of the tile
	Vec3 pos = node->GetPos();
	topLeftWorld = Vec3(pos.x - 0.5 * width, pos.y + 0.5 * height, 0.0f);
	bottomRightWorld = Vec3(pos.x + 0.5 * width, pos.y - 0.5 * height, 0.0f);

	topLeftScreenCoords = scene->getProjectionMatrix() * topLeftWorld;
	bottomRightScreenCoords = scene->getProjectionMatrix() * bottomRightWorld;

	rect.x = static_cast<int>(topLeftScreenCoords.x);
	rect.y = static_cast<int>(topLeftScreenCoords.y);
	rect.w = static_cast<int>(bottomRightScreenCoords.x - topLeftScreenCoords.x);
	rect.h = static_cast<int>(bottomRightScreenCoords.y - topLeftScreenCoords.y);

	//draw the tile
	SetRGBA(128, 127, 128, 255);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);

	//draw the border around the tile
	SetRGBA(255, 255, 255, 255);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawRect(renderer, &rect);
}