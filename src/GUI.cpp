#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <Geode/modify/CCEGLView.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <cocos2d.h>

#include "Keys.h"
#include "GUI.h"
#include "MirrorToggle.h"


bool isVisible = false;

using namespace geode::prelude;


void gui()
{
    if(isVisible)
    {

        ImGui::Begin("No Mirror Portals", &isVisible);

        if (ImGui::Checkbox("No Mirror", &Mirror::no));
        
        if (ImGui::Checkbox("Instant Mirror", &Mirror::instant));


        ImGui::Text("Made by GDLsunq");
        ImGui::Text("Credits: Maxnut for some GUI Code");
        
        ImGui::End();
    }

        
}



// Credits to Maxnut for the UI opening Code
class $modify(CCKeyboardDispatcher)
{
    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool arr){
        
        if (!arr)
        {
            int UIKey = ImGuiKey_F2;

            if(down && (ConvertKeyEnum(key) == UIKey))
            {
                
                isVisible = !isVisible;
                return true;
            }

            if (!ImGuiCocos::get().isInitialized())
                return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);

            if (const auto imKey = ConvertKeyEnum(key); imKey != ImGuiKey_None)
                ImGui::GetIO().AddKeyEvent(imKey, down);
        }

        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);
    }
};

$on_mod(Loaded)
{
        ImGuiCocos::get().setup([]
        {
        ImGui::StyleColorsDark();
        })
        .draw([]
            {
                gui();
            });
}
