#include "register_types.hpp"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "character_gd3d.hpp"
#include "visual_obstacle_gd3d.hpp"
#include "visual_detector_gd3d.hpp"
#include "interior_area_gd3d.hpp"
#include "interior_detector_gd3d.hpp"
#include "selectable_gd3d.hpp"
#include "tween_mesh_instance_gd3d.hpp"

using namespace godot;

void initialize_gd3d_topdown_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
		return;
	}

    ClassDB::register_class<CharacterGD3D>();
    ClassDB::register_class<VisualObstacleGD3D>();
    ClassDB::register_class<VisualDetectorGD3D>();
    ClassDB::register_class<InteriorAreaGD3D>();
    ClassDB::register_class<InteriorDetectorGD3D>();
    ClassDB::register_class<SelectableGD3D>();
    ClassDB::register_class<TweenMeshInstanceGD3D>();

}
void uninitialize_gd3d_topdown_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) 
    {
        return;
    }
}

extern "C" {
    GDExtensionBool GDE_EXPORT gd3d_topdown_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

        init_obj.register_initializer(initialize_gd3d_topdown_module);
        init_obj.register_terminator(uninitialize_gd3d_topdown_module);

        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
        return init_obj.init();
    }
}