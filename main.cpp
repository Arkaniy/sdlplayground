#include <iostream>
#include <string>

#include "gfxengine/gfxengine.h"
#include "gfxengine/resourcepreloadholder.h"

#include "core/container.h"

#include "core/components/sprite.h"
#include "core/components/transform.h"

int main() {
    auto& gfxEngine = GfxEngine::getInstance();
    gfxEngine.init();

    ResourcePreloadHolder resourcePreloadHolder;
    resourcePreloadHolder.addImage("img.jpg", "bg");

    Container container;

    Sprite sprite(container, "bg");
    Transform transform(container, 0, 0, 720, 480);

    gfxEngine.loadResources(resourcePreloadHolder);

    gfxEngine.startFrame();
    gfxEngine.drawSprite(&sprite, &transform);
    gfxEngine.endFrame();


    std::cin.get();

    gfxEngine.free();
}
