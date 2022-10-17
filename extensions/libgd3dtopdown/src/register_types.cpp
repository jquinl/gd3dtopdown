#include "register_types.hpp"

#include <godot/gdnative_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "GD3Dtopdown.hpp"
#include "GD3Dvisual_obstacle.hpp"
#include "GD3Dinterior_area.hpp"

using namespace godot;

void initialize_GD3Dtopdown_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
		return;
	}

    ClassDB::register_class<GD3Dtopdown>();
    ClassDB::register_class<GD3Dvisual_obstacle>();
    ClassDB::register_class<GD3Dinterior_area>();

}
void uninitialize_GD3Dtopdown_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) 
    {
        return;
    }
}

extern "C" {
GDNativeBool GDN_EXPORT GD3Dtopdown_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

    init_obj.register_initializer(initialize_GD3Dtopdown_module);
    init_obj.register_terminator(uninitialize_GD3Dtopdown_module);

    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}