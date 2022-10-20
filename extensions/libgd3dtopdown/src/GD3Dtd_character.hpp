#ifdef WIN32
#include <windows.h>
#endif
#ifndef GD3DTD_CHARACTER
#define GD3DTD_CHARACTER

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/global_constants.hpp>

#include <godot_cpp/classes/character_body3d.hpp>

#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_mouse_motion.hpp>

#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/physics_server3d.hpp>
#include <godot_cpp/classes/physics_ray_query_parameters3d.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node.hpp>

#include <godot_cpp/classes/area3d.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/classes/box_shape3d.hpp>

#include <godot_cpp/classes/physics_body3d.hpp>

#include "GD3Dvisual_obstacle.hpp"
#include "GD3Dinterior_area.hpp"

using namespace godot;

class GD3Dtd_character : public CharacterBody3D {


    GDCLASS(GD3Dtd_character, CharacterBody3D);

    GD3Dtd_character();
    ~GD3Dtd_character();
protected:
    static void _bind_methods();

private:

    bool initialized;
    //Singletons
    Input* input;
    ProjectSettings* p_settings;
    PhysicsServer3D* ph_server;
    Ref<World3D> w3d;

    //Values
    float gravity = 9.8f;
    float mouse_sensitivity = 0.2f;
    float walk_speed = 5.0f;
    float sprint_speed = 10.0f;

    //Aiming and camera properties
    bool is_aiming;
    Vector3 lookat_position;
    NodePath camera_node_path;
    Camera3D* camera;
    Vector3 camera_boon = Vector3(0, 15, 10);
    float camera_predict = 1;
    float camera_predict_speed = 15;
    Vector3 camera_follow_position;
    bool invert_camera_movement;

    uint32_t aim_collision_mask;
    Node3D* old_aim_node;

    //Visual obstacles
    Area3D* interiors_collision_area;
    uint32_t interiors_collision_mask;

    uint32_t visual_collision_mask;
    TypedArray<RID>  visual_rayexcludes = {};
    Area3D* visual_collision_area;

public:

    virtual bool _is_initialized()  const;
    virtual bool _initialize();
    virtual void _uninitialize();

    virtual void _ready() override;
    virtual void _input(const Ref<InputEvent>& p_event) override;
    virtual void _physics_process(double delta) override;


#if defined(DEBUG_ENABLED)
    void _ready_handle();
    void _physics_process_handle(double delta);
    void _input_handle(const Ref<InputEvent>& p_event);
#endif

    //Other functions
    void handle_aim_node(Node3D* nd);

    //Signals
    void enter_visual_event(Variant body);
    void exit_visual_event(Variant body);

    void enter_interior_event(Variant area);
    void exit_interior_event(Variant area);


    //Getters and setters
#define GETTERSETTER_GD3D(VAR,TYPE) void GD3Dtd_character::set_##VAR##(const TYPE##& set);\
                                            TYPE GD3Dtd_character::get_##VAR##() const
    GETTERSETTER_GD3D(mouse_sensitivity, float);
    GETTERSETTER_GD3D(walk_speed, float);
    GETTERSETTER_GD3D(sprint_speed, float);
    GETTERSETTER_GD3D(camera_node_path, NodePath);
    GETTERSETTER_GD3D(invert_camera_movement, bool);
    GETTERSETTER_GD3D(camera_boon, Vector3);
    GETTERSETTER_GD3D(camera_predict, float);
    GETTERSETTER_GD3D(camera_predict_speed, float);
    GETTERSETTER_GD3D(interiors_collision_mask, uint32_t);
    GETTERSETTER_GD3D(aim_collision_mask, uint32_t);
#undef GETTERSETTER_GD3D

    uint32_t get_visual_collision_mask() const;
    void set_visual_collision_mask(uint32_t p_mask);

    Vector3 get_lookat_position() const;
    Node3D* get_aim_node()const;

};
#endif 