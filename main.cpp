#include <iostream>
#include <string>

#include "gfxengine/gfxengine.h"
#include "gfxengine/resourcepreloadholder.h"

#include "core/container.h"
#include "core/scene.h"

#include "core/components/sprite.h"
#include "core/components/transform.h"

int main() {
    auto& gfxEngine = GfxEngine::getInstance();
    gfxEngine.init();

    ResourcePreloadHolder resourcePreloadHolder;
    resourcePreloadHolder.addImage("img.jpg", "bg");
    resourcePreloadHolder.addImage("rb.png", "bg1");

    Scene scene;

    Container container;

    Sprite sprite(container, "bg");
    Transform transform(container, 0, 0, 480, 320);

    Container container1;

    Sprite sprite1(container1, "bg1");
    Transform transform1(container1, 100, 100, 480, 320);

    container.addComponent(std::make_shared<Sprite>(sprite));
    container.addComponent(std::make_shared<Transform>(transform));

    container1.addComponent(std::make_shared<Sprite>(sprite1));
    container1.addComponent(std::make_shared<Transform>(transform1));

    gfxEngine.loadResources(resourcePreloadHolder);

    scene.registerEntity(std::make_shared<Container>(container));
    scene.registerEntity(std::make_shared<Container>(container1));

    scene.run();

    gfxEngine.free();
}
