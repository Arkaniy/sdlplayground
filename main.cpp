#include <iostream>
#include <string>

#include "gfxengine/gfxengine.h"
#include "gfxengine/resourcepreloadholder.h"

#include "core/entity.h"
#include "core/scene.h"

#include "entities/picture.h"

int main() {
    auto& gfxEngine = GfxEngine::getInstance();
    gfxEngine.init();

    ResourcePreloadHolder resourcePreloadHolder;
    resourcePreloadHolder.addImage("img.jpg", "bg");
    resourcePreloadHolder.addImage("rb.png", "bg1");

    gfxEngine.loadResources(resourcePreloadHolder);

    Scene scene;


    Picture p1("bg", scene);
    p1.setTransform(100,100, 300, 300);
    scene.registerEntity(std::make_shared<Picture>(p1));

    Picture p("bg1", scene, &p1);
    p.setTransform(0,0, 200, 200);
    scene.registerEntity(std::make_shared<Picture>(p));

    scene.run();
}
