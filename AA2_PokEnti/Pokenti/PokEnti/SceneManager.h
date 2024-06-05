#pragma once

enum class Scenes
{
    MENU,
    MAP,
    COMBAT,
    COUNT
};

struct SceneManager
{
    Scenes currentScene;
};