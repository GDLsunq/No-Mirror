#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <imgui-cocos.hpp>

#include "MirrorToggle.h"

using namespace geode::prelude;

class $modify(GJBaseGameLayer){

    void toggleFlipped(bool p0, bool p1){
        if (Mirror::instant)
        {
            GJBaseGameLayer::toggleFlipped(p0, true);
            return;
        } 
        if (Mirror::no)
        {
            if (Mod::get()->getSettingValue<bool>("nomirror"))
            {
            return GJBaseGameLayer::toggleFlipped(p0, (p1) ? p1 : Mod::get()->getSettingValue<bool>("instantmirror"));
            }
        }
        else
        {
        GJBaseGameLayer::toggleFlipped(p0, p1);
        }
        }
};



