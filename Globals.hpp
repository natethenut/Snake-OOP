#pragma once

enum class Moves{Up, Down, Left, Right};
enum class PieceToDraw{Snake, Apple};

static bool quit = false;

static constexpr int width = 600;
static constexpr int height = 400;
static constexpr int size = 10;
static constexpr int game_width = width / size;
static constexpr int game_height = height / size;
